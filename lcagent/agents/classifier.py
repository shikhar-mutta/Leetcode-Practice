#!/usr/bin/env python3
"""
ClassifierAgent — pick the tracker topic for a problem.

Constrained to the vocabulary already in LC Tracker.xlsx rather than free text.
The sheet holds 95 distinct topics with a 59-item long tail of one-offs; letting
a model invent another spelling of "Binary Search" would make the topic column
useless for the reporting agent. It picks from what is already there, and only
falls back to the LeetCode tag when nothing fits.
"""

from __future__ import annotations

from ..core import tracker_io
from ..core.state import Context
from ..providers import ProviderError, get_provider
from .base import Agent, AgentResult


class ClassifierAgent(Agent):
    name = "classifier"
    role = "Choose the tracker topic, reusing the vocabulary already in the sheet"
    requires_llm = False          # degrades to the LeetCode tag

    def run(self, ctx: Context, **_) -> AgentResult:
        try:
            known = tracker_io.vocabulary(minimum=2)
        except tracker_io.MissingDependency:
            known = []          # no sheet to read: fall through to the tag path

        tags = (ctx.problem or {}).get("tags") or []

        provider = get_provider()
        usable, _ = provider.available()
        if usable:
            try:
                topic = self._ask(ctx, known, tags, provider)
                if topic:
                    ctx.topic = topic
                    ctx.note(self.name, f"topic: {topic}")
                    return self.ok(topic, topic=topic, source="model")
            except ProviderError:
                pass          # fall through to the deterministic path

        topic = self._from_tags(tags, known)
        if not topic:
            return self.fail("could not determine a topic (no tags, no model)")
        ctx.topic = topic
        ctx.note(self.name, f"topic: {topic} (from tags)")
        return self.ok(topic, topic=topic, source="tags")

    def _ask(self, ctx: Context, known: list[str], tags: list[str], provider) -> str:
        statement = (ctx.paths.problem.read_text(encoding="utf-8", errors="replace")[:1200]
                     if ctx.paths.problem.is_file() else "")
        system = ("You label LeetCode problems with a single topic, chosen from a fixed list. "
                  "Reply with the label only — no punctuation, no explanation.")
        prompt = f"""{statement}

LeetCode tags: {', '.join(tags) or 'none'}

Choose exactly one label from this list:
{chr(10).join('  ' + k for k in known)}

Reply with one label from that list, copied exactly."""
        out = provider.complete(system, prompt, tier="fast", max_tokens=1600).text.strip()
        out = out.strip().strip('."\'').splitlines()[-1].strip() if out else ""
        for k in known:                       # exact, then case-insensitive
            if out == k:
                return k
        for k in known:
            if out.lower() == k.lower():
                return k
        return ""

    @staticmethod
    def _from_tags(tags: list[str], known: list[str]) -> str:
        """Map a LeetCode tag onto the sheet's own spelling where one exists."""
        lowered = {k.lower(): k for k in known}
        for t in tags:
            if t.lower() in lowered:
                return lowered[t.lower()]
            squashed = t.replace(" ", "_").lower()
            if squashed in lowered:
                return lowered[squashed]
        return tags[0] if tags else ""
