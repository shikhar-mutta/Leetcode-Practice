#!/usr/bin/env python3
"""
The provider interface — one method, so backends stay swappable.

Deliberately narrow: agents send a system prompt plus a user prompt and get
text back. No streaming, no tool use, no provider-specific message shapes, so
adding a backend means implementing one method and nothing else changes.
"""

from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass


class ProviderError(RuntimeError):
    """Any backend failure — missing key, network, refusal, bad response."""


@dataclass
class Completion:
    text: str
    model: str
    input_tokens: int = 0
    output_tokens: int = 0

    @property
    def tokens(self) -> int:
        return self.input_tokens + self.output_tokens


class Provider(ABC):
    name: str = "provider"

    #: Logical tiers agents ask for, so no agent hardcodes a model id.
    #: "fast" = cheap and structured (classify, summarise);
    #: "smart" = C++ generation and reasoning.
    TIERS = ("fast", "smart")

    @abstractmethod
    def complete(self, system: str, prompt: str, *, tier: str = "smart",
                 max_tokens: int = 2000, temperature: float = 0.0) -> Completion:
        ...

    @abstractmethod
    def available(self) -> tuple[bool, str]:
        """(usable, reason) — checked before any agent that needs a model runs."""


class NullProvider(Provider):
    """
    Stands in when nothing is configured.

    Every LLM-backed agent asks `available()` first and degrades to its
    deterministic half rather than raising, so the system stays usable with no
    key at all.
    """

    name = "none"

    def complete(self, system, prompt, *, tier="smart", max_tokens=2000, temperature=0.0):
        raise ProviderError("no model provider configured")

    def available(self) -> tuple[bool, str]:
        return False, ("no provider configured — all free options: set GROQ_API_KEY "
                       "(console.groq.com/keys) or GEMINI_API_KEY "
                       "(aistudio.google.com/apikey), or run a local `ollama serve`. "
                       "See `provider` for the full list.")
