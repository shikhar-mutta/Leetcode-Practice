#!/usr/bin/env python3
"""
ArchiverAgent — copy a solved problem into the two archives.

  Code Dirs/All LC 1 - 4017/<id>/   the scaffold: solution, driver, input, expected,
                                    and the question file when there is one
  All Codes/All LC 1 - 4017/<id>.cpp  the flat solution corpus

`_debug.txt` is deliberately excluded — the archived folders never keep it,
checked against the existing entries. `_problem.txt` is kept, so a later `new`
can scaffold the problem with no network at all. Archiving is gated on passing tests: the
archive doubles as the scorer's reference corpus, so a broken solution in it
would poison future comparisons.
"""

from __future__ import annotations

import shutil

from ..core import paths
from ..core.state import Context
from .base import Agent, AgentResult


class ArchiverAgent(Agent):
    name = "archiver"
    role = "Copy the solved problem into Code Dirs/ and All Codes/"
    requires_llm = False

    def run(self, ctx: Context, *, require_pass: bool = True,
            overwrite: bool = False, **_) -> AgentResult:
        if require_pass and not (ctx.report and ctx.report.all_passed):
            return self.fail("tests are not passing — refusing to archive")

        pp = ctx.paths
        missing = [f.name for f in (pp.solution, pp.driver, pp.input, pp.expected)
                   if not f.is_file()]
        if missing:
            return self.fail("missing: " + ", ".join(missing))

        dest_dir = paths.code_dirs() / ctx.pid
        flat = paths.all_codes() / f"{ctx.pid}.cpp"
        has_dir, has_flat = dest_dir.is_dir(), flat.is_file()
        # A half-present archive is a gap to fill, not a reason to refuse: the
        # bulk import left entries with one side missing (Code Dirs/448 has no
        # All Codes/448.cpp, and problem 4 was the reverse).
        complete = has_dir and has_flat
        if complete and not overwrite:
            return self.fail(f"{ctx.pid} is already archived — `finish --overwrite` to replace")
        partial = (has_dir or has_flat) and not complete

        copied = []
        try:
            dest_dir.mkdir(parents=True, exist_ok=True)
            for f in (pp.solution, pp.driver, pp.input, pp.expected, pp.problem):
                if f is pp.problem and not f.is_file():
                    continue                            # optional; never _debug.txt
                shutil.copy2(f, dest_dir / f.name)
                copied.append(f.name)
            flat.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(pp.solution, flat)
            copied.append(f"All Codes/{flat.name}")
        except OSError as e:
            return self.fail(f"copy failed: {e}")

        ctx.note(self.name, f"archived {ctx.pid} ({len(copied)} files)")
        verb = "replaced" if complete else ("completed" if partial else "archived")
        return self.ok(f"{verb} {ctx.pid} — {len(copied)} files into Code Dirs/ and All Codes/",
                       files=copied, replaced=complete, completed_partial=partial)
