#!/usr/bin/env python3
"""
The verification pipeline: compile, run, compare — the Python port of run.sh.

Ported rather than shelled out to, because cmd.exe has no bash. The payoff
beyond portability is that results come back as a TestReport the scoring and
debugging agents can read directly, instead of as text they'd have to re-parse.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from enum import Enum
from pathlib import Path

from . import paths
from .compiler import CompileResult, compile_cpp
from .runner import RunResult, run_binary


class Status(str, Enum):
    OK = "OK"                        # every case matched
    WRONG_ANSWER = "WRONG_ANSWER"    # ran clean, output differs
    COMPILE_ERROR = "COMPILE_ERROR"
    RUNTIME_ERROR = "RUNTIME_ERROR"
    TIMEOUT = "TIMEOUT"
    MISSING_FILES = "MISSING_FILES"


@dataclass
class CaseResult:
    index: int                       # 1-based, matching run.sh's "Test 1:"
    expected: str
    actual: str | None               # None when the program printed too few lines
    passed: bool
    stdin_block: str = ""            # this case's input, recovered from stderr


@dataclass
class TestReport:
    status: Status
    cases: list[CaseResult] = field(default_factory=list)
    compile_result: CompileResult | None = None
    run_result: RunResult | None = None
    source: Path | None = None
    detail: str = ""                 # missing-file list, runtime message, etc.

    @property
    def passed(self) -> int:
        return sum(1 for c in self.cases if c.passed)

    @property
    def total(self) -> int:
        return len(self.cases)

    @property
    def all_passed(self) -> bool:
        return self.status is Status.OK

    @property
    def elapsed_ms(self) -> float:
        return self.run_result.elapsed_ms if self.run_result else 0.0

    def failures(self) -> list[CaseResult]:
        return [c for c in self.cases if not c.passed]

    def summary(self) -> str:
        """run.sh-shaped output, so the terminal feel stays familiar."""
        if self.status is Status.MISSING_FILES:
            return f"ERROR: {self.detail}"
        if self.status is Status.COMPILE_ERROR:
            err = self.compile_result.first_error() if self.compile_result else ""
            return f"COMPILE ERROR\n{err}"
        if self.status is Status.TIMEOUT:
            return f"TIMEOUT\n{self.detail}"
        if self.status is Status.RUNTIME_ERROR:
            return f"RUNTIME ERROR\n{self.detail}"

        out = []
        for c in self.cases:
            if c.passed:
                out.append(f"Test {c.index}: PASS  (output: {c.actual})")
            else:
                shown = "<no output>" if c.actual is None else c.actual
                out.append(f"Test {c.index}: FAIL  (expected: {c.expected}  |  got: {shown})")
                for i, line in enumerate(c.stdin_block.splitlines()):
                    out.append(f"         input: {line}" if i == 0 else f"                {line}")
        out.append("")
        out.append(f"Result: {self.passed} / {self.total} passed  ({self.elapsed_ms:.0f} ms)")
        return "\n".join(out)


# ─── stderr → per-case input blocks ──────────────────────────────────────────

def split_case_inputs(stderr: str) -> list[str]:
    """
    Recover each case's raw input from the driver's stderr echo.

    Drivers emit every consumed line, then a lone `---` to close the case.
    Compiled with -DDEBUG the echo is suppressed, so this returns nothing and
    failing cases simply display without their input.
    """
    blocks, cur = [], []
    for line in stderr.splitlines():
        if line.strip() == "---":
            blocks.append("\n".join(cur).rstrip())
            cur = []
        else:
            cur.append(line)
    if cur and any(s.strip() for s in cur):
        blocks.append("\n".join(cur).rstrip())
    return blocks


# ─── the pipeline ────────────────────────────────────────────────────────────

def verify(
    pid: int | str,
    *,
    root: Path | None = None,
    std: str = "gnu++20",
    timeout: float = 10.0,
    optimize: bool = True,
) -> TestReport:
    """Compile problem `pid`'s driver, run it on _input.txt, diff vs _expected.txt."""
    pp = paths.ProblemPaths(pid, root)

    src = pp.compile_target()
    if src is None:
        return TestReport(
            Status.MISSING_FILES,
            detail=f"no source for problem {pp.pid} (looked for {pp.pid}_*.cpp and {pp.pid}.cpp)",
        )
    absent = pp.missing("input", "expected")
    if absent:
        return TestReport(
            Status.MISSING_FILES,
            source=src,
            detail=", ".join(p.name for p in absent) + " not found",
        )

    comp = compile_cpp(src, f"sol_{pp.pid}", std=std, optimize=optimize)
    if not comp.ok:
        return TestReport(Status.COMPILE_ERROR, compile_result=comp, source=src)

    stdin_text = pp.input.read_text(encoding="utf-8", errors="replace")
    run = run_binary(comp.binary, stdin_text, timeout=timeout)

    if run.timed_out:
        return TestReport(Status.TIMEOUT, compile_result=comp, run_result=run, source=src,
                          detail=f"killed after {timeout:.0f}s")
    if run.exit_code != 0:
        return TestReport(Status.RUNTIME_ERROR, compile_result=comp, run_result=run, source=src,
                          detail=f"exit code {run.exit_code}\n{run.stderr.strip()[-800:]}")

    expected_lines = pp.expected.read_text(encoding="utf-8", errors="replace").splitlines()
    actual_lines = run.stdout_lines()
    blocks = split_case_inputs(run.stderr)

    cases = []
    for i, exp in enumerate(expected_lines):
        act = actual_lines[i] if i < len(actual_lines) else None
        cases.append(CaseResult(
            index=i + 1,
            expected=exp,
            actual=act,
            passed=act is not None and act.strip() == exp.strip(),
            stdin_block=blocks[i] if i < len(blocks) else "",
        ))

    status = Status.OK if all(c.passed for c in cases) and cases else Status.WRONG_ANSWER
    return TestReport(status, cases=cases, compile_result=comp, run_result=run, source=src)
