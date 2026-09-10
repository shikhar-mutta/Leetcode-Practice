#!/usr/bin/env python3
"""
Ollama backend — fully local, zero cost, no key.

Kept as a real fallback so the system is never locked to one vendor, but not
the default: a 7B-Q4 model needs ~4.5 GB and will not fit a 2 GB laptop GPU,
so it runs on CPU at a few tokens a second — minutes per C++ generation, which
the watch loop cannot absorb. Sensible on a machine with a real GPU.

Uses urllib rather than the ollama package so there is nothing to install.
"""

from __future__ import annotations

import json
import os
import urllib.error
import urllib.request

from .base import Completion, Provider, ProviderError

DEFAULT_HOST = "http://127.0.0.1:11434"
DEFAULT_MODELS = {"fast": "qwen2.5-coder:7b", "smart": "qwen2.5-coder:7b"}


class OllamaProvider(Provider):
    name = "ollama"

    def __init__(self, models: dict | None = None, host: str | None = None):
        self.models = {**DEFAULT_MODELS, **(models or {})}
        self.host = (host or os.environ.get("OLLAMA_HOST") or DEFAULT_HOST).rstrip("/")

    def _get(self, path: str, timeout: float = 5.0):
        with urllib.request.urlopen(f"{self.host}{path}", timeout=timeout) as r:
            return json.loads(r.read().decode("utf-8", "replace"))

    def available(self) -> tuple[bool, str]:
        try:
            tags = self._get("/api/tags")
        except (urllib.error.URLError, OSError, TimeoutError, json.JSONDecodeError):
            return False, f"no Ollama server at {self.host} (`ollama serve`)"
        have = {m.get("name", "").split(":")[0] for m in tags.get("models", [])}
        want = {v.split(":")[0] for v in self.models.values()}
        missing = want - have
        if missing:
            return False, f"model(s) not pulled: {', '.join(sorted(missing))} (`ollama pull ...`)"
        return True, f"ollama at {self.host} — {self.models['smart']}"

    def complete(self, system: str, prompt: str, *, tier: str = "smart",
                 max_tokens: int = 2000, temperature: float = 0.0) -> Completion:
        model = self.models.get(tier, self.models["smart"])
        body = json.dumps({
            "model": model,
            "system": system,
            "prompt": prompt,
            "stream": False,
            "options": {"temperature": temperature, "num_predict": max_tokens},
        }).encode()
        req = urllib.request.Request(
            f"{self.host}/api/generate", data=body,
            headers={"Content-Type": "application/json"},
        )
        try:
            with urllib.request.urlopen(req, timeout=600) as r:
                d = json.loads(r.read().decode("utf-8", "replace"))
        except (urllib.error.URLError, OSError, TimeoutError, json.JSONDecodeError) as e:
            raise ProviderError(f"ollama: {e}") from e
        return Completion(
            text=d.get("response", ""),
            model=model,
            input_tokens=d.get("prompt_eval_count", 0),
            output_tokens=d.get("eval_count", 0),
        )
