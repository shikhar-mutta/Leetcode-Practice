#!/usr/bin/env python3
"""
MasterAgent — the loop you actually talk to.

Owns one Context at a time, keeps it on disk so a restart resumes on the same
problem, and dispatches to the specialists. Two modes:

  * REPL   — `python -m lcagent`, runs until you type `quit` or hit Ctrl-D.
  * watch  — polls the solution file and re-verifies on every save, until
             Ctrl-C drops you back to the prompt.

Polling is used rather than the `watchdog` package so the system stays on the
standard library: no pip install, nothing to fail differently across the two
operating systems.
"""

from __future__ import annotations

import json
import os
import sys
import time
from pathlib import Path

from ..core import codetype, notes_io, paths, ui
from ..core.state import Context
from ..core.testcase import Status
from .base import Agent, AgentResult
from .fetcher import FetcherAgent
from .archiver import ArchiverAgent
from .classifier import ClassifierAgent
from .committer import CommitterAgent
from .debugger import DebuggerAgent
from .driver_repair import DriverRepairAgent
from .improve import ImproverAgent
from .notes import NotesAgent
from .notes import render as render_note
from .reporter import ReporterAgent
from .reporter import render as render_progress
from .solver import SolverAgent
from .tracker import TrackerAgent
from .scorer import ScorerAgent
from .scorer import render as render_score
from .statement import StatementAgent
from .verifier import VerifierAgent

POLL_SECONDS = 0.4
DEBOUNCE_SECONDS = 0.6


class MasterAgent(Agent):
    name = "master"
    role = "Own the session loop and dispatch work to the specialist agents"
    requires_llm = False

    def __init__(self) -> None:
        self.ctx: Context | None = None
        self.fetcher = FetcherAgent()
        self.statement = StatementAgent()
        self.verifier = VerifierAgent()
        self.scorer = ScorerAgent()
        self.improver = ImproverAgent()
        self.repairer = DriverRepairAgent()
        self.solver = SolverAgent()
        self.debugger = DebuggerAgent()
        self.classifier = ClassifierAgent()
        self.archiver = ArchiverAgent()
        self.tracker = TrackerAgent()
        self.committer = CommitterAgent()
        self.notes = NotesAgent()
        self.reporter = ReporterAgent()
        self.running = True

    # ── the Agent contract, for uniformity ──
    def run(self, ctx: Context, **kwargs) -> AgentResult:
        self.ctx = ctx
        self.loop()
        return self.ok("session ended")

    # ── session persistence ──
    def _save(self) -> None:
        if not self.ctx:
            return
        try:
            paths.session_file().write_text(
                json.dumps({"pid": self.ctx.pid, "saved": time.time()}), encoding="utf-8")
        except OSError:
            pass

    def _restore(self) -> None:
        f = paths.session_file()
        if not f.is_file():
            return
        try:
            pid = json.loads(f.read_text(encoding="utf-8")).get("pid")
        except (json.JSONDecodeError, OSError):
            return
        if not pid:
            return
        candidate = Context.for_problem(pid)
        # Only resume onto a problem that still has something on disk; a stale
        # id left by a failed fetch should not become the session.
        if candidate.paths.solution.is_file() or candidate.paths.problem.is_file():
            self.ctx = candidate

    # ── entry points ──
    def loop(self) -> None:
        """The REPL. Runs until `quit`, Ctrl-D, or `stop`."""
        try:  # arrow-key history where the platform provides it
            import readline  # noqa: F401
        except ImportError:
            pass

        if self.ctx is None:
            self._restore()
        self._greet()
        print(self._render_menu())

        while self.running:
            try:
                line = input(self._prompt()).strip()
            except EOFError:
                print()
                break
            except KeyboardInterrupt:
                print("\n" + ui.info("0 or `quit` to exit"))
                continue
            if not line:                      # bare Enter redisplays the menu
                print(self._render_menu())
                continue
            try:
                self.dispatch(line)
            except Exception as e:  # noqa: BLE001 — a bad command must not kill the session
                print(ui.bad(f"{type(e).__name__}: {e}"))
            if self.running:
                print(self._render_menu())
        self._save()
        print(ui.dim("session saved. bye."))

    def one_shot(self, argv: list[str]) -> int:
        """`python -m lcagent run 2859` — same commands, no loop."""
        self._restore()
        try:
            self.dispatch(" ".join(argv))
        except Exception as e:  # noqa: BLE001
            print(ui.bad(f"{type(e).__name__}: {e}"))
            return 1
        self._save()
        if self.ctx and self.ctx.report:
            return 0 if self.ctx.report.all_passed else 1
        return 0

    # ── dispatch ──
    def dispatch(self, line: str) -> None:
        parts = line.split()
        cmd, args = parts[0].lower(), parts[1:]
        cmd = NUMBERS.get(cmd, cmd)          # menu number -> command
        handler = _ALIASES.get(cmd)
        if handler is None:
            print(ui.bad(f"unknown command {cmd!r} — pick a menu option, "
                         f"press Enter for the menu, or type `help`"))
            return
        getattr(self, handler)(args)

    # ── commands ──
    def cmd_new(self, args: list[str]) -> None:
        if not args:
            try:                                  # `2859 --live` works at the prompt too
                args = input(ui.cyan("  problem id > ")).split()
            except (EOFError, KeyboardInterrupt):
                print()
                return
        if not args or not args[0]:
            print(ui.warn("usage: new <problem id>"))
            return
        pid = args[0]
        if not pid.isdigit():
            print(ui.warn(f"{pid!r} is not a problem number"))
            return
        previous = self.ctx
        self.ctx = Context.for_problem(pid)
        offline = "--offline" in args

        print(ui.info(f"fetching {pid} ..."))
        live_only = "--live" in args or "--no-archive" in args
        r = self.fetcher.run(self.ctx, offline=offline, force="--force" in args,
                             allow_archive=not live_only)
        if not r.ok:
            print(ui.bad(r.message))
            for why in r.data.get("reasons", []):
                print(ui.dim(f"      · {why}"))
            restored, kept = r.data.get("restored", []), r.data.get("kept", [])
            if restored:
                print(ui.info(f"restored unchanged: {', '.join(restored)}"))
            if kept:
                print(ui.warn(f"partial files kept for inspection: {', '.join(kept)}"))
            if not restored and not kept:
                print(ui.info("nothing on disk was modified"))
            else:
                print(ui.info("none of your existing work was modified or deleted"))
            self.ctx = previous          # never strand the session on a problem that failed
            return
        print(ui.ok(r.message))
        for pid in r.data.get("replaced", []):
            print(ui.info(f"cleared previous problem {pid} from the root"))
        for pid in r.data.get("rescued", []):
            print(ui.warn(f"{pid}.cpp was not in the archive — a copy was saved to "
                          f"lcagent/data/replaced/{pid}.cpp"))
        if r.data.get("todos"):
            print(ui.warn(f"{r.data['todos']} unfilled TODO(s) in the driver "
                          f"— `repair` (menu 3) fills them"))
        for w in r.data.get("warnings", []):
            print(ui.warn(w))

        if r.data.get("statement"):              # the archive had the question: no network
            print(ui.ok(f"question: {self.ctx.paths.problem.name} (from the local archive)"))
        else:
            s = self.statement.run(self.ctx)
            print(ui.ok(s.message) if s.ok else ui.warn(s.message))
            if s.ok:
                print(ui.info(f"statement: {s.artifacts[0].relative_to(paths.repo_root())}"))
        ct = codetype.for_problem(self.ctx)
        if ct:
            print(ui.info(f"type: {ct.label}"))
        print(ui.info(f"edit {self.ctx.paths.solution.name}, then `run` (or `watch`)"))
        self._save()

    def cmd_statements(self, args: list[str]) -> None:
        """Write <id>_problem.txt into every archived problem folder."""
        from .statement import backfill_archive
        pids = [a for a in args if a.isdigit()] or None
        print(ui.info("writing question files into Code Dirs/ — Ctrl-C stops, "
                      "running it again resumes"))
        try:
            r = backfill_archive(pids, refresh="--refresh" in args, offline="--offline" in args,
                                 log=lambda m: print(ui.dim(f"     {m}")))
        except KeyboardInterrupt:
            print("\n" + ui.info("stopped — run `statements` again to resume"))
            return
        print(ui.ok(f"{r['written']} written, {r['skipped']} already there, "
                    f"{len(r['failures'])} failed"))
        for pid, why in r["failures"][:15]:
            print(ui.dim(f"      · {pid}: {why}"))

    def cmd_run(self, args: list[str]) -> None:
        if not self._need_ctx(args):
            return
        r = self.verifier.run(self.ctx)
        self._print_report()
        if r.ok:
            print()
            self.cmd_score([])

    def cmd_score(self, args: list[str]) -> None:
        if not self._need_ctx(args):
            return
        if self.ctx.report is None:
            print(ui.info("running tests first ..."))
            self.verifier.run(self.ctx)
            self._print_report()
            print()
        r = self.scorer.run(self.ctx)
        if not r.ok:
            print(ui.bad(r.message))
            return
        print(render_score(self.ctx.score))

    def cmd_better(self, args: list[str]) -> None:
        """Write the better solution the scorer identified, and verify it."""
        if not self._need_ctx(args):
            return
        if not (self.ctx.score or {}).get("better"):
            if self.ctx.score is None:
                print(ui.info("scoring first ..."))
                if self.ctx.report is None:
                    self.verifier.run(self.ctx)
                self.scorer.run(self.ctx)
            if not (self.ctx.score or {}).get("better"):
                print(ui.green("no better approach was found — nothing to write"))
                return

        b = self.ctx.score["better"]
        print(ui.info(f"writing the {b.get('approach')} solution ..."))
        r = self.improver.run(self.ctx)
        if not r.ok:
            print(ui.bad(r.message))
            return

        installed = r.data.get("installed")
        print(ui.ok(r.message) if installed or r.data.get("passed") else ui.warn(r.message))
        if installed:
            print(ui.info(f"your previous solution was saved to "
                          f"lcagent/data/replaced/{self.ctx.pid}_before_improve.cpp"))
            print(ui.warn("if this file is open in your editor, reload it before typing — "
                          "a stale buffer will overwrite what was just written"))
        else:
            print(ui.info(f"kept in lcagent/data/improved/{self.ctx.pid}_better.cpp; "
                          f"{self.ctx.paths.solution.name} was not modified"))
        print()
        print(ui.rule())
        print(r.artifacts[0].read_text(encoding="utf-8"))
        print(ui.rule())
        if installed:
            print(ui.green(f"verified {r.data['passed']}/{r.data['total']} on the same "
                           f"tests, then written to {self.ctx.paths.solution.name}"))

    def cmd_repair(self, args: list[str]) -> None:
        if not self._need_ctx(args):
            return
        n = FetcherAgent.count_todos(self.ctx)
        print(ui.info(f"repairing {self.ctx.paths.driver.name}"
                      f" ({n} TODO{'s' if n != 1 else ''}) ..."))
        r = self.repairer.run(self.ctx, force="--force" in args)
        print(ui.ok(r.message) if r.ok else ui.bad(r.message))
        if r.ok and r.data.get("changed"):
            print(ui.info("driver changed — re-running the tests"))
            self.verifier.run(self.ctx)
            self._print_report()

    def cmd_solve(self, args: list[str]) -> None:
        if not self._need_ctx(args):
            return
        print(ui.info("writing a solution ..."))
        r = self.solver.run(self.ctx, force="--force" in args)
        if not r.ok:
            print(ui.bad(r.message))
            return
        print(ui.ok(r.message))
        if r.data.get("backup"):
            print(ui.info(f"previous solution saved to "
                          f"lcagent/data/replaced/{self.ctx.pid}_before_solve.cpp"))
        print(ui.warn("reload the file in your editor before typing"))
        print()
        print(ui.rule())
        print(self.ctx.paths.solution.read_text(encoding="utf-8"))
        print(ui.rule())

    def cmd_fix(self, args: list[str]) -> None:
        if not self._need_ctx(args):
            return
        if self.ctx.report is None:
            print(ui.info("running the tests first ..."))
            self.verifier.run(self.ctx)
            self._print_report()
            print()
        if self.ctx.report.all_passed:
            print(ui.green("all tests already pass — nothing to fix"))
            return
        print(ui.info("debugging ..."))
        r = self.debugger.run(self.ctx)
        if not r.ok:
            print(ui.bad(r.message))
            return
        print(ui.ok(r.message))
        print(ui.info(f"previous version saved to "
                      f"lcagent/data/replaced/{self.ctx.pid}_before_debug.cpp"))
        print(ui.warn("reload the file in your editor before typing"))
        self.verifier.run(self.ctx)
        self._print_report()

    def cmd_finish(self, args: list[str]) -> None:
        """Classify, archive, update the tracker, and optionally commit."""
        if not self._need_ctx(args):
            return
        if self.ctx.report is None:
            print(ui.info("running the tests first ..."))
            self.verifier.run(self.ctx)
            self._print_report()
            print()
        if not self.ctx.report.all_passed:
            print(ui.bad("tests are not passing — nothing was archived or recorded"))
            return

        overwrite = "--overwrite" in args
        print(ui.banner(f"finishing problem {self.ctx.pid}"))

        c = self.classifier.run(self.ctx)
        print(ui.ok(f"topic: {c.message}") if c.ok else ui.warn(c.message))

        a = self.archiver.run(self.ctx, overwrite=overwrite)
        print(ui.ok(a.message) if a.ok else ui.warn(a.message))

        t = self.tracker.run(self.ctx, overwrite_topic=overwrite)
        if t.ok:
            print(ui.ok(f"tracker {t.data['cell']} — {t.message.split('—', 1)[-1].strip()}"))
            print(ui.dim(f"     backup: {t.data['backup']}"))
        else:
            print(ui.bad(t.message))

        if "--commit" in args:
            custom = None
            if "-m" in args:
                i = args.index("-m")
                custom = " ".join(args[i + 1:]).strip() or None
            g = self.committer.run(self.ctx, message=custom)
            print(ui.ok(g.message) if g.ok else ui.bad(g.message))
        else:
            g = self.committer.run(self.ctx, dry_run=True)
            if g.ok and g.data.get("commit_message"):
                print(ui.info(f"{g.message}"))
                print(ui.dim("     run `finish --commit` to actually commit"))
        # Notes are not run automatically: the answer is "nothing new" for most
        # problems, and a wasted model call per finish adds up on a free tier.
        print(ui.dim("     `notes` records anything reusable this one taught you"))

    def cmd_notes(self, args: list[str]) -> None:
        """Add what this problem taught you to your own notes files."""
        if not self._need_ctx(args):
            return
        target = next((a for a in args if a in notes_io.TARGETS), None)
        r = self.notes.run(
            self.ctx, target=target,
            dry_run="--dry-run" in args or "--preview" in args,
            force="--force" in args)

        if not r.ok:
            print(ui.warn(r.message) if r.data.get("duplicate") else ui.bad(r.message))
            if r.data.get("duplicate"):
                print(ui.dim("     `notes --force` adds it anyway; "
                             "`notes ds|formula|algo` picks the file"))
            return

        print(ui.ok(r.message))
        body = render_note(r)
        if body:
            print(body)
        if r.data.get("backup"):
            print(ui.dim(f"     backup: {r.data['backup']}"))
        elif not r.data.get("wrote") and r.data.get("preview"):
            print(ui.dim("     nothing was written — drop --dry-run to add it"))

    def cmd_report(self, args: list[str]) -> None:
        """Progress across the whole tracker — no problem needs to be loaded."""
        print(ui.dim("  reading the tracker ..."))
        r = self.reporter.run(self.ctx)
        if not r.ok:
            print(ui.bad(r.message))
            return
        print(render_progress(r.data))

    def cmd_provider(self, args: list[str]) -> None:
        from ..providers import describe_all, get_provider
        if args and args[0].lower() in ("models", "list"):
            p = get_provider()
            if not hasattr(p, "list_models"):
                print(ui.warn(f"{p.name} cannot list models"))
                return
            print(ui.info(f"asking {p.name} what it serves ..."))
            names = p.list_models()
            if not names:
                print(ui.warn("no models returned (check the key or the endpoint)"))
                return
            for n in names:
                print(f"  {n}")
            return

        print(ui.banner("providers") + ui.dim("   free first, paid last"))
        for name, usable, why in describe_all():
            mark = ui.green("ready") if usable else ui.dim(" --  ")
            print(f"  [{mark}] {ui.bold(name):<20} {why}")
        active = get_provider()
        print()
        print(ui.info(f"active: {active.name}"))

    def cmd_show(self, args: list[str]) -> None:
        if not self._need_ctx(args):
            return
        f = self.ctx.paths.problem
        if not f.is_file():
            print(ui.warn("no statement rendered yet — run `new` or `fetch` first"))
            return
        print(f.read_text(encoding="utf-8"))

    def cmd_fetch(self, args: list[str]) -> None:
        """Re-render just the statement file."""
        if not self._need_ctx(args):
            return
        s = self.statement.run(self.ctx, refresh=True)
        print(ui.ok(s.message) if s.ok else ui.bad(s.message))

    def cmd_watch(self, args: list[str]) -> None:
        if not self._need_ctx(args):
            return
        sol, drv = self.ctx.paths.solution, self.ctx.paths.driver
        if not sol.is_file():
            print(ui.bad(f"{sol.name} does not exist"))
            return

        print(ui.banner(f"watching {sol.name}") + ui.dim("   (Ctrl-C to stop)"))
        last = self._stamp(sol, drv)
        try:
            while True:
                time.sleep(POLL_SECONDS)
                now = self._stamp(sol, drv)
                if now == last:
                    continue
                # let the editor finish writing before compiling
                while True:
                    time.sleep(DEBOUNCE_SECONDS)
                    settled = self._stamp(sol, drv)
                    if settled == now:
                        break
                    now = settled
                last = now
                print()
                print(ui.dim(time.strftime("── %H:%M:%S ") + "─" * 40))
                r = self.verifier.run(self.ctx)
                self._print_report()
                if r.ok:                       # submitted and green — score it
                    print()
                    sc = self.scorer.run(self.ctx)
                    if sc.ok:
                        print(render_score(self.ctx.score))
        except KeyboardInterrupt:
            print("\n" + ui.info("stopped watching"))

    def cmd_status(self, args: list[str]) -> None:
        if self.ctx is None:
            print(ui.info("no problem loaded — `new <id>`"))
            return
        p = self.ctx.paths
        if self.ctx.problem is None:      # hydrate from cache, no network
            from ..core import leetcode
            self.ctx.problem = leetcode.cached_only(self.ctx.pid)
        print(ui.banner(f"problem {self.ctx.pid}"))
        if self.ctx.problem:
            d = self.ctx.problem
            print(f"  {d['title']}  ({d.get('difficulty','?')})")
            print(f"  tags: {', '.join(d.get('tags') or []) or '—'}")
        for label, path in (("solution", p.solution), ("driver", p.driver),
                            ("input", p.input), ("expected", p.expected),
                            ("statement", p.problem), ("reference", p.reference)):
            mark = ui.green("present") if path.is_file() else ui.dim("missing")
            print(f"  {label:<10} {mark}")
        if self.ctx.report:
            print(f"  last run   {self.ctx.report.status.value} "
                  f"({self.ctx.report.passed}/{self.ctx.report.total})")

    def cmd_roster(self, args: list[str]) -> None:
        from ..providers import get_provider
        prov = get_provider()
        usable, _ = prov.available()
        print(ui.banner("agent roster"))
        print(ui.dim("  offline = needs no model at all · model = needs a provider"))
        print(ui.dim(f"  provider: {prov.name if usable else 'none configured'}"
                     f"{'  (free tier — nothing here costs money)' if usable else ''}"))
        built = [self.fetcher, self.statement, self.repairer, self.verifier,
                 self.solver, self.debugger, self.scorer, self.improver,
                 self.classifier, self.archiver, self.tracker, self.committer,
                 self.notes, self.reporter, self]
        for a in built:
            # The distinction is whether the agent needs a model provider at
            # all — not cost. On a free tier every agent here is free to run.
            tag = ui.yellow("model  ") if a.requires_llm else ui.green("offline")
            print(f"  {tag}  {ui.bold(a.name):<12} {a.role}")


    def _render_menu(self) -> str:
        from ..providers import get_provider
        pid = self.ctx.pid if self.ctx else "no problem"
        prov = get_provider()
        usable = prov.available()[0]
        # Pad against the *visible* text; colour codes carry no display width,
        # so measuring the styled string would push the border out of line.
        right = prov.name if usable else "no model"
        head = f" lcagent · {pid}"

        width = 60
        pad = max(width - len(head) - len(right) - 1, 1)
        styled_right = ui.green(right) if usable else ui.dim(right)
        out = ["", ui.dim("┌" + "─" * width + "┐")]
        out.append(ui.dim("│") + ui.bold(ui.cyan(head)) + " " * pad
                   + styled_right + " " + ui.dim("│"))
        out.append(ui.dim("└" + "─" * width + "┘"))
        for section, rows in MENU:
            out.append("  " + ui.dim(section))
            for key, label, desc, _cmd in rows:
                out.append(f"   {ui.bold(ui.yellow(key))}  {label:<15} {ui.dim(desc)}")
        return "\n".join(out)

    def cmd_menu(self, args: list[str]) -> None:
        print(self._render_menu())

    def cmd_help(self, args: list[str]) -> None:
        print(ui.banner("commands"))
        for keys, desc in _HELP:
            print(f"  {ui.bold(keys):<28} {desc}")

    def cmd_quit(self, args: list[str]) -> None:
        self.running = False

    # ── helpers ──
    def _need_ctx(self, args: list[str]) -> bool:
        if args and args[0].isdigit():
            if self.ctx is None or self.ctx.pid != args[0]:
                self.ctx = Context.for_problem(args[0])
                self._save()
            return True
        if self.ctx is None:
            print(ui.warn("no problem loaded — `new <id>` or pass an id"))
            return False
        return True

    @staticmethod
    def _stamp(*files: Path) -> tuple:
        out = []
        for f in files:
            try:
                st = f.stat()
                out.append((st.st_mtime_ns, st.st_size))
            except OSError:
                out.append(None)
        return tuple(out)

    def _print_report(self) -> None:
        rep = self.ctx.report
        if rep is None:
            return
        text = rep.summary()
        if rep.status is Status.OK:
            print(ui.green(text))
        elif rep.status in (Status.COMPILE_ERROR, Status.RUNTIME_ERROR, Status.TIMEOUT,
                            Status.MISSING_FILES):
            print(ui.red(text))
        else:
            for line in text.splitlines():
                if "PASS" in line:
                    print(ui.green(line))
                elif "FAIL" in line:
                    print(ui.red(line))
                elif line.startswith("Result:"):
                    print(ui.bold(line))
                else:
                    print(ui.dim(line))

    def _prompt(self) -> str:
        return ui.cyan("  choose or type a command > ") if ui.COLOR \
            else "  choose or type a command > "

    def _greet(self) -> None:
        print(ui.banner("lcagent") + ui.dim("  LeetCode practice multi-agent system"))
        print(ui.dim(f"  repo: {paths.repo_root()}"))
        if self.ctx:
            print(ui.info(f"resumed on problem {self.ctx.pid}"))




#: The numbered menu. Each row maps a key to an existing command, so typing
#: `3` and typing `run` go down exactly the same path — the menu is a front
#: end, never a second implementation.
MENU: list[tuple[str, list[tuple[str, str, str, str]]]] = [
    ("PROBLEM", [
        ("1", "New problem",   "local archive first, else LeetCode",       "new"),
        ("2", "Show question", "statement, constraints, test cases",       "show"),
        ("3", "Repair driver", "fill the driver's TODO scaffolding",       "repair"),
    ]),
    ("SOLVE", [
        ("4", "Run tests",     "compile, run, per-case results",           "run"),
        ("5", "Watch",         "auto test + score on every save",          "watch"),
        ("6", "Solve for me",  "write the solution from the statement",    "solve"),
        ("7", "Fix failures",  "debug until the failing cases pass",       "fix"),
    ]),
    ("REVIEW", [
        ("8", "Score",         "grade + better-approach check",            "score"),
        ("9", "Better code",   "verify the suggestion, then write it in",  "better"),
    ]),
    ("FINISH", [
        ("f", "Finish",        "classify, archive, update the tracker",    "finish"),
        ("l", "Notes",         "add the reusable trick to your notes",     "notes"),
    ]),
    ("SESSION", [
        ("s", "Status",        "what is loaded, which files exist",        "status"),
        ("g", "Progress",      "solved counts, thin topics, \u2b50 queue",     "report"),
        ("a", "Agents",        "the agent roster",                         "roster"),
        ("p", "Providers",     "model backends, and which are usable",     "provider"),
        ("h", "Help",          "every command and alias",                  "help"),
        ("0", "Quit",          "save the session and exit",                "quit"),
    ]),
]

NUMBERS = {key: cmd for _, rows in MENU for key, _, _, cmd in rows}

_ALIASES = {
    "new": "cmd_new", "n": "cmd_new",
    "run": "cmd_run", "r": "cmd_run", "test": "cmd_run", "t": "cmd_run",
    "show": "cmd_show", "s": "cmd_show", "problem": "cmd_show", "p": "cmd_show",
    "fetch": "cmd_fetch",
    "statements": "cmd_statements", "questions": "cmd_statements",
    "score": "cmd_score", "sc": "cmd_score", "grade": "cmd_score",
    "better": "cmd_better", "improve": "cmd_better", "b": "cmd_better",
    "repair": "cmd_repair", "driver": "cmd_repair",
    "solve": "cmd_solve",
    "fix": "cmd_fix", "debug": "cmd_fix",
    "finish": "cmd_finish", "f": "cmd_finish", "archive": "cmd_finish",
    "notes": "cmd_notes", "note": "cmd_notes",
    "report": "cmd_report", "progress": "cmd_report", "stats": "cmd_report",
    "provider": "cmd_provider", "providers": "cmd_provider",
    "watch": "cmd_watch", "w": "cmd_watch",
    "status": "cmd_status", "st": "cmd_status",
    "roster": "cmd_roster", "agents": "cmd_roster",
    "help": "cmd_help", "h": "cmd_help", "?": "cmd_help",
    "menu": "cmd_menu", "m": "cmd_menu",
    "quit": "cmd_quit", "q": "cmd_quit", "exit": "cmd_quit", "stop": "cmd_quit",
}

_HELP = [
    ("new <id> [--live]", "scaffold from the local archive (empty stub), else LeetCode"),
    ("    --live", "skip the archive, fetch a fresh scaffold from LeetCode"),
    ("    --offline", "use the local archive only, no network"),
    ("    --force", "refetch even if files already exist"),
    ("run [id]  (r, test)", "compile, run the test cases, show per-case results"),
    ("score     (sc)", "grade the solution and say if a better approach exists"),
    ("better    (improve)", "verify the suggested solution, then write it into <id>.cpp"),
    ("repair    (driver)", "fill the driver's TODO scaffolding, then retest"),
    ("solve     [--force]", "write the solution from the statement"),
    ("fix       (debug)", "patch the solution until the failing cases pass"),
    ("finish    (f, archive)", "classify, archive, update LC Tracker.xlsx"),
    ("    --commit [-m msg]", "also commit as the next U<n>, or your own message"),
    ("    --overwrite", "replace an existing archive entry / tracker topic"),
    ("notes     [ds|formula|algo]", "append a reusable technique to your notes files"),
    ("    --dry-run", "show the entry without writing it"),
    ("    --force", "add it even if it looks like a duplicate"),
    ("report    (progress, stats)", "solved counts, thin topics, \u2b50 queue, unsolved runs"),
    ("watch     (w)", "re-run on every save and score when green, until Ctrl-C"),
    ("provider [models]", "which model providers are usable; free ones first"),
    ("show      (s, p)", "print the problem statement + test cases"),
    ("fetch", "re-render the statement from LeetCode"),
    ("statements [ids] [--refresh]", "write <id>_problem.txt into every Code Dirs/ folder"),
    ("status    (st)", "what is loaded and which files exist"),
    ("roster    (agents)", "list the agents and which ones need a model"),
    ("menu      (m, Enter)", "redisplay the numbered menu"),
    ("help      (h, ?)", "this list"),
    ("quit      (q, exit)", "leave the loop"),
    ("", ""),
    ("python -m lcagent setup", "check/install compiler, openpyxl, launchers, keys"),
    ("python -m lcagent doctor", "the same checks, changing nothing"),
]
