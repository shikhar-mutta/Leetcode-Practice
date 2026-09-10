#!/usr/bin/env python3
"""
ReporterAgent — the progress view over LC Tracker.xlsx.

Reads only; it never writes to the sheet. Four questions it answers, in the
order they matter for deciding what to practise next:

  * how far along am I, per thousand-block;
  * which topics are thin (few solved) versus over-practised;
  * which problems are flagged ⭐ and still waiting to be revisited;
  * where are the runs of unsolved problems worth attacking next.

Fully offline — no model, no network. `tracker_io.stats()` is one streaming
pass over the workbook (~0.8 s), and the agent makes exactly one call.
"""

from __future__ import annotations

import json
import re

from ..core import leetcode, paths, tracker_io, ui
from ..core.state import Context
from .base import Agent, AgentResult

THIN_BELOW = 8            # topics with fewer than this many solved are "thin"
THIN_FLOOR = 2            # ...but a label used only once is a typo, not a topic
GAP_MIN = 12              # only report unsolved runs at least this long
TOP_N = 10


class ReporterAgent(Agent):
    name = "reporter"
    role = "Summarise tracker progress: blocks, topics, ⭐ queue, unsolved runs"
    requires_llm = False

    def run(self, ctx: Context | None = None, *, limit: int = TOP_N, **_) -> AgentResult:
        try:
            s = tracker_io.stats()
        except tracker_io.MissingDependency as e:
            return self.fail(str(e))
        except FileNotFoundError:
            return self.fail(f"tracker not found at {paths.tracker_xlsx()}")
        except Exception as e:                              # noqa: BLE001
            return self.fail(f"could not read the tracker: {type(e).__name__}: {e}")

        solved: set[int] = s["solved"]
        starred = sorted(s["starred"])
        report = {
            "count": s["count"],
            "per_block": s["per_block"],
            "topics": s["topics"].most_common(),
            # Singletons are almost always one-off labels ("OUT", "pushAll->push
            # left") rather than categories, so they are not practice targets.
            "thin": [(k, n) for k, n in sorted(s["topics"].items(), key=lambda kv: kv[1])
                     if THIN_FLOOR <= n < THIN_BELOW][:limit],
            "starred": [(p, s["topic_of"].get(p, ""), _title(p)) for p in starred],
            "gaps": _gaps(solved, limit),
            "recent": _recent_scores(limit),
        }
        if ctx is not None:
            ctx.note(self.name, f"{s['count']} solved, {len(starred)} starred")
        return self.ok(f"{s['count']} solved, {len(starred)} flagged for revision",
                       **report)


_LINK = re.compile(r"leetcode\.com/problems/([a-z0-9-]+)")


def _title(pid: int) -> str:
    """
    A problem's title without touching the network.

    The cache only holds problems this system has fetched, so most ids fall
    through to the archive, where every solution carries a `// Link:` line.
    The slug in it reconstructs the title well enough to recognise the problem.
    """
    d = leetcode.cached_only(pid)
    if d and d.get("title"):
        return d["title"]
    for f in _archive_files(pid):
        try:
            head = f.read_text(encoding="utf-8", errors="replace")[:400]
        except OSError:
            continue
        m = _LINK.search(head)
        if m:
            return m.group(1).replace("-", " ").title()
    return ""


def _archive_files(pid: int) -> list:
    """
    Archive entries for one id.

    105 of them carry the user's own `*` revisit marker in the filename
    (`1009*.cpp`, `1157**ST.cpp`), so an exact `<id>.cpp` lookup misses them —
    but a bare `<id>*` glob would also catch `4480` when asked for `448`, so
    the digit boundary is checked explicitly.
    """
    try:
        found = list(paths.all_codes().glob(f"{pid}*.cpp"))
    except OSError:
        return []
    return [f for f in found if re.match(rf"^{pid}(?!\d)", f.name)]


def _gaps(solved: set[int], limit: int) -> list[tuple[int, int, int]]:
    """
    Longest runs of consecutive unsolved ids below the highest solved one.

    Bounded by the highest solved problem rather than by 4017: the empty
    stretch above whatever you have reached is not a gap in your practice,
    it is simply the part you have not got to yet.
    """
    if not solved:
        return []
    top = max(solved)
    runs, start = [], None
    for i in range(1, top + 1):
        if i in solved:
            if start is not None:
                runs.append((start, i - 1, i - start))
                start = None
        elif start is None:
            start = i
    if start is not None:
        runs.append((start, top, top - start + 1))
    runs = [r for r in runs if r[2] >= GAP_MIN]
    return sorted(runs, key=lambda r: -r[2])[:limit]


def _recent_scores(limit: int) -> list[tuple[str, float, str]]:
    """Most recently written score cards: (pid, total, grade)."""
    out = []
    try:
        files = sorted(paths.scores_dir().glob("*_score.json"),
                       key=lambda f: f.stat().st_mtime, reverse=True)
    except OSError:
        return out
    for f in files[:limit]:
        try:
            d = json.loads(f.read_text(encoding="utf-8"))
            out.append((str(d.get("pid", f.stem.split("_")[0])),
                        float(d.get("total", 0.0)), str(d.get("grade", "?"))))
        except (OSError, ValueError, TypeError):
            continue
    return out


# ── rendering ────────────────────────────────────────────────────────────────

def _bar(done: int, total: int, width: int = 24) -> str:
    filled = int(round(width * done / total)) if total else 0
    return "█" * filled + ui.dim("·" * (width - filled))


def render(data: dict) -> str:
    total = data["count"]
    out = [ui.banner("progress")]
    out.append(f"  {ui.bold(str(total))} problems solved\n")

    out.append("  " + ui.dim("BY BLOCK"))
    for label, n in data["per_block"].items():
        pct = f"{n / 10:.0f}%"
        out.append(f"   {label:<12} {_bar(n, 1000)} {n:>4} {ui.dim(pct):>3}")

    top = data["topics"][:TOP_N]
    if top:
        out.append("\n  " + ui.dim(f"STRONGEST TOPICS  (of {len(data['topics'])})"))
        widest = max(n for _, n in top)
        for name, n in top:
            out.append(f"   {name:<22} {_bar(n, widest, 18)} {n:>4}")

    if data["thin"]:
        out.append("\n  " + ui.dim(f"THIN TOPICS  (under {THIN_BELOW} solved — practise these)"))
        out.append("   " + ui.yellow(", ".join(f"{k} ({n})" for k, n in data["thin"])))

    if data["starred"]:
        out.append("\n  " + ui.dim(f"⭐ REVISION QUEUE  ({len(data['starred'])})"))
        for pid, topic, title in data["starred"]:
            bits = " ".join(x for x in (title, ui.dim(f"[{topic}]") if topic else "") if x)
            out.append(f"   {ui.bold(str(pid)):<6} {bits}")

    if data["gaps"]:
        out.append("\n  " + ui.dim(f"LARGEST UNSOLVED RUNS  (at least {GAP_MIN} in a row)"))
        for lo, hi, n in data["gaps"]:
            out.append(f"   {lo}–{hi}" + ui.dim(f"  ({n} problems)"))

    if data["recent"]:
        out.append("\n  " + ui.dim("RECENT SCORES"))
        for pid, score, grade in data["recent"]:
            colour = ui.green if score >= 85 else (ui.yellow if score >= 70 else ui.red)
            out.append(f"   {pid:<6} {colour(f'{score:>5.1f}')}  {colour(grade)}")

    return "\n".join(out) + "\n"
