#!/usr/bin/env python3
"""
FetcherAgent — get a problem's scaffold onto the repo root.

The local archive under `Code Dirs/All LC 1 - 4017/<id>/` comes first: it needs
no network, and its drivers and expected files carry hand repairs that a fresh
fetch would regenerate broken. Its `<id>.cpp` is the finished solution, though,
so that file is never copied — core/stub.py rebuilds it as the empty stub a
fresh fetch would give, and a re-fetch is a re-solve.

LeetCode is the fallback, for problems the archive does not have. That path
delegates to the existing fetch_problem.py rather than reimplementing its
snippet parsing and driver generation, invoked through sys.executable so the
right interpreter is used on Windows, where `python3` is frequently not on PATH.
"""

from __future__ import annotations

import re
import shutil
import subprocess
import sys

from ..core import paths, stub
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

        Order: the local archive, then LeetCode. `allow_archive=False` (`new
        <id> --live`) goes straight to LeetCode; `offline` never leaves the
        archive.

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

        if allow_archive:
            r = self._from_archive(ctx)
            if r.ok:
                if replace_previous:
                    r.data.update(self._replace_previous(ctx))
                return r
            reasons.append(f"archive: {r.message}")
            self._rollback(snapshot)

        if not offline:
            r = self._fetch_online(ctx)
            if r.ok:
                if reasons:
                    r.message += f"   [{'; '.join(reasons)}]"
                if replace_previous:
                    r.data.update(self._replace_previous(ctx))
                return r
            reasons.append(f"LeetCode: {r.message}")
        else:
            reasons.append("offline mode — LeetCode not tried")

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
            if (solution.is_file() and not self._is_archived(solution, archived)
                    and not self._is_blank(solution, root / f"{pid}_driver.cpp")):
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

    @staticmethod
    def _is_blank(solution, driver) -> bool:
        """
        True when the solution is still the untouched empty stub.

        Re-solving archived problems makes this the common case, and rescuing
        an empty stub would overwrite a real rescued copy of the same id.
        """
        try:
            drv = driver.read_text(encoding="utf-8", errors="replace") if driver.is_file() else ""
            return stub.is_untouched(solution.read_text(encoding="utf-8", errors="replace"), drv)
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
        """
        The archived driver, tests and question file as they are, and an empty
        stub in place of the archived (solved) `<id>.cpp`.
        """
        pp, src = ctx.paths, ctx.paths.archive_dir
        if not src.is_dir():
            return self.fail(f"no archive copy at {src.name}/")
        copies = [(src / f.name, f) for f in (pp.driver, pp.input, pp.expected)]
        empty = [s.name for s, _ in copies if not s.is_file() or s.stat().st_size == 0]
        if empty:
            return self.fail(f"archive copy is incomplete (missing or empty: {', '.join(empty)})")

        solved = src / pp.solution.name
        try:
            driver = copies[0][0].read_text(encoding="utf-8", errors="replace")
            text = stub.make_stub(solved.read_text(encoding="utf-8", errors="replace"), driver) \
                if solved.is_file() else None
        except OSError as e:
            return self.fail(f"could not read the archive: {e}")
        if text is None:
            return self.fail(f"could not build an empty stub from the archived {solved.name}")

        statement = src / pp.problem.name
        if statement.is_file():
            copies.append((statement, pp.problem))
        try:
            pp.solution.write_text(text, encoding="utf-8")
            for s, d in copies:
                shutil.copy2(s, d)
            pp.debug.write_text(_first_case(pp.input.read_text(encoding="utf-8", errors="replace")),
                                encoding="utf-8")
        except OSError as e:
            return self.fail(f"copy failed: {e}")

        ctx.note(self.name, f"scaffolded {ctx.pid} from the local archive")
        return self.ok(f"scaffolded {ctx.pid} from the local archive — empty {pp.solution.name}, "
                       f"archived driver and tests",
                       todos=self.count_todos(ctx), from_archive=True,
                       statement=statement.is_file(),
                       artifacts=[pp.solution, pp.driver, pp.input, pp.expected])

    # ── inspection ──
    @staticmethod
    def count_todos(ctx: Context) -> int:
        """Unfilled `// TODO: parse ...` scaffolding in the generated driver."""
        if not ctx.paths.driver.is_file():
            return 0
        text = ctx.paths.driver.read_text(encoding="utf-8", errors="replace")
        return len(TODO_RE.findall(text))


def _first_case(input_text: str) -> str:
    """
    `_debug.txt` for debug.sh: the first test case of `_input.txt`, the way
    fetch_problem.py writes it. The archive never keeps one. When the cases do
    not split evenly the whole input is used — it still runs.
    """
    lines = [ln for ln in input_text.splitlines() if ln.strip()]
    try:
        count = int(lines[0].strip())
    except (IndexError, ValueError):
        return input_text
    rest = lines[1:]
    if count <= 0 or not rest or len(rest) % count:
        return input_text
    return "1\n" + "\n".join(rest[:len(rest) // count]) + "\n"
