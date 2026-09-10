#!/usr/bin/env python3
"""
ImproverAgent — turn the scorer's "a better solution exists" verdict into code.

The verdict alone ("use a binary search partition, O(log(min(m,n)))") names the
approach but leaves the work undone. This writes the actual solution, with
comments explaining the mechanism, and then **verifies it against the same
driver and test cases** before handing it over — a suggested improvement that
does not compile, or is wrong, is worse than no suggestion at all.

Output goes to data/improved/<id>_better.cpp rather than the repo root on
purpose: run.sh picks its compile target with the glob `<id>_*.cpp` and takes
the first sorted match, so a root-level `<id>_better.cpp` would sort ahead of
`<id>_driver.cpp` and break the existing workflow.
"""

from __future__ import annotations

import re
import shutil

from ..core import paths
from ..core.compiler import compile_cpp
from ..core.runner import run_binary
from ..core.state import Context
from ..providers import ProviderError, get_provider
from .base import Agent, AgentResult


class ImproverAgent(Agent):
    name = "improver"
    role = "Write and verify the better solution the scorer identified"
    requires_llm = True

    def run(self, ctx: Context, *, verify: bool = True,
            write_to_solution: bool = True, **_) -> AgentResult:
        """
        Generate the better solution, verify it, then install it.

        Ordering matters: the candidate is verified against the real driver
        *before* it is allowed near `<id>.cpp`. A suggestion that does not
        compile, or fails a case, must never replace code that works — in that
        case it stays in data/improved/ and the solution file is untouched.
        The previous solution is backed up either way.
        """
        score = ctx.score or {}
        better = score.get("better")
        if not better:
            if score:
                return self.fail("the scorer found no better approach for this solution")
            return self.fail("nothing scored yet — `score` first")

        provider = get_provider()
        usable, why = provider.available()
        if not usable:
            return self.fail(f"needs a model provider — {why}")

        try:
            code = self._generate(ctx, better, provider)
        except ProviderError as e:
            return self.fail(str(e))
        if not code:
            return self.fail("the model did not return a usable C++ solution")

        out_dir = paths.agent_data_dir() / "improved"
        out_dir.mkdir(parents=True, exist_ok=True)
        candidate = out_dir / f"{ctx.pid}_better.cpp"
        candidate.write_text(code, encoding="utf-8")

        data = {"approach": better.get("approach"), "candidate": str(candidate),
                "installed": False, "backup": None}

        if not verify:
            ctx.note(self.name, f"wrote {candidate.name} (unverified)")
            return self.ok(f"wrote {candidate.name} — not verified", artifacts=[candidate], **data)

        passed, total, detail = self._verify(ctx, candidate)
        data.update(passed=passed, total=total, detail=detail)
        good = bool(total) and passed == total

        if not good:
            ctx.note(self.name, f"candidate failed verification: {detail}")
            return self.ok(
                f"{better.get('approach')} — VERIFICATION FAILED ({detail}); "
                f"{ctx.paths.solution.name} left untouched",
                artifacts=[candidate], **data)

        if write_to_solution and ctx.paths.solution.is_file():
            backup = self._backup(ctx)
            data["backup"] = str(backup) if backup else None
            ctx.paths.solution.write_text(code, encoding="utf-8")
            data["installed"] = True
            ctx.report = None          # the file changed; the old verdict is stale
            ctx.score = None
            ctx.note(self.name, f"installed better solution into {ctx.paths.solution.name}")
            return self.ok(
                f"{better.get('approach')} — verified {passed}/{total} and written to "
                f"{ctx.paths.solution.name}",
                artifacts=[ctx.paths.solution], **data)

        ctx.note(self.name, f"{candidate.name} verified {passed}/{total}")
        return self.ok(f"{better.get('approach')} — verified {passed}/{total}",
                       artifacts=[candidate], **data)

    def _backup(self, ctx: Context):
        """Keep the current solution before it is replaced."""
        bak_dir = paths.agent_data_dir() / "replaced"
        bak_dir.mkdir(parents=True, exist_ok=True)
        target = bak_dir / f"{ctx.pid}_before_improve.cpp"
        try:
            shutil.copy2(ctx.paths.solution, target)
            return target
        except OSError:
            return None

    # ── generation ──
    def _generate(self, ctx: Context, better: dict, provider) -> str:
        current = ctx.paths.solution.read_text(encoding="utf-8", errors="replace")
        statement = (ctx.paths.problem.read_text(encoding="utf-8", errors="replace")[:3500]
                     if ctx.paths.problem.is_file() else "")
        system = (
            "You write competitive-programming C++ solutions. "
            "Output ONLY a C++ code block: the complete `class Solution` with the same "
            "public method signature as the code you are given, plus any includes it needs. "
            "Add short comments explaining the key steps and why the approach is faster. "
            "No prose outside the code block."
        )
        prompt = f"""{statement}

=== THE CURRENT SOLUTION (to be improved on) ===
{current}

=== THE APPROACH TO IMPLEMENT ===
name: {better.get('approach')}
time: {better.get('time')}
why:  {better.get('why')}

Write that approach as a complete, compilable `class Solution` with the same
public method signature. Include `#include <bits/stdc++.h>` and `using namespace std;`."""

        comp = provider.complete(system, prompt, tier="smart", max_tokens=4000)
        return self._extract_code(comp.text, ctx)

    @staticmethod
    def _extract_code(text: str, ctx: Context) -> str:
        m = re.search(r"```(?:cpp|c\+\+)?\s*(.*?)```", text, re.DOTALL | re.I)
        body = (m.group(1) if m else text).strip()
        if "class Solution" not in body:
            return ""
        if "#include" not in body:
            body = "#include <bits/stdc++.h>\nusing namespace std;\n\n" + body
        link = ""
        first = ctx.paths.solution.read_text(encoding="utf-8", errors="replace").splitlines()
        if first and first[0].startswith("// Link:"):
            link = first[0] + "\n\n"
        header = ("// Suggested improvement, generated by lcagent's improver agent.\n"
                  "// Review before adopting — this is a suggestion, not your work.\n")
        return link + header + body.rstrip() + "\n"

    # ── verification against the real driver ──
    def _verify(self, ctx: Context, candidate) -> tuple[int, int, str]:
        """Compile the candidate against this problem's driver and diff outputs."""
        if not (ctx.paths.driver.is_file() and ctx.paths.input.is_file()
                and ctx.paths.expected.is_file()):
            return 0, 0, "no driver/test files to verify against"

        stage = paths.build_dir() / f"impstage_{ctx.pid}"
        try:
            shutil.rmtree(stage, ignore_errors=True)
            stage.mkdir(parents=True, exist_ok=True)
            shutil.copy2(candidate, stage / f"{ctx.pid}.cpp")
            shutil.copy2(ctx.paths.driver, stage / f"{ctx.pid}_driver.cpp")
            comp = compile_cpp(stage / f"{ctx.pid}_driver.cpp", f"impbin_{ctx.pid}")
            if not comp.ok:
                return 0, 0, "does not compile: " + comp.first_error(3).replace("\n", " ")[:160]

            run = run_binary(comp.binary,
                             ctx.paths.input.read_text(encoding="utf-8", errors="replace"),
                             timeout=15.0)
            if run.timed_out:
                return 0, 0, "timed out"
            if run.exit_code != 0:
                return 0, 0, f"runtime error (exit {run.exit_code})"

            exp = ctx.paths.expected.read_text(encoding="utf-8", errors="replace").splitlines()
            got = run.stdout_lines()
            passed = sum(1 for i, e in enumerate(exp)
                         if i < len(got) and got[i].strip() == e.strip())
            return passed, len(exp), "" if passed == len(exp) else f"{passed}/{len(exp)} cases"
        except OSError as e:
            return 0, 0, f"verification error: {e}"
        finally:
            shutil.rmtree(stage, ignore_errors=True)
