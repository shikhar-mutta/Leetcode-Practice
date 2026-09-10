#!/usr/bin/env python3
"""
Provider selection: config file, overridden by environment.

Auto-detection deliberately tries **free providers first** and paid last, so a
machine with no key and no server still runs (deterministic agents only) and a
machine with a free key never silently starts spending money.

Resolution order — LCAGENT_PROVIDER, then config.toml's `provider`, then auto.
Selection never raises: an unusable provider degrades to NullProvider.
"""

from __future__ import annotations

import os
from pathlib import Path

from .base import Completion, NullProvider, Provider, ProviderError

try:
    import tomllib
except ModuleNotFoundError:  # pragma: no cover — Python < 3.11
    tomllib = None

__all__ = ["Completion", "Provider", "ProviderError", "NullProvider",
           "get_provider", "load_config", "config_path", "describe_all", "AUTO_ORDER"]

#: Free first, local second, paid last. Never reorder without good reason.
AUTO_ORDER = ("groq", "gemini", "cerebras", "openrouter", "ollama", "anthropic")

_cached: Provider | None = None


def config_path() -> Path:
    return Path(__file__).resolve().parent.parent / "config.toml"


def load_config() -> dict:
    f = config_path()
    if not f.is_file() or tomllib is None:
        return {}
    try:
        return tomllib.loads(f.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {}


def _build(name: str, cfg: dict) -> Provider:
    section = (cfg.get(name) or {})
    models = section.get("models") or {}

    if name == "anthropic":
        from .anthropic_p import AnthropicProvider
        return AnthropicProvider(models=models, api_key=section.get("api_key"))

    if name == "ollama":
        from .ollama_p import OllamaProvider
        return OllamaProvider(models=models, host=section.get("host"))

    from .openai_compat import PRESETS, OpenAICompatProvider
    if name in PRESETS:
        return OpenAICompatProvider(
            preset=name, models=models,
            base_url=section.get("base_url"),
            api_key=section.get("api_key"),
            env_var=section.get("env"),
        )
    return NullProvider()


def get_provider(refresh: bool = False) -> Provider:
    global _cached
    if _cached is not None and not refresh:
        return _cached

    cfg = load_config()
    choice = (os.environ.get("LCAGENT_PROVIDER")
              or (cfg.get("provider") if isinstance(cfg.get("provider"), str) else None)
              or "auto").strip().lower()

    if choice == "auto":
        for candidate in AUTO_ORDER:
            p = _build(candidate, cfg)
            if p.available()[0]:
                _cached = p
                return _cached
        _cached = NullProvider()
        return _cached

    _cached = _build(choice, cfg) if choice != "none" else NullProvider()
    return _cached


def describe_all() -> list[tuple[str, bool, str]]:
    """(name, usable, reason) for every provider — powers the `provider` command."""
    cfg = load_config()
    out = []
    for name in AUTO_ORDER:
        try:
            usable, why = _build(name, cfg).available()
        except Exception as e:                                  # noqa: BLE001
            usable, why = False, f"{type(e).__name__}: {e}"
        out.append((name, usable, why))
    return out
