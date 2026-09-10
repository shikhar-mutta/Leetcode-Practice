#!/usr/bin/env python3
"""
Executing a compiled solution against an input file.

subprocess's own `timeout` is used rather than signal.alarm or SIGKILL, because
signals are the one part of process control that differs sharply between
Windows and POSIX. subprocess handles the difference for us.
"""

from __future__ import annotations

import subprocess
import time
from dataclasses import dataclass
from pathlib import Path


@dataclass
class RunResult:
    exit_code: int
    stdout: str
    stderr: str
    elapsed_ms: float
    timed_out: bool = False

    @property
    def ok(self) -> bool:
        return self.exit_code == 0 and not self.timed_out

    def stdout_lines(self) -> list[str]:
        return self.stdout.splitlines()


def run_binary(
    binary: Path,
    stdin_text: str = "",
    *,
    timeout: float = 10.0,
    cwd: Path | None = None,
) -> RunResult:
    """
    Feed `stdin_text` to `binary` and capture both streams.

    stderr matters as much as stdout here: the generated drivers echo every
    input line to stderr with a `---` between cases, which is how a failing
    case gets its input reconstructed for display.
    """
    started = time.perf_counter()
    try:
        proc = subprocess.run(
            [str(binary)],
            input=stdin_text,
            capture_output=True,
            text=True,
            errors="replace",
            timeout=timeout,
            cwd=str(cwd) if cwd else None,
        )
    except subprocess.TimeoutExpired as e:
        return RunResult(
            exit_code=-1,
            stdout=_as_text(e.stdout),
            stderr=_as_text(e.stderr),
            elapsed_ms=(time.perf_counter() - started) * 1000.0,
            timed_out=True,
        )

    return RunResult(
        exit_code=proc.returncode,
        stdout=proc.stdout,
        stderr=proc.stderr,
        elapsed_ms=(time.perf_counter() - started) * 1000.0,
    )


def _as_text(v) -> str:
    """TimeoutExpired hands back bytes or str depending on the path taken."""
    if v is None:
        return ""
    return v if isinstance(v, str) else v.decode("utf-8", "replace")
