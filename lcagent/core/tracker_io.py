#!/usr/bin/env python3
"""
Reading and writing LC Tracker.xlsx.

The sheet is five side-by-side blocks of 1000 problems each:

      A  B  C  D  |  E  F  G  H  |  I  J  K  L  |  M  N  O  P  |  Q  R  S  T
      0 - 999     |  1000-1999   |  2000-2999   |  3000-3999   |  4000+

Within a block the four columns are: number, mark, mark, topic. The number
column is a text label in block 1 (`'0004'`), a formula in blocks 2-4
(`'=A5 +1000'`) and a plain integer in block 5 — it is never written to.

Row is `id % 1000 + 1`. Verified against 2859 (row 860, block I-L) and
4 (row 5, block A-D).
"""

from __future__ import annotations

import shutil
import sys
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path

from . import paths

class MissingDependency(RuntimeError):
    """openpyxl is absent — every tracker feature is unavailable, nothing else is."""


BLOCK_STARTS = (1, 5, 9, 13, 17)      # A, E, I, M, Q
DONE = "✅"
STAR = "⭐"


@dataclass
class Row:
    pid: int
    row: int
    col: int          # first column of the block
    mark_a: str | None
    mark_b: str | None
    topic: str | None

    @property
    def solved(self) -> bool:
        return self.mark_a in (DONE, STAR) or self.mark_b in (DONE, STAR)


def locate(pid: int | str) -> tuple[int, int]:
    """(row, block start column) for a problem id."""
    n = int(pid)
    block = n // 1000
    if block >= len(BLOCK_STARTS):
        raise ValueError(f"problem {n} is beyond the sheet's {len(BLOCK_STARTS) * 1000} rows")
    return (n % 1000) + 1, BLOCK_STARTS[block]


def _open(read_only: bool = False):
    """
    Load the workbook.

    read_only mode is deliberately NOT used for random cell access: those
    worksheets stream rows, so `ws.cell(r, c)` rescans from the top every call
    and a few hundred lookups take minutes. The file is ~57 KB, so a normal
    load is cheap; the full scan below uses a single iter_rows pass instead.
    """
    try:
        import openpyxl
    except ModuleNotFoundError as e:      # the one third-party dependency
        raise MissingDependency(
            "reading LC Tracker.xlsx needs the `openpyxl` package.\n"
            f"      install it with:  {sys.executable} -m pip install openpyxl\n"
            "      everything else in lcagent works without it."
        ) from e
    return openpyxl.load_workbook(paths.tracker_xlsx(), read_only=read_only)


def read(pid: int | str) -> Row:
    n = int(pid)
    r, c = locate(n)
    wb = _open()
    try:
        ws = wb["Sheet1"]
        vals = [ws.cell(r, c + i).value for i in range(4)]
    finally:
        wb.close()
    return Row(n, r, c, vals[1], vals[2], vals[3])


def backup() -> Path:
    """Copy the tracker aside before any write. Never skipped."""
    d = paths.agent_data_dir() / "tracker_backups"
    d.mkdir(parents=True, exist_ok=True)
    target = d / f"LC Tracker {datetime.now():%Y-%m-%d_%H%M%S}.xlsx"
    shutil.copy2(paths.tracker_xlsx(), target)
    return target


def mark(pid: int | str, topic: str | None = None, *,
         overwrite_topic: bool = False) -> tuple[Row, Row, Path]:
    """
    Mark a problem solved and set its topic.

    Both mark columns get ✅, mirroring the sheet's own convention — they are
    identical in all but 6 of ~936 filled rows. An existing ⭐ is left alone:
    it is the user's own annotation and carries meaning this system does not
    know. An existing topic is likewise kept unless overwrite_topic is set.

    Returns (before, after, backup path).
    """
    n = int(pid)
    r, c = locate(n)
    before = read(n)
    bak = backup()

    wb = _open()
    try:
        ws = wb["Sheet1"]
        for i in (1, 2):
            if ws.cell(r, c + i).value != STAR:      # never clobber a star
                ws.cell(r, c + i).value = DONE
        if topic and (overwrite_topic or not before.topic):
            ws.cell(r, c + 3).value = topic
        wb.save(paths.tracker_xlsx())
    finally:
        wb.close()

    return before, read(n), bak


def stats() -> dict:
    """Solved counts and topic distribution — used by the reporting agent."""
    import collections
    wb = _open(read_only=True)
    try:
        ws = wb["Sheet1"]
        solved, starred, topics = set(), set(), collections.Counter()
        topic_of: dict[int, str] = {}
        per_block = {f"{b*1000}-{b*1000+999}": 0 for b in range(len(BLOCK_STARTS))}
        # One streaming pass: read_only worksheets are fast this way and slow
        # under random access.
        for r, row in enumerate(ws.iter_rows(values_only=True), start=1):
            for bi, c in enumerate(BLOCK_STARTS):
                i = c - 1                       # iter_rows is 0-indexed
                if i + 3 >= len(row):
                    continue
                pid = bi * 1000 + (r - 1)
                if pid == 0:
                    # Row 1 of block A is labelled '0000' and carries marks, but
                    # LeetCode numbering starts at 1 — counting it would report
                    # one solved problem that does not exist.
                    continue
                marks = (row[i + 1], row[i + 2])
                if any(m in (DONE, STAR) for m in marks):
                    solved.add(pid)
                    per_block[f"{bi*1000}-{bi*1000+999}"] += 1
                    # ⭐ is the user's own "come back to this" flag — it means
                    # solved AND worth revisiting, so it is tracked apart from
                    # the solved set rather than folded into it.
                    if STAR in marks:
                        starred.add(pid)
                t = row[i + 3]
                if t and isinstance(t, str):
                    topics[t.strip()] += 1
                    topic_of[pid] = t.strip()
    finally:
        wb.close()
    return {"solved": solved, "starred": starred, "count": len(solved),
            "topics": topics, "topic_of": topic_of, "per_block": per_block}


def vocabulary(minimum: int = 2) -> list[str]:
    """Topics already used at least `minimum` times — the classifier's menu."""
    t = stats()["topics"]
    return [k for k, n in t.most_common() if n >= minimum]
