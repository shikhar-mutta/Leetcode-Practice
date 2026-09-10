#!/usr/bin/env python3
"""
The contract every specialist agent implements.

`requires_llm` is the important field: it splits the roster into agents that
always work — offline, free, no key — and agents that need a configured model
provider. The master loop uses it to degrade gracefully instead of failing when
no provider is set up.
"""

from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from pathlib import Path
from typing import ClassVar

from ..core.state import Context


@dataclass
class AgentResult:
    agent: str
    ok: bool
    message: str = ""
    data: dict = field(default_factory=dict)
    artifacts: list[Path] = field(default_factory=list)

    def __bool__(self) -> bool:
        return self.ok


class Agent(ABC):
    name: ClassVar[str] = "agent"
    role: ClassVar[str] = ""
    requires_llm: ClassVar[bool] = False

    @abstractmethod
    def run(self, ctx: Context, **kwargs) -> AgentResult:
        """Do this agent's one job, enriching `ctx` in place."""

    # ── result helpers ──
    def ok(self, message: str, **data) -> AgentResult:
        artifacts = data.pop("artifacts", [])
        return AgentResult(self.name, True, message, data, artifacts)

    def fail(self, message: str, **data) -> AgentResult:
        return AgentResult(self.name, False, message, data)

    def __repr__(self) -> str:
        return f"<{type(self).__name__} name={self.name!r}>"
