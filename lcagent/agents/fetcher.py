#!/usr/bin/env python3
"""
FetcherAgent — get a problem's scaffold onto the repo root.

Delegates to the existing fetch_problem.py rather than reimplementing its
snippet parsing and driver generation, which are the hard-won parts. It is
invoked through sys.executable so the right interpreter is used on Windows,
where `python3` frequently is not on PATH.

When LeetCode is unreachable the pre-fetched archive under
`Code Dirs/All LC 1 - 4017/<id>/` is used instead — 3356 problems already have
their driver, input and expected files sitting there, which makes the whole
system usable with no network at all.
"""

from __future__ import annotations

import re
import shutil
import subprocess
import sys

from ..core import paths
from ..core.paths import all_codes
from ..core.state import Context
from .base import Agent, AgentResult

TODO_RE = re.compile(r"//\s*TODO", re.I)

#: Root files that belong to a problem: 2859.cpp, 2859_driver.cpp, 2859_input.txt …
#: Anchored so it can never match run.sh, lc.bat, fetch_problem.py and the like.
PROBLEM_FILE_RE = re.compile(r"^(\d+)(?:_[A-Za-z0-9_]+)?\.(?:cpp|txt)$")


class FetcherAgent(Agent):
    name = "fetcher"
    role = "Fetch a problem and scaffold its solution stub, driver and test files"
    requires_llm = False

    def run(self, ctx: Context, *, offline: bool = False, force: bool = False,
            allow_archive: bool = True, replace_previous: bool = True,
            **_) -> AgentResult:
        """
        Scaffold a problem, or change nothing at all.

        The guarantee this method makes: if the problem cannot be fetched, every
        file at the repo root is left exactly as it was. fetch_problem.py writes
        directly into the working tree and can die part-way through (a premium
        problem kills it after some files exist), so the existing files are
        snapshotted first and rolled back on any failure.
        """
        pp = ctx.paths
        existing = [f for f in self._owned(ctx) if f.is_file()]

        if existing and not force:
            return self.ok(f"{pp.pid} already scaffolded at repo root "
                           f"({len(existing)} files) — `new {pp.pid} --force` to refetch",
                           todos=self.count_todos(ctx), reused=True)

        snapshot = self._snapshot(ctx)
        reasons: list[str] = []

        if not offline:
            r = self._fetch_online(ctx)
            if r.ok:
                if replace_previous:
                    r.data.update(self._replace_previous(ctx))
                return r
            reasons.append(f"LeetCode: {r.message}")
            restored, kept = self._rollback(snapshot)
            if restored:
                ctx.note(self.name, f"restored {len(restored)} pre-existing file(s)")
        else:
            reasons.append("offline mode requested")

        # The archive is a safe fallback only when it cannot destroy anything.
        # Overwriting a solution the user is part-way through is worse than
        # failing, so it is skipped unless the slot is empty or force is given.
        if allow_archive and (force or not existing):
            r = self._from_archive(ctx)
            if r.ok:
                r.message += f"   [{'; '.join(reasons)}]"
                if replace_previous:
                    r.data.update(self._replace_previous(ctx))
                return r
            reasons.append(f"archive: {r.message}")
        elif existing:
            reasons.append("archive fallback skipped — refusing to overwrite the "
                           "existing files at root")

        restored, kept = self._rollback(snapshot)
        return self.fail(f"could not fetch problem {pp.pid}",
                         reasons=reasons, restored=restored, kept=kept)

    # ── keeping the root to one problem ──
    def _replace_previous(self, ctx: Context) -> dict:
        """
        Clear the previously-fetched problem out of the repo root.

        This mirrors what rename.sh does — the root holds one problem at a time
        — but rename.sh moves the old files onto the new number where
        fetch_problem.py then overwrites them, so an unarchived solution is
        simply gone. Anything not already in `All Codes/` is copied to
        `data/replaced/` first; the workflow stays the same, the work does not
        disappear.
        """
        root = ctx.paths.root
        victims: dict[str, list] = {}
        for f in root.iterdir():
            if not f.is_file():
                continue
            m = PROBLEM_FILE_RE.match(f.name)
            if m and m.group(1) != ctx.pid:
                victims.setdefault(m.group(1), []).append(f)
        if not victims:
            return {}

        replaced, rescued = [], []
        for pid, files in victims.items():
            solution = root / f"{pid}.cpp"
            archived = (all_codes() / f"{pid}.cpp")
            if solution.is_file() and not self._is_archived(solution, archived):
                backup_dir = paths.agent_data_dir() / "replaced"
                backup_dir.mkdir(parents=True, exist_ok=True)
                try:
                    shutil.copy2(solution, backup_dir / f"{pid}.cpp")
                    rescued.append(pid)
                except OSError:
                    continue          # could not save it, so do not remove it
            for f in files:
                try:
                    f.unlink()
                except OSError:
                    pass
            replaced.append(pid)

        ctx.note(self.name, f"cleared previous problem(s): {', '.join(replaced)}")
        return {"replaced": replaced, "rescued": rescued}

    @staticmethod
    def _is_archived(solution, archived) -> bool:
        """True when the archive already holds this exact solution."""
        if not archived.is_file():
            return False
        try:
            return solution.read_bytes() == archived.read_bytes()
        except OSError:
            return False

    # ── transactional protection ──
    def _owned(self, ctx: Context) -> list:
        """Every root file this agent is allowed to create or replace."""
        pp = ctx.paths
        return [pp.solution, pp.driver, pp.input, pp.expected, pp.debug, pp.problem]

    def _snapshot(self, ctx: Context) -> dict:
        """Contents of each owned file, or None where the file does not exist."""
        return {f: (f.read_bytes() if f.is_file() else None) for f in self._owned(ctx)}

    def _rollback(self, snapshot: dict) -> tuple[list[str], list[str]]:
        """
        Restore pre-existing files; never delete anything.

        Two different things can be sitting on disk after a failed fetch, and
        they are treated differently:

          * a file that existed beforehand — restored byte-for-byte, because
            it may be a solution in progress and the attempt may have
            truncated or overwritten it;
          * a file the attempt created — left exactly where it is. A partial
            scaffold is evidence about what went wrong and may be usable, so
            it is never thrown away silently.

        Returns (restored, kept).
        """
        restored, kept = [], []
        for f, data in snapshot.items():
            try:
                if data is None:
                    if f.is_file():             # produced by the failed attempt
                        kept.append(f.name)
                elif not f.is_file() or f.read_bytes() != data:
                    f.write_bytes(data)         # truncated or overwritten
                    restored.append(f.name)
            except OSError:
                pass
        return restored, kept

    # ── sources ──
    def _fetch_online(self, ctx: Context) -> AgentResult:
        script = paths.repo_root() / "fetch_problem.py"
        if not script.is_file():
            return self.fail("fetch_problem.py not found")
        try:
            proc = subprocess.run(
                [sys.executable, str(script), str(ctx.pid)],
                capture_output=True, text=True, errors="replace", timeout=120,
            )
        except subprocess.TimeoutExpired:
            return self.fail("fetch_problem.py timed out")
        if proc.returncode != 0:
            # A premium problem is the common cause and the crash message for it
            # ("TypeError: 'NoneType' object is not iterable") explains nothing.
            from ..core import leetcode
            try:
                meta = leetcode.fetch_question(ctx.pid)
            except Exception:                                   # noqa: BLE001
                meta = None
            if meta and meta.get("locked"):
                extra = ("" if leetcode.has_session() else
                         "  Set LEETCODE_SESSION to your own cookie if you hold a "
                         "Premium subscription.")
                return self.fail(f"{ctx.pid} ({meta['title']}) is a LeetCode Premium "
                                 f"problem — the API served an empty statement and "
                                 f"code snippet." + extra)
            tail = (proc.stdout + proc.stderr).strip().splitlines()
            return self.fail(tail[-1] if tail else f"fetch_problem.py exited {proc.returncode}")

        todos = self.count_todos(ctx)
        warns = [l.strip() for l in proc.stdout.splitlines() if l.startswith("WARNING")]
        ctx.note(self.name, f"scaffolded {ctx.pid} from LeetCode")
        return self.ok(f"scaffolded {ctx.pid} from LeetCode", todos=todos, warnings=warns,
                       artifacts=[pp for pp in (ctx.paths.solution, ctx.paths.driver,
                                                ctx.paths.input, ctx.paths.expected)])

    def _from_archive(self, ctx: Context) -> AgentResult:
        src = ctx.paths.archive_dir
        if not src.is_dir():
            return self.fail(f"no archive copy at {src.name}/")
        copied = []
        for name in (f"{ctx.pid}.cpp", f"{ctx.pid}_driver.cpp",
                     f"{ctx.pid}_input.txt", f"{ctx.pid}_expected.txt"):
            s = src / name
            if s.is_file():
                shutil.copy2(s, paths.repo_root() / name)
                copied.append(name)
        if not copied:
            return self.fail(f"archive folder {src.name}/ is empty")
        ctx.note(self.name, f"restored {ctx.pid} from archive")
        return self.ok(f"restored {ctx.pid} from archive ({len(copied)} files)",
                       todos=self.count_todos(ctx), from_archive=True)

    # ── inspection ──
    @staticmethod
    def count_todos(ctx: Context) -> int:
        """Unfilled `// TODO: parse ...` scaffolding in the generated driver."""
        if not ctx.paths.driver.is_file():
            return 0
        text = ctx.paths.driver.read_text(encoding="utf-8", errors="replace")
        return len(TODO_RE.findall(text))
