#!/usr/bin/env python3
"""
ScorerAgent — grade a submitted solution and say whether a better one exists.

Split so it is useful with no model at all:

  deterministic  correctness (from the verifier) and efficiency (the solution
                 benchmarked head-to-head against the archived reference)
  model-judged   complexity against the optimal approach, readability, and the
                 "is there a better approach" verdict

With no provider configured the model-judged weight is redistributed onto the
deterministic components and the card says so, rather than inventing numbers.
"""

from __future__ import annotations

import json
import re
import shutil
from dataclasses import asdict, dataclass, field

from ..core import paths, ui
from ..core.compiler import compile_cpp
from ..core.runner import run_binary
from ..core.state import Context
from ..core.testcase import Status
from ..providers import ProviderError, get_provider, load_config
from .base import Agent, AgentResult

#: Below this, process startup dominates and a runtime comparison is noise.
NOISE_FLOOR_MS = 8.0
BENCH_REPEATS = 5


@dataclass
class Component:
    name: str
    points: float
    max_points: float
    note: str = ""
    judged_by: str = "measured"


@dataclass
class ScoreCard:
    pid: str
    total: float = 0.0
    grade: str = "—"
    components: list[Component] = field(default_factory=list)
    verdict: str = ""
    better: dict | None = None
    model: str | None = None
    degraded: bool = False

    def as_dict(self) -> dict:
        d = asdict(self)
        d["components"] = [asdict(c) for c in self.components]
        return d


def _grade(total: float) -> str:
    for cutoff, letter in ((90, "A"), (80, "B"), (70, "C"), (60, "D")):
        if total >= cutoff:
            return letter
    return "F"


class ScorerAgent(Agent):
    name = "scorer"
    role = "Score a solution and report whether a better approach exists"
    requires_llm = False          # degrades; the model only enriches

    def run(self, ctx: Context, **_) -> AgentResult:
        if ctx.report is None:
            return self.fail("nothing verified yet — `run` first")

        weights = (load_config().get("scoring") or
                   {"correctness": 50, "complexity": 25, "efficiency": 15, "readability": 10})
        card = ScoreCard(pid=ctx.pid)

        # ── deterministic: correctness ──
        rep = ctx.report
        frac = (rep.passed / rep.total) if rep.total else 0.0
        if rep.status in (Status.COMPILE_ERROR, Status.MISSING_FILES):
            frac, note = 0.0, rep.status.value.replace("_", " ").lower()
        elif rep.status is Status.TIMEOUT:
            frac, note = 0.0, "timed out"
        elif rep.status is Status.RUNTIME_ERROR:
            frac, note = 0.0, "runtime error"
        else:
            note = f"{rep.passed}/{rep.total} test cases"
        card.components.append(
            Component("correctness", round(frac * weights["correctness"], 1),
                      weights["correctness"], note))

        # ── deterministic: efficiency vs the archived reference ──
        card.components.append(self._efficiency(ctx, weights["efficiency"]))

        # ── model-judged: complexity, readability, better-approach verdict ──
        provider = get_provider()
        usable, why = provider.available()
        if usable and rep.all_passed:
            try:
                self._judge(ctx, card, weights, provider)
            except ProviderError as e:
                card.degraded = True
                card.verdict = f"model review unavailable ({e})"
        else:
            card.degraded = True
            card.verdict = ("model review skipped — solve the problem first"
                            if usable else f"model review unavailable — {why}")

        if card.degraded:
            self._redistribute(card, weights)

        card.total = round(sum(c.points for c in card.components), 1)
        card.grade = _grade(card.total)
        ctx.score = card.as_dict()

        out = paths.scores_dir() / f"{ctx.pid}_score.json"
        out.write_text(json.dumps(card.as_dict(), indent=2), encoding="utf-8")

        ctx.note(self.name, f"scored {card.total}/100 ({card.grade})")
        return self.ok(f"{card.total}/100  grade {card.grade}",
                       artifacts=[out], card=card.as_dict())

    # ── components ──
    def _efficiency(self, ctx: Context, max_points: float) -> Component:
        """Benchmark this solution against the archived reference on the same input."""
        rep = ctx.report
        if rep is None or not rep.all_passed or rep.compile_result is None:
            return Component("efficiency", 0.0, max_points, "not measured (tests not passing)")

        mine = self._bench(rep.compile_result.binary, ctx)
        ref_ms = self._bench_reference(ctx)

        if mine is None:
            return Component("efficiency", 0.0, max_points, "could not measure")
        if ref_ms is None:
            return Component("efficiency", round(max_points * 0.7, 1), max_points,
                             f"{mine:.1f} ms — no reference to compare against")
        if mine < NOISE_FLOOR_MS and ref_ms < NOISE_FLOOR_MS:
            return Component("efficiency", max_points, max_points,
                             f"{mine:.1f} ms vs {ref_ms:.1f} ms reference — "
                             f"both below the {NOISE_FLOOR_MS:.0f} ms noise floor, "
                             f"example tests are too small to differentiate")

        ratio = ref_ms / mine if mine else 1.0          # >1 means faster than reference
        pts = max(0.0, min(1.0, 0.5 + 0.5 * min(ratio, 2.0) - 0.25)) * max_points
        return Component("efficiency", round(pts, 1), max_points,
                         f"{mine:.1f} ms vs {ref_ms:.1f} ms reference")

    def _bench(self, binary, ctx: Context) -> float | None:
        if binary is None or not binary.is_file():
            return None
        stdin_text = ctx.paths.input.read_text(encoding="utf-8", errors="replace")
        times = []
        for _ in range(BENCH_REPEATS):
            r = run_binary(binary, stdin_text, timeout=20.0)
            if not r.ok:
                return None
            times.append(r.elapsed_ms)
        return min(times)

    def _bench_reference(self, ctx: Context) -> float | None:
        """
        Build the archived reference against this problem's driver.

        The driver `#include`s "<id>.cpp", so the reference is staged under that
        name in a scratch directory and compiled there.
        """
        ref = ctx.paths.reference
        if not ref.is_file() or not ctx.paths.driver.is_file():
            return None
        stage = paths.build_dir() / f"refstage_{ctx.pid}"
        try:
            stage.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ref, stage / f"{ctx.pid}.cpp")
            shutil.copy2(ctx.paths.driver, stage / f"{ctx.pid}_driver.cpp")
            # distinct from the stage directory name, or the linker overwrites it
            comp = compile_cpp(stage / f"{ctx.pid}_driver.cpp", f"refbin_{ctx.pid}")
            if not comp.ok:
                return None
            return self._bench(comp.binary, ctx)
        except OSError:
            return None
        finally:
            shutil.rmtree(stage, ignore_errors=True)

    def _redistribute(self, card: ScoreCard, weights: dict) -> None:
        """Scale measured components up to 100 so a degraded card is still out of 100."""
        measured = sum(c.max_points for c in card.components)
        if measured <= 0:
            return
        factor = 100.0 / measured
        for c in card.components:
            c.points = round(c.points * factor, 1)
            c.max_points = round(c.max_points * factor, 1)

    # ── model review ──
    def _judge(self, ctx: Context, card: ScoreCard, weights: dict, provider) -> None:
        solution = ctx.paths.solution.read_text(encoding="utf-8", errors="replace")
        statement = ctx.paths.problem.read_text(encoding="utf-8", errors="replace")[:4000] \
            if ctx.paths.problem.is_file() else ""
        reference = ctx.paths.reference.read_text(encoding="utf-8", errors="replace")[:3000] \
            if ctx.paths.reference.is_file() else ""

        system = (
            "You review competitive-programming C++ solutions. "
            "Be exact about complexity and honest when a solution is already optimal — "
            "do not invent an improvement that does not exist. "
            "Reply with a single JSON object and nothing else."
        )
        prompt = f"""{statement}

=== SUBMITTED SOLUTION ===
{solution}
""" + (f"""
=== A KNOWN REFERENCE SOLUTION (for comparison only) ===
{reference}
""" if reference else "") + f"""
Return JSON with exactly these keys:
{{
  "time_complexity":  "O(...) of the submitted solution",
  "space_complexity": "O(...) of the submitted solution",
  "optimal_time":     "O(...) achievable for this problem",
  "complexity_score": <0-{weights['complexity']}, full marks if already optimal>,
  "readability_score": <0-{weights['readability']}>,
  "readability_note": "one short sentence",
  "better_exists":    true or false,
  "better_approach":  "name of the better approach, or null",
  "better_time":      "O(...) or null",
  "better_why":       "one or two sentences on why it wins, or null",
  "verdict":          "one sentence overall"
}}"""

        comp = provider.complete(system, prompt, tier="smart", max_tokens=4000)
        data = self._parse_json(comp.text)
        if data is None:
            raise ProviderError("model did not return usable JSON")

        card.model = comp.model
        cx = float(data.get("complexity_score") or 0)
        rd = float(data.get("readability_score") or 0)
        card.components.append(Component(
            "complexity", round(min(cx, weights["complexity"]), 1), weights["complexity"],
            f"{data.get('time_complexity','?')} time, {data.get('space_complexity','?')} space "
            f"(optimal {data.get('optimal_time','?')})", judged_by=comp.model))
        card.components.append(Component(
            "readability", round(min(rd, weights["readability"]), 1), weights["readability"],
            str(data.get("readability_note", "")), judged_by=comp.model))

        card.verdict = str(data.get("verdict", ""))
        if data.get("better_exists"):
            card.better = {
                "approach": data.get("better_approach"),
                "time": data.get("better_time"),
                "why": data.get("better_why"),
            }

    @staticmethod
    def _parse_json(text: str) -> dict | None:
        text = text.strip()
        fence = re.search(r"```(?:json)?\s*(.*?)```", text, re.DOTALL)
        if fence:
            text = fence.group(1).strip()
        start, end = text.find("{"), text.rfind("}")
        if start == -1 or end <= start:
            return None
        try:
            return json.loads(text[start:end + 1])
        except json.JSONDecodeError:
            return None


# ─── terminal rendering ──────────────────────────────────────────────────────

def render(card: ScoreCard | dict) -> str:
    d = card if isinstance(card, dict) else card.as_dict()
    colour = {"A": ui.green, "B": ui.green, "C": ui.yellow, "D": ui.yellow, "F": ui.red}
    tint = colour.get(d["grade"], ui.dim)

    headline = tint(ui.bold(f"{d['total']:.0f}/100"))
    out = [ui.banner(f"score — problem {d['pid']}"),
           f"  {headline}   grade {tint(ui.bold(d['grade']))}",
           ""]
    for c in d["components"]:
        bar_w = 18
        filled = int(round(bar_w * (c["points"] / c["max_points"]))) if c["max_points"] else 0
        bar = "█" * filled + ui.dim("·" * (bar_w - filled))
        out.append(f"  {c['name']:<12} {bar} {c['points']:>5.1f}/{c['max_points']:<5.1f} "
                   + ui.dim(c["note"]))
    out.append("")
    if d.get("verdict"):
        out.append("  " + d["verdict"])
    if d.get("better"):
        b = d["better"]
        out.append("")
        out.append("  " + ui.yellow(ui.bold("better solution exists")))
        out.append(f"    approach : {b.get('approach')}")
        if b.get("time"):
            out.append(f"    time     : {b.get('time')}")
        if b.get("why"):
            out.append(f"    why      : {b.get('why')}")
    elif not d.get("degraded"):
        out.append("  " + ui.green("no better approach found — this is optimal"))
    if d.get("model"):
        out.append("")
        out.append(ui.dim(f"  reviewed by {d['model']}"))
    return "\n".join(out)
