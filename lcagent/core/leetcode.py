#!/usr/bin/env python3
"""
LeetCode GraphQL access, with a persistent on-disk cache.

fetch_problem.py already queries LeetCode, but only for `content`,
`exampleTestcases` and `codeSnippets` — it never asks for difficulty, topic
tags or hints, all of which the problem file and the topic classifier want.
This module asks for the full set once and caches it, so re-rendering a
statement or re-classifying a topic costs no network at all.
"""

from __future__ import annotations

import json
import os
import time
import urllib.error
import urllib.request
from pathlib import Path

from . import paths

GRAPHQL = "https://leetcode.com/graphql"

#: Premium problems return an empty `content` and `codeSnippets` to anonymous
#: callers. If you hold a LeetCode Premium subscription, exporting your own
#: session cookie makes the API return the content you are entitled to:
#:     export LEETCODE_SESSION=<the LEETCODE_SESSION cookie from your browser>
#: Without it there is no way to obtain premium statements, and the fetcher
#: says so rather than looking elsewhere.
SESSION_ENV = "LEETCODE_SESSION"

HEADERS = {
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:120.0) Gecko/20100101 Firefox/120.0",
    "Referer": "https://leetcode.com",
    "Accept": "application/json",
}


class OfflineError(RuntimeError):
    """Raised when LeetCode is unreachable and no cache entry exists."""


def cache_dir() -> Path:
    """Delegates to the shared agent-data root."""
    return paths.cache_dir()


# ─── transport ───────────────────────────────────────────────────────────────

def post_json(query: str, variables: dict, *, tries: int = 4, timeout: float = 20.0) -> dict:
    """POST with backoff — LeetCode rate-limits bursts and occasionally 5xx's."""
    body = json.dumps({"query": query, "variables": variables}).encode()
    headers = dict(HEADERS)
    session = os.environ.get(SESSION_ENV, "").strip()
    if session:
        headers["Cookie"] = f"{SESSION_ENV}={session}"
    last: Exception | None = None
    for attempt in range(tries):
        try:
            req = urllib.request.Request(GRAPHQL, data=body, headers=headers)
            with urllib.request.urlopen(req, timeout=timeout) as resp:
                return json.loads(resp.read().decode("utf-8", "replace"))
        except (urllib.error.URLError, urllib.error.HTTPError, OSError, TimeoutError) as e:
            last = e
            if attempt < tries - 1:
                time.sleep(1.5 * (attempt + 1))
    raise OfflineError(f"LeetCode unreachable after {tries} tries: {last}")


# ─── queries ─────────────────────────────────────────────────────────────────

_Q_SLUG = """query ql($f: QuestionListFilterInput) {
  questionList(categorySlug: "" limit: 30 skip: 0 filters: $f) {
    data { questionFrontendId titleSlug title }
  }
}"""

_Q_DETAIL = """query qd($s: String!) {
  question(titleSlug: $s) {
    questionFrontendId title titleSlug difficulty
    content exampleTestcases hints
    topicTags { name }
    codeSnippets { langSlug code }
  }
}"""


def _resolve_slug(num: int | str) -> tuple[str, str]:
    """
    Number → (slug, title).

    Keyword search ranks loosely — "1" also matches "Number of 1 Bits" — so ask
    for a wide page and pick out the exact frontend id.
    """
    r = post_json(_Q_SLUG, {"f": {"searchKeywords": str(num)}})
    for q in r["data"]["questionList"]["data"]:
        if str(q["questionFrontendId"]) == str(num):
            return q["titleSlug"], q["title"]
    raise RuntimeError(f"Problem {num} not found on LeetCode (no entry with frontend id {num}).")


# ─── public API ──────────────────────────────────────────────────────────────

def fetch_question(num: int | str, *, refresh: bool = False, allow_cache: bool = True) -> dict:
    """
    Full metadata for one problem.

    Returns keys: id, title, slug, difficulty, tags, content (HTML),
    example_testcases, hints, cpp_snippet, locked.
    """
    cache_file = cache_dir() / f"{num}.json"
    if allow_cache and not refresh and cache_file.is_file():
        try:
            return _migrate(json.loads(cache_file.read_text(encoding="utf-8")))
        except (json.JSONDecodeError, OSError):
            pass  # corrupt entry, re-fetch

    slug, title = _resolve_slug(num)
    d = post_json(_Q_DETAIL, {"s": slug})["data"]["question"]
    if not d:
        raise RuntimeError(f"LeetCode returned no data for {slug}")

    cpp = next((s["code"] for s in (d.get("codeSnippets") or []) if s["langSlug"] == "cpp"), "")
    # Premium problems return metadata but no body: `content` and `codeSnippets`
    # come back empty (or null) for anyone without a subscription. Flag it here
    # so every downstream agent can say so plainly instead of guessing.
    locked = not (d.get("content") or "").strip() and not cpp
    out = {
        "locked": locked,
        "id": str(d.get("questionFrontendId") or num),
        "title": d.get("title") or title,
        "slug": slug,
        "difficulty": d.get("difficulty") or "",
        "tags": [t["name"] for t in (d.get("topicTags") or [])],
        "content": d.get("content") or "",
        "example_testcases": d.get("exampleTestcases") or "",
        "hints": d.get("hints") or [],
        "cpp_snippet": cpp,
    }
    try:
        cache_file.write_text(json.dumps(out, indent=1), encoding="utf-8")
    except OSError:
        pass  # cache is an optimisation, never a hard requirement
    return out


def cached_only(num: int | str) -> dict | None:
    """Cache lookup with no network attempt — used by the offline path."""
    f = cache_dir() / f"{num}.json"
    if f.is_file():
        try:
            return _migrate(json.loads(f.read_text(encoding="utf-8")))
        except (json.JSONDecodeError, OSError):
            return None
    return None


def _migrate(d: dict) -> dict:
    """
    Backfill fields added after an entry was cached.

    The cache outlives the code that wrote it, so an entry stored before a
    field existed would otherwise KeyError anything that reads it directly.
    """
    if "locked" not in d:
        d["locked"] = not (d.get("content") or "").strip() and not d.get("cpp_snippet")
    d.setdefault("hints", [])
    d.setdefault("tags", [])
    return d


def has_session() -> bool:
    """Whether a LeetCode session cookie is configured for premium access."""
    return bool(os.environ.get(SESSION_ENV, "").strip())


def problem_url(slug: str) -> str:
    return f"https://leetcode.com/problems/{slug}/description/"
