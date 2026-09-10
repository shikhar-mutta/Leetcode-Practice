#!/usr/bin/env python3
"""
OpenAI-compatible backend — the free-tier route.

Groq, Google Gemini, OpenRouter and Cerebras all expose the same
`/chat/completions` wire format, so one implementation covers every free tier
worth using. Each is selected by a preset name that carries its base URL and
the environment variable holding its (free) key.

urllib is used rather than the `openai` package so there is nothing to install.

Model ids on free tiers change often. They are config-driven rather than
hardcoded, and `list_models()` asks the endpoint what it actually serves —
never trust a model name baked into source that may be months stale.
"""

from __future__ import annotations

import json
import os
import urllib.error
import urllib.request

from .base import Completion, Provider, ProviderError

#: Reasoning models need room to think before they emit content at all.
MIN_REASONING_BUDGET = 1500

_USER_AGENT = ("Mozilla/5.0 (X11; Linux x86_64; rv:120.0) "
               "Gecko/20100101 Firefox/120.0")

#: base_url, key env var, and starting model guesses per free provider.
PRESETS: dict[str, dict] = {
    "groq": {
        "base_url": "https://api.groq.com/openai/v1",
        "env": "GROQ_API_KEY",
        "signup": "https://console.groq.com/keys  (free, no card)",
        "reasoning_effort": "low",
        "models": {"fast": "openai/gpt-oss-20b", "smart": "openai/gpt-oss-120b"},
    },
    "gemini": {
        "base_url": "https://generativelanguage.googleapis.com/v1beta/openai",
        "env": "GEMINI_API_KEY",
        "signup": "https://aistudio.google.com/apikey  (free, no card)",
        "models": {"fast": "gemini-2.0-flash", "smart": "gemini-2.5-flash"},
    },
    "openrouter": {
        "base_url": "https://openrouter.ai/api/v1",
        "env": "OPENROUTER_API_KEY",
        "signup": "https://openrouter.ai/keys  (has :free models)",
        "models": {"fast": "qwen/qwen-2.5-coder-32b-instruct:free",
                   "smart": "qwen/qwen-2.5-coder-32b-instruct:free"},
    },
    "cerebras": {
        "base_url": "https://api.cerebras.ai/v1",
        "env": "CEREBRAS_API_KEY",
        "signup": "https://cloud.cerebras.ai  (free tier)",
        "models": {"fast": "llama3.1-8b", "smart": "llama-3.3-70b"},
    },
}


class OpenAICompatProvider(Provider):
    name = "openai_compat"

    def __init__(self, preset: str = "groq", models: dict | None = None,
                 base_url: str | None = None, api_key: str | None = None,
                 env_var: str | None = None, reasoning_effort: str | None = None):
        self.preset = preset
        spec = PRESETS.get(preset, {})
        self.base_url = (base_url or spec.get("base_url") or "").rstrip("/")
        self.env_var = env_var or spec.get("env") or "OPENAI_API_KEY"
        self.signup = spec.get("signup", "")
        self.models = {**(spec.get("models") or {}), **(models or {})}
        self.api_key = api_key or os.environ.get(self.env_var, "")
        # Reasoning models (gpt-oss, qwen3) spend most of their completion
        # budget thinking before emitting a token of content. "low" keeps that
        # affordable on a rate-limited free tier; the endpoint ignores the
        # field for non-reasoning models.
        self.reasoning_effort = reasoning_effort or spec.get("reasoning_effort")
        self._last_limits: dict = {}
        self.name = preset

    # ── transport ──
    def _request(self, path: str, payload: dict | None = None, timeout: float = 180.0) -> dict:
        url = f"{self.base_url}{path}"
        data = json.dumps(payload).encode() if payload is not None else None
        req = urllib.request.Request(
            url, data=data,
            headers={"Authorization": f"Bearer {self.api_key}",
                     "Content-Type": "application/json",
                     # Several of these endpoints sit behind Cloudflare, which
                     # rejects the default Python-urllib agent with a 403/1010.
                     "User-Agent": _USER_AGENT,
                     "Accept": "application/json"},
            method="POST" if data is not None else "GET",
        )
        try:
            with urllib.request.urlopen(req, timeout=timeout) as r:
                self._last_limits = {
                    k.replace("x-ratelimit-", ""): v
                    for k, v in r.headers.items() if k.lower().startswith("x-ratelimit-")
                }
                return json.loads(r.read().decode("utf-8", "replace"))
        except urllib.error.HTTPError as e:
            body = e.read().decode("utf-8", "replace")[:400]
            if e.code == 429:
                # Free tiers meter tokens per minute. Surface the wait plainly:
                # the agents treat this as "no model right now" and fall back to
                # their deterministic half rather than failing the whole command.
                retry = e.headers.get("retry-after") or ""
                left = e.headers.get("x-ratelimit-remaining-tokens")
                detail = f" — retry in {retry}s" if retry else ""
                if left is not None:
                    detail += f" ({left} tokens left this window)"
                raise ProviderError(f"{self.preset} rate limit reached{detail}") from e
            if e.code in (401, 403):
                raise ProviderError(f"{self.preset} rejected the key "
                                    f"(HTTP {e.code}) — check {self.env_var}") from e
            raise ProviderError(f"{self.preset} HTTP {e.code}: {body}") from e
        except (urllib.error.URLError, OSError, TimeoutError, json.JSONDecodeError) as e:
            raise ProviderError(f"{self.preset}: {e}") from e

    # ── contract ──
    def available(self) -> tuple[bool, str]:
        if not self.base_url:
            return False, f"unknown preset {self.preset!r} (one of {', '.join(PRESETS)})"
        if not self.api_key:
            hint = f" — get one free at {self.signup}" if self.signup else ""
            return False, f"{self.env_var} is not set{hint}"
        return True, (f"{self.preset} (free tier) — "
                      f"fast={self.models.get('fast')}, smart={self.models.get('smart')}")

    def budget(self) -> dict:
        """Live rate-limit budget from the last response headers, if any."""
        return dict(self._last_limits)

    def list_models(self) -> list[str]:
        """Ask the endpoint what it serves — free-tier catalogues change often."""
        try:
            d = self._request("/models", None, timeout=30.0)
        except ProviderError:
            return []
        return sorted(m.get("id", "") for m in d.get("data", []) if m.get("id"))

    def complete(self, system: str, prompt: str, *, tier: str = "smart",
                 max_tokens: int = 2000, temperature: float = 0.0) -> Completion:
        if not self.api_key:
            raise ProviderError(self.available()[1])
        model = self.models.get(tier) or self.models.get("smart") or ""
        payload = {
            "model": model,
            # Reasoning tokens come out of this same budget, so a request that
            # looks generous for the answer alone can be entirely consumed
            # before any content is produced.
            "max_tokens": max(max_tokens, MIN_REASONING_BUDGET),
            "temperature": temperature,
            "messages": [
                {"role": "system", "content": system},
                {"role": "user", "content": prompt},
            ],
        }
        if self.reasoning_effort:
            payload["reasoning_effort"] = self.reasoning_effort

        d = self._request("/chat/completions", payload)
        try:
            choice = d["choices"][0]
            text = (choice.get("message") or {}).get("content") or ""
        except (KeyError, IndexError, TypeError) as e:
            raise ProviderError(f"{self.preset}: unexpected response shape: "
                                f"{json.dumps(d)[:300]}") from e

        if not text.strip():
            # Never hand back a silent empty string: an agent would read it as
            # a valid-but-useless answer instead of a failure it can retry.
            finish = choice.get("finish_reason")
            spent = ((d.get("usage") or {}).get("completion_tokens_details") or {}) \
                .get("reasoning_tokens")
            if finish == "length":
                raise ProviderError(
                    f"{self.preset}/{model}: truncated before producing content "
                    f"({spent} reasoning tokens used of a {payload['max_tokens']} budget) "
                    f"— raise max_tokens or lower reasoning_effort")
            raise ProviderError(f"{self.preset}/{model}: empty response "
                                f"(finish_reason={finish})")
        usage = d.get("usage") or {}
        return Completion(
            text=text,
            model=d.get("model", model),
            input_tokens=usage.get("prompt_tokens", 0),
            output_tokens=usage.get("completion_tokens", 0),
        )
