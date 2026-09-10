#!/usr/bin/env python3
"""
Shared machinery for the agents that write C++.

DriverRepair, Solver, Debugger and Improver all do the same three things:
ask a model for code, pull the code back out of the reply, and prove it works
before it is allowed near the working tree. That loop lives here once.

The retry loop is the important part. Free-tier models are weaker at C++ than
frontier ones, so the first attempt often does not compile — but the compiler
error is an excellent teaching signal, and feeding it back usually fixes it in
one round. Attempts are capped so a model that cannot converge fails fast
instead of burning the token budget.
"""

from __future__ import annotations

import re
import shutil
from dataclasses import dataclass, field
from pathlib import Path

from ..core import paths
from ..core.compiler import compile_cpp
from ..core.runner import run_binary
from ..core.state import Context
from ..providers import ProviderError

MAX_ATTEMPTS = 3


@dataclass
class Attempt:
    n: int
    ok: bool
    detail: str
    passed: int = 0
    total: int = 0


@dataclass
class CodegenResult:
    ok: bool
    code: str = ""
    attempts: list[Attempt] = field(default_factory=list)
    passed: int = 0
    total: int = 0
    tokens: int = 0

    @property
    def tries(self) -> int:
        return len(self.attempts)

    def summary(self) -> str:
        last = self.attempts[-1].detail if self.attempts else "no attempts"
        if self.ok:
            return f"verified {self.passed}/{self.total} after {self.tries} attempt(s)"
        return f"failed after {self.tries} attempt(s): {last}"


# ─── pulling code out of a reply ─────────────────────────────────────────────

def extract_code(text: str, *, must_contain: str = "") -> str:
    """Take the C++ out of a model reply, fenced or bare."""
    if not text:
        return ""
    m = re.search(r"```(?:cpp|c\+\+)?\s*(.*?)```", text, re.DOTALL | re.I)
    body = (m.group(1) if m else text).strip()
    if must_contain and must_contain not in body:
        return ""
    return body


def ensure_includes(code: str) -> str:
    if "#include" not in code:
        return "#include <bits/stdc++.h>\nusing namespace std;\n\n" + code
    return code


def keep_link_line(ctx: Context, code: str) -> str:
    """Preserve the `// Link:` line the repo puts at the top of every solution."""
    try:
        first = ctx.paths.solution.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return code
    if first and first[0].startswith("// Link:") and not code.startswith("// Link:"):
        return first[0] + "\n\n" + code
    return code


# ─── proving it works ────────────────────────────────────────────────────────

def verify_pair(ctx: Context, solution_code: str | None = None,
                driver_code: str | None = None, *, timeout: float = 15.0,
                compile_only: bool = False) -> Attempt:
    """
    Compile and run a candidate solution and/or driver in a scratch directory.

    Neither file is written into the working tree — whichever side is not being
    tested is copied from the repo, so a candidate is always exercised against
    the real counterpart it will have to work with.
    """
    pid = ctx.pid
    stage = paths.build_dir() / f"cg_{pid}"
    try:
        shutil.rmtree(stage, ignore_errors=True)
        stage.mkdir(parents=True, exist_ok=True)

        sol_dst, drv_dst = stage / f"{pid}.cpp", stage / f"{pid}_driver.cpp"
        if solution_code is not None:
            sol_dst.write_text(solution_code, encoding="utf-8")
        elif ctx.paths.solution.is_file():
            shutil.copy2(ctx.paths.solution, sol_dst)
        else:
            return Attempt(0, False, "no solution to compile")

        if driver_code is not None:
            drv_dst.write_text(driver_code, encoding="utf-8")
        elif ctx.paths.driver.is_file():
            shutil.copy2(ctx.paths.driver, drv_dst)
        else:
            return Attempt(0, False, "no driver to compile")

        comp = compile_cpp(drv_dst, f"cgbin_{pid}")
        if not comp.ok:
            return Attempt(0, False, "compile error:\n" + comp.first_error(14))

        if compile_only:
            # Used when the solution is still an empty stub: the driver can be
            # proven to build against the real type definitions, but no output
            # it produces could possibly match the expected file yet.
            return Attempt(0, True, "compiles against the solution stub")
        if not (ctx.paths.input.is_file() and ctx.paths.expected.is_file()):
            return Attempt(0, True, "compiles (no test files to run against)")

        run = run_binary(comp.binary,
                         ctx.paths.input.read_text(encoding="utf-8", errors="replace"),
                         timeout=timeout)
        if run.timed_out:
            return Attempt(0, False, f"timed out after {timeout:.0f}s")
        if run.exit_code != 0:
            return Attempt(0, False, f"runtime error (exit {run.exit_code}): "
                                     f"{run.stderr.strip()[-300:]}")

        exp = ctx.paths.expected.read_text(encoding="utf-8", errors="replace").splitlines()
        got = run.stdout_lines()
        passed = sum(1 for i, e in enumerate(exp)
                     if i < len(got) and got[i].strip() == e.strip())
        if passed == len(exp) and exp:
            return Attempt(0, True, "all cases pass", passed, len(exp))

        diffs = []
        for i, e in enumerate(exp):
            g = got[i] if i < len(got) else "<no output>"
            if g.strip() != e.strip():
                diffs.append(f"  case {i+1}: expected {e!r}, got {g!r}")
                if len(diffs) == 3:
                    break
        return Attempt(0, False, f"{passed}/{len(exp)} cases pass\n" + "\n".join(diffs),
                       passed, len(exp))
    except OSError as e:
        return Attempt(0, False, f"staging error: {e}")
    finally:
        shutil.rmtree(stage, ignore_errors=True)


# ─── the retry loop ──────────────────────────────────────────────────────────

def generate_with_retry(ctx: Context, provider, *, system: str, prompt: str,
                        is_driver: bool = False, must_contain: str = "",
                        max_attempts: int = MAX_ATTEMPTS,
                        max_tokens: int = 4000,
                        compile_only: bool = False) -> CodegenResult:
    """
    Ask for code, verify it, and feed failures back until it works or runs out.

    Each retry appends the previous attempt's compiler or test output, which is
    a far stronger correction signal than restating the request.
    """
    result = CodegenResult(ok=False)
    conversation = prompt

    for n in range(1, max_attempts + 1):
        try:
            comp = provider.complete(system, conversation, tier="smart", max_tokens=max_tokens)
        except ProviderError as e:
            result.attempts.append(Attempt(n, False, str(e)))
            return result
        result.tokens += comp.tokens

        code = ensure_includes(extract_code(comp.text, must_contain=must_contain))
        if not code:
            result.attempts.append(Attempt(n, False, "no usable code in the reply"))
            conversation = (prompt + "\n\nYour previous reply contained no usable C++ code "
                                     "block. Reply with only a ```cpp fenced block.")
            continue

        att = verify_pair(ctx,
                          driver_code=code if is_driver else None,
                          solution_code=None if is_driver else code,
                          compile_only=compile_only)
        att.n = n
        result.attempts.append(att)
        if att.ok:
            result.ok, result.code = True, code
            result.passed, result.total = att.passed, att.total
            return result

        conversation = (f"{prompt}\n\n=== YOUR PREVIOUS ATTEMPT ===\n{code}\n\n"
                        f"=== IT FAILED ===\n{att.detail}\n\n"
                        f"Fix it and reply with the corrected complete code only.")
    return result
