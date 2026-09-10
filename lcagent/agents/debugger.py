#!/usr/bin/env python3
"""
DebuggerAgent — take a failing verdict and patch the solution until it passes.

This closes the only cycle in the system: Verifier → Debugger → Verifier. The
loop is capped, and the failing case (input, expected, actual) is fed back on
every round, which is a far stronger signal than restating the problem.

It never touches a solution that is already passing, and never writes a patch
that does not itself pass.
"""

from __future__ import annotations

from ..core import paths
from ..core.state import Context
from ..core.testcase import Status
from ..providers import get_provider
from .base import Agent, AgentResult
from .codegen import generate_with_retry, keep_link_line


class DebuggerAgent(Agent):
    name = "debugger"
    role = "Patch a failing solution using the verifier's report"
    requires_llm = True

    def run(self, ctx: Context, *, max_attempts: int = 3, **_) -> AgentResult:
        if ctx.report is None:
            return self.fail("nothing verified yet — `run` first")
        if ctx.report.all_passed:
            return self.ok("all tests already pass — nothing to debug", changed=False)

        provider = get_provider()
        usable, why = provider.available()
        if not usable:
            return self.fail(f"needs a model provider — {why}")

        current = ctx.paths.solution.read_text(encoding="utf-8", errors="replace")
        statement = (ctx.paths.problem.read_text(encoding="utf-8", errors="replace")[:3000]
                     if ctx.paths.problem.is_file() else "")

        system = (
            "You debug C++ competitive-programming solutions. "
            "You are given a solution, and the exact test cases it fails. "
            "Find the actual cause and fix it — do not rewrite the approach unless the "
            "approach itself is wrong. Reply with ONLY the complete corrected "
            "`class Solution` in one ```cpp fenced block."
        )
        prompt = f"""{statement}

=== THE FAILING SOLUTION ({ctx.paths.solution.name}) ===
{current}

=== WHAT WENT WRONG ===
{self._failure_detail(ctx)}

Fix the solution so every case passes."""

        res = generate_with_retry(ctx, provider, system=system, prompt=prompt,
                                  must_contain="class Solution",
                                  max_attempts=max_attempts)
        if not res.ok:
            return self.fail(f"could not fix it — {res.summary()}",
                             attempts=res.tries, tokens=res.tokens)

        backup = self._backup(ctx)
        ctx.paths.solution.write_text(keep_link_line(ctx, res.code), encoding="utf-8")
        ctx.report = None
        ctx.score = None
        ctx.note(self.name, f"patched {ctx.paths.solution.name} ({res.summary()})")
        return self.ok(f"fixed {ctx.paths.solution.name} — {res.summary()}",
                       artifacts=[ctx.paths.solution], attempts=res.tries,
                       tokens=res.tokens, backup=str(backup) if backup else None,
                       changed=True)

    @staticmethod
    def _failure_detail(ctx: Context) -> str:
        rep = ctx.report
        if rep.status is Status.COMPILE_ERROR and rep.compile_result:
            return "It does not compile:\n" + rep.compile_result.first_error(16)
        if rep.status is Status.TIMEOUT:
            return ("It times out — the approach is too slow for the stated constraints. "
                    "A faster algorithm is required, not a micro-optimisation.")
        if rep.status is Status.RUNTIME_ERROR:
            return "It crashes at runtime:\n" + rep.detail
        lines = [f"{rep.passed} of {rep.total} cases pass. The failures:"]
        for c in rep.failures()[:4]:
            lines.append(f"\n  case {c.index}:")
            if c.stdin_block:
                for ln in c.stdin_block.splitlines():
                    lines.append(f"    input    : {ln}")
            lines.append(f"    expected : {c.expected}")
            lines.append(f"    got      : {c.actual if c.actual is not None else '<no output>'}")
        return "\n".join(lines)

    @staticmethod
    def _backup(ctx: Context):
        d = paths.agent_data_dir() / "replaced"
        d.mkdir(parents=True, exist_ok=True)
        target = d / f"{ctx.pid}_before_debug.cpp"
        try:
            target.write_bytes(ctx.paths.solution.read_bytes())
            return target
        except OSError:
            return None
