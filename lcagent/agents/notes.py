#!/usr/bin/env python3
"""
NotesAgent — add what a problem actually taught you to your own notes files.

The bar for writing is deliberately high. `imp DS.txt`, `formula.txt` and
`algo_name.txt` are hand-curated: 50, 16 and 15 entries built up over ~935
solved problems, which is roughly one note per twenty problems. An agent that
appends something after every problem would bury the signal within a month, so
the model is told that NONE is the expected answer and the agent refuses on
duplicates before it ever writes.

Three safety rails, in order:
  1. the model may answer `none`, and is told most problems deserve that;
  2. `notes_io.duplicate()` blocks anything close to an existing entry;
  3. the file is copied to data/notes_backups/ before the write.
"""

from __future__ import annotations

from ..core import notes_io, ui
from ..core.state import Context
from ..providers import ProviderError, get_provider
from .base import Agent, AgentResult

MAX_CODE_CHARS = 3000
MAX_BODY_LINES = 22


class NotesAgent(Agent):
    name = "notes"
    role = "Append a genuinely new technique to your notes files, in their own format"
    requires_llm = True

    def run(self, ctx: Context, *, target: str | None = None,
            dry_run: bool = False, force: bool = False, **_) -> AgentResult:
        sol = ctx.paths.solution
        if not sol.is_file():
            return self.fail(f"{sol.name} does not exist — nothing to take notes from")
        code = sol.read_text(encoding="utf-8", errors="replace")
        if not code.strip():
            return self.fail(f"{sol.name} is empty")

        if target and target not in notes_io.TARGETS:
            return self.fail(f"unknown notes file {target!r} — "
                             f"pick one of: {', '.join(notes_io.TARGETS)}")

        provider = get_provider()
        usable, why = provider.available()
        if not usable:
            return self.fail(f"needs a model provider — {why}")

        try:
            pick = self._extract(ctx, code, provider, forced=target)
        except ProviderError as e:
            return self.fail(f"model call failed: {e}")

        if pick is None:
            return self.ok("nothing new worth noting — no file was touched",
                           target=None, wrote=False)

        key, title, body = pick
        t = notes_io.TARGETS[key]

        dup = notes_io.duplicate(t, title, ctx.pid)
        if dup and not force:
            return self.fail(
                f"already covered in {t.label} — {dup}",
                target=key, duplicate=dup, title=title, wrote=False)

        number = notes_io.next_number(t)
        preview = notes_io.render(t, number, title, body)
        if dry_run:
            return self.ok(f"would add entry {number} to {t.label} (dry run)",
                           target=key, title=title, number=number,
                           preview=preview, wrote=False)

        n, bak, added = notes_io.append(t, title, body)
        ctx.note(self.name, f"{t.label}: entry {n} — {title}")
        return self.ok(f"added entry {n} to {t.label}",
                       target=key, title=title, number=n, preview=added,
                       backup=str(bak), wrote=True,
                       artifacts=[t.path])

    # ── the model call ──
    def _extract(self, ctx: Context, code: str, provider,
                 forced: str | None) -> tuple[str, str, str] | None:
        problem = ctx.problem or {}
        statement = ""
        if ctx.paths.problem.is_file():
            statement = ctx.paths.problem.read_text(encoding="utf-8",
                                                    errors="replace")[:1000]

        choices = {forced: notes_io.TARGETS[forced]} if forced else notes_io.TARGETS
        menu = "\n".join(f"  {k} = {t.label}: {t.what}" for k, t in choices.items())
        existing = []
        for k, t in choices.items():
            titles = "; ".join(title for _, title in notes_io.entries(t))
            existing.append(f"Already in {t.label}: {titles}")

        system = (
            "You maintain a competitive programmer's personal notes files. "
            "You are extremely selective: these files hold one entry per ~20 "
            "problems solved. Standard techniques the programmer obviously "
            "already knows (two pointers, basic sorting, hash maps, plain "
            "binary search, simple DP) are NEVER worth an entry. Describe ONLY "
            "the technique the given solution actually uses — never an "
            "approach it rejected or does not contain. Reply in the exact "
            "format asked for, nothing else.")

        force_line = (
            "That is the only file available. If this solution has nothing "
            "worth adding to it, reply with exactly:\nNONE"
            if forced else
            "If the solution uses nothing that deserves a permanent note — "
            "which is the usual case — reply with exactly:\nNONE")

        prompt = f"""Problem {ctx.pid}: {problem.get('title', '')}

{statement}

Accepted C++ solution:
```cpp
{code[:MAX_CODE_CHARS]}
```

Notes files available:
{menu}

{chr(10).join(existing)}

Decide whether this solution taught a REUSABLE technique that is not already
in the list above. {force_line}

Otherwise reply in exactly this format:

FILE: <{'|'.join(choices)}>
TITLE: <one line, the same style as the existing titles, cite the problem as (LC {ctx.pid})>
BODY:
<the note: what it is, the syntax or formula, when to reach for it, and a
short C++ snippet. Plain text, no markdown fences, at most {MAX_BODY_LINES}
lines, wrapped at 70 columns. Write prose at column 0 and INDENT every line
of code by four spaces — the indent is what marks a line as code, and code is
never rewrapped. For the algo file omit BODY entirely — the title is the
whole entry.>"""

        out = provider.complete(system, prompt, tier="smart", max_tokens=2000).text
        return self._parse(out, forced, set(choices))

    @staticmethod
    def _parse(out: str, forced: str | None,
               allowed: set[str]) -> tuple[str, str, str] | None:
        text = (out or "").strip()
        if not text:
            raise ProviderError("model returned an empty response")
        # Models like to wrap the whole reply in a fence; strip it before parsing.
        if text.startswith("```"):
            text = "\n".join(text.split("\n")[1:])
            if text.rstrip().endswith("```"):
                text = text.rstrip()[:-3]

        lines = text.split("\n")
        if any(l.strip().upper() == "NONE" for l in lines[:3]):
            return None

        key, title, body = forced, "", []
        seen_body = False
        for line in lines:
            s = line.strip()
            up = s.upper()
            if not seen_body and up.startswith("FILE:"):
                cand = s.split(":", 1)[1].strip().lower().strip("<>` ")
                if cand in allowed:
                    key = cand
            elif not seen_body and up.startswith("TITLE:"):
                title = s.split(":", 1)[1].strip().strip("<>`")
            elif not seen_body and up.startswith("BODY:"):
                seen_body = True
                rest = s.split(":", 1)[1].strip()
                if rest:
                    body.append(rest)
            elif seen_body:
                body.append(line)

        if not key or not title:
            return None
        if key == "algo":
            return key, title, ""
        trimmed = "\n".join(body).strip("\n")
        while trimmed.count("\n") + 1 > MAX_BODY_LINES:
            trimmed = trimmed.rsplit("\n", 1)[0]
        if not trimmed.strip():
            return None
        return key, title, trimmed


def render(result: AgentResult) -> str:
    """Show the entry the way it will look in the file."""
    preview = result.data.get("preview", "")
    if not preview:
        return ""
    t = notes_io.TARGETS.get(result.data.get("target") or "")
    head = f"  {t.label}" if t else "  notes"
    body = "\n".join("  " + l if l else "" for l in preview.rstrip().split("\n"))
    return f"\n{ui.dim(head)}\n{body}\n"
