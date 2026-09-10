#!/usr/bin/env python3
"""
DriverRepairAgent — fill the `// TODO` scaffolding fetch_problem.py leaves behind.

fetch_problem.py generates a driver for every problem, but its type table only
covers the common shapes. Anything else — `Node*` graphs, nested integers, quad
trees, unusual return types — lands as a `// TODO: parse ...` line that still
consumes its input line, so the file compiles and the gap is obvious. This is
the repo's documented recurring gap and the one piece with no manual workaround.

Also handles special judges, which are not TODO-marked and so are easy to miss:
problems where any correct answer is accepted, and the fetched _expected.txt
holds one particular reference answer that a different valid answer will never
match.
"""

from __future__ import annotations

import re

from ..core.state import Context
from ..providers import get_provider
from .base import Agent, AgentResult
from .codegen import generate_with_retry

TODO_RE = re.compile(r"//\s*TODO[^\n]*", re.I)


class DriverRepairAgent(Agent):
    name = "driver-repair"
    role = "Fill the driver's TODO scaffolding so a problem can actually be tested"
    requires_llm = True

    def run(self, ctx: Context, *, force: bool = False, **_) -> AgentResult:
        if not ctx.paths.driver.is_file():
            return self.fail(f"{ctx.paths.driver.name} does not exist")

        driver = ctx.paths.driver.read_text(encoding="utf-8", errors="replace")
        todos = TODO_RE.findall(driver)
        if not todos and not force:
            return self.ok("driver has no TODO scaffolding — nothing to repair",
                           todos=0, changed=False)

        provider = get_provider()
        usable, why = provider.available()
        if not usable:
            return self.fail(f"needs a model provider — {why}")

        solution = (ctx.paths.solution.read_text(encoding="utf-8", errors="replace")
                    if ctx.paths.solution.is_file() else "")
        statement = (ctx.paths.problem.read_text(encoding="utf-8", errors="replace")[:2500]
                     if ctx.paths.problem.is_file() else "")
        sample_in = self._head(ctx.paths.input, 8)
        sample_exp = self._head(ctx.paths.expected, 5)

        system = (
            "You repair C++ test drivers for LeetCode problems. "
            "The driver reads test cases from stdin, calls the Solution class, and prints "
            "one line of output per case in exactly the format the expected file uses. "
            "Keep every existing helper function and the overall structure; change only "
            "what is needed. Reply with ONLY the complete corrected driver in one "
            "```cpp fenced block."
        )
        prompt = f"""{statement}

=== THE SOLUTION THE DRIVER MUST CALL ({ctx.paths.solution.name}) ===
{solution}

=== THE DRIVER TO REPAIR ({ctx.paths.driver.name}) ===
{driver}

=== {ctx.paths.input.name} (first lines) ===
{sample_in}

=== {ctx.paths.expected.name} (first lines) ===
{sample_exp}

There {'are' if len(todos) != 1 else 'is'} {len(todos)} unfinished TODO line(s):
{chr(10).join('  ' + t for t in todos) or '  (none — verify the output format instead)'}

Fill them in so the driver builds the inputs, calls the solution, and prints
output matching the expected file exactly. Keep `#include "{ctx.pid}.cpp"` and
the existing reader helpers."""

        # With an empty stub no output could match the expected file, so the
        # driver is held only to compiling against the real type definitions.
        stub_only = not self._has_implementation(solution)
        res = generate_with_retry(ctx, provider, system=system, prompt=prompt,
                                  is_driver=True, must_contain="int main",
                                  compile_only=stub_only)
        if not res.ok:
            return self.fail(f"could not repair the driver — {res.summary()}",
                             attempts=res.tries, tokens=res.tokens)

        ctx.paths.driver.write_text(res.code, encoding="utf-8")
        ctx.report = None                     # the driver changed; old verdict is stale
        ctx.note(self.name, f"repaired {ctx.paths.driver.name} ({res.summary()})")
        return self.ok(f"repaired {ctx.paths.driver.name} — {res.summary()}",
                       artifacts=[ctx.paths.driver], todos=len(todos), changed=True,
                       attempts=res.tries, tokens=res.tokens)

    @staticmethod
    def _has_implementation(code: str) -> bool:
        """Whether the solution file holds real code rather than an empty stub."""
        body = re.sub(r"//.*", "", code)
        body = re.sub(r"#include.*", "", body)
        # class definitions (Node, ListNode) carry no `return`/loop of their own
        return bool(re.search(r"\b(return|for|while)\b", body))

    @staticmethod
    def _head(path, n: int) -> str:
        if not path.is_file():
            return "(missing)"
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
        out = "\n".join(lines[:n])
        return out + (f"\n... ({len(lines) - n} more lines)" if len(lines) > n else "")
