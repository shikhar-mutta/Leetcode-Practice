#!/usr/bin/env python3
"""
The blackboard every agent reads from and writes to.

Agents do not talk to each other directly. The master agent owns one Context
per problem, hands it down the pipeline, and each agent enriches it. That keeps
ordering explicit and every run reproducible — the alternative, agents
free-chatting, is far harder to debug and costs a model call per exchange.
"""

from __future__ import annotations

import time
from dataclasses import dataclass, field
from pathlib import Path

from .paths import ProblemPaths
from .testcase import TestReport


@dataclass
class Context:
    """Shared state for work on a single problem."""

    pid: str
    paths: ProblemPaths

    problem: dict | None = None          # LeetCode metadata (leetcode.fetch_question)
    report: TestReport | None = None     # latest verification
    score: dict | None = None            # latest score card
    topic: str | None = None             # classifier's tracker topic

    history: list[str] = field(default_factory=list)
    started: float = field(default_factory=time.time)

    @classmethod
    def for_problem(cls, pid: int | str, root: Path | None = None) -> "Context":
        return cls(pid=str(pid), paths=ProblemPaths(pid, root))

    def note(self, agent: str, message: str) -> None:
        stamp = time.strftime("%H:%M:%S")
        self.history.append(f"[{stamp}] {agent}: {message}")

    @property
    def solved(self) -> bool:
        return self.report is not None and self.report.all_passed
