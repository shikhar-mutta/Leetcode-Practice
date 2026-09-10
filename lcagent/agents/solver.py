#!/usr/bin/env python3
"""
SolverAgent — write `<id>.cpp` from the problem statement.

Deliberately the least trusted agent in the system. It writes into the working
tree only after its output passes the real test cases, and it refuses to
overwrite a solution you have already written unless asked: the point of the
repo is that you solve the problems.
"""

from __future__ import annotations

import re

from ..core import paths
from ..core.state import Context
from ..providers import get_provider
from .base import Agent, AgentResult
from .codegen import generate_with_retry, keep_link_line


class SolverAgent(Agent):
    name = "solver"
    role = "Write the solution from the problem statement"
    requires_llm = True

    def run(self, ctx: Context, *, force: bool = False, **_) -> AgentResult:
        if not ctx.paths.solution.is_file():
            return self.fail(f"{ctx.paths.solution.name} does not exist — fetch the problem first")

        current = ctx.paths.solution.read_text(encoding="utf-8", errors="replace")
        if self._has_work(current) and not force:
            return self.fail(
                f"{ctx.paths.solution.name} already contains a solution — "
                f"`solve --force` to replace it (a backup is kept)")

        provider = get_provider()
        usable, why = provider.available()
        if not usable:
            return self.fail(f"needs a model provider — {why}")

        statement = (ctx.paths.problem.read_text(encoding="utf-8", errors="replace")[:4000]
                     if ctx.paths.problem.is_file() else "")
        if not statement:
            return self.fail("no problem statement available to solve from")

        system = (
            "You solve competitive-programming problems in C++. "
            "Reply with ONLY the complete `class Solution` in one ```cpp fenced block, "
            "keeping the exact public method signature given. Prefer the optimal "
            "complexity for the stated constraints. Do not write a main()."
        )
        prompt = f"""{statement}

=== THE STUB TO FILL ({ctx.paths.solution.name}) ===
{current}

Write the complete solution. Match the signature exactly and aim for the best
complexity the constraints allow."""

        res = generate_with_retry(ctx, provider, system=system, prompt=prompt,
                                  must_contain="class Solution")
        if not res.ok:
            return self.fail(f"could not produce a passing solution — {res.summary()}",
                             attempts=res.tries, tokens=res.tokens)

        backup = self._backup(ctx) if self._has_work(current) else None
        ctx.paths.solution.write_text(keep_link_line(ctx, res.code), encoding="utf-8")
        ctx.report = None
        ctx.score = None
        ctx.note(self.name, f"wrote {ctx.paths.solution.name} ({res.summary()})")
        return self.ok(f"wrote {ctx.paths.solution.name} — {res.summary()}",
                       artifacts=[ctx.paths.solution], attempts=res.tries,
                       tokens=res.tokens, backup=str(backup) if backup else None)

    @staticmethod
    def _has_work(code: str) -> bool:
        """Whether the file holds a real solution rather than an empty stub."""
        body = re.sub(r"//.*", "", code)
        body = re.sub(r"#include.*", "", body)
        return bool(re.search(r"\b(return|for|while|if)\b", body))

    @staticmethod
    def _backup(ctx: Context):
        d = paths.agent_data_dir() / "replaced"
        d.mkdir(parents=True, exist_ok=True)
        target = d / f"{ctx.pid}_before_solve.cpp"
        try:
            target.write_bytes(ctx.paths.solution.read_bytes())
            return target
        except OSError:
            return None
