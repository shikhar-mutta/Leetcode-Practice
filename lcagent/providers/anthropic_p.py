#!/usr/bin/env python3
"""
Anthropic API backend — pay-per-token, no subscription.

Two tiers are routed to different models: the cheap one handles classification
and note-writing, the capable one handles C++ generation and review. Agents ask
for a tier, never a model id.
"""

from __future__ import annotations

import os

from .base import Completion, Provider, ProviderError

DEFAULT_MODELS = {
    "fast": "claude-haiku-4-5-20251001",
    "smart": "claude-sonnet-5",
}


class AnthropicProvider(Provider):
    name = "anthropic"

    def __init__(self, models: dict | None = None, api_key: str | None = None):
        self.models = {**DEFAULT_MODELS, **(models or {})}
        self.api_key = api_key or os.environ.get("ANTHROPIC_API_KEY", "")
        self._client = None

    def _get_client(self):
        if self._client is None:
            try:
                import anthropic
            except ImportError as e:
                raise ProviderError("the `anthropic` package is not installed") from e
            if not self.api_key:
                raise ProviderError("ANTHROPIC_API_KEY is not set")
            self._client = anthropic.Anthropic(api_key=self.api_key)
        return self._client

    def available(self) -> tuple[bool, str]:
        try:
            import anthropic  # noqa: F401
        except ImportError:
            return False, "`pip install anthropic`"
        if not self.api_key:
            return False, "ANTHROPIC_API_KEY is not set (get one at console.anthropic.com)"
        return True, f"anthropic — fast={self.models['fast']}, smart={self.models['smart']}"

    def complete(self, system: str, prompt: str, *, tier: str = "smart",
                 max_tokens: int = 2000, temperature: float = 0.0) -> Completion:
        client = self._get_client()
        model = self.models.get(tier, self.models["smart"])
        try:
            msg = client.messages.create(
                model=model,
                max_tokens=max_tokens,
                temperature=temperature,
                system=system,
                messages=[{"role": "user", "content": prompt}],
            )
        except Exception as e:  # noqa: BLE001 — surface every backend failure uniformly
            raise ProviderError(f"{type(e).__name__}: {e}") from e

        text = "".join(b.text for b in msg.content if getattr(b, "type", "") == "text")
        return Completion(
            text=text,
            model=model,
            input_tokens=getattr(msg.usage, "input_tokens", 0),
            output_tokens=getattr(msg.usage, "output_tokens", 0),
        )
