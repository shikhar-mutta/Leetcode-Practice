#!/usr/bin/env python3
"""
VerifierAgent — compile, run and diff. The feedback signal for every other agent.

Deliberately the first thing built and entirely deterministic: the scorer, the
debugger and the archiver all gate on its verdict, so it has to be trustworthy
before a single model call is made.
"""

from __future__ import annotations

from ..core.state import Context
from ..core.testcase import Status, verify
from .base import Agent, AgentResult


class VerifierAgent(Agent):
    name = "verifier"
    role = "Compile the driver, run the test cases, and report per-case results"
    requires_llm = False

    def run(self, ctx: Context, *, timeout: float = 10.0, std: str = "gnu++20", **_) -> AgentResult:
        report = verify(ctx.pid, root=ctx.paths.root, timeout=timeout, std=std)
        ctx.report = report

        if report.status is Status.OK:
            msg = f"{report.passed}/{report.total} passed in {report.elapsed_ms:.0f} ms"
        elif report.status is Status.WRONG_ANSWER:
            msg = f"{report.passed}/{report.total} passed"
        else:
            msg = report.status.value.replace("_", " ").lower()

        ctx.note(self.name, msg)
        result = AgentResult(self.name, report.all_passed, msg,
                             {"status": report.status.value,
                              "passed": report.passed,
                              "total": report.total,
                              "elapsed_ms": report.elapsed_ms})
        return result
