#!/usr/bin/env python3
"""
Every path the agent system touches resolves through this module.

Nothing else builds a path by hand: the repo lives under "Sem 2/Coding
Practice/...", so naive string joins break on the spaces, and Windows needs
backslash separators that only pathlib gets right for free.
"""

from __future__ import annotations

import os
import tempfile
from pathlib import Path

# ─── repo root ───────────────────────────────────────────────────────────────

# Files that only ever coexist at the practice-repo root.
_ROOT_MARKERS = ("run.sh", "fetch_problem.py", "All Codes")

_cached_root: Path | None = None


def find_repo_root(start: Path | None = None) -> Path:
    """Walk upward from `start` until every root marker is present."""
    here = (start or Path(__file__)).resolve()
    for cand in (here, *here.parents):
        if cand.is_dir() and all((cand / m).exists() for m in _ROOT_MARKERS):
            return cand
    raise FileNotFoundError(
        "Could not locate the Leetcode-Practice root (looked for "
        + ", ".join(_ROOT_MARKERS)
        + f" walking up from {here}). Set LCAGENT_ROOT to override."
    )


def repo_root() -> Path:
    """Cached repo root. LCAGENT_ROOT overrides discovery."""
    global _cached_root
    if _cached_root is None:
        override = os.environ.get("LCAGENT_ROOT")
        _cached_root = Path(override).resolve() if override else find_repo_root()
    return _cached_root


# ─── well-known locations ────────────────────────────────────────────────────

def code_dirs() -> Path:
    """Per-problem scaffold archive: <id>/{<id>.cpp,_driver.cpp,_input,_expected}."""
    return repo_root() / "Code Dirs" / "All LC 1 - 4017"


def all_codes() -> Path:
    """Flat solution archive: <id>.cpp. Doubles as the reference corpus."""
    return repo_root() / "All Codes" / "All LC 1 - 4017"


def tracker_xlsx() -> Path:
    return repo_root() / "LC Tracker.xlsx"


def notes_dir() -> Path:
    return repo_root() / "All Codes" / "Notes"


def formula_file() -> Path:
    return repo_root() / "All Codes" / "Math formula" / "formula.txt"


def build_dir() -> Path:
    """
    Scratch space for compiled binaries.

    Deliberately outside the repo: run.sh drops ./sol_<N> at the root and only
    removes it on the happy path, which is how a stale `sol_18` ended up
    committed. Nothing we produce can land in the working tree.
    """
    d = Path(tempfile.gettempdir()) / "lcagent_build"
    d.mkdir(parents=True, exist_ok=True)
    return d


EXE_SUFFIX = ".exe" if os.name == "nt" else ""


# ─── agent data root ─────────────────────────────────────────────────────────
# Everything the agents produce lives under one folder, never scattered across
# the practice repo: cached API responses, rendered problem files, score cards,
# session state and logs.

def agent_data_dir() -> Path:
    """Root for all agent-produced data: <repo>/lcagent/data."""
    d = Path(__file__).resolve().parent.parent / "data"
    d.mkdir(parents=True, exist_ok=True)
    return d


def _sub(name: str) -> Path:
    d = agent_data_dir() / name
    d.mkdir(parents=True, exist_ok=True)
    return d


def cache_dir() -> Path:
    """Cached LeetCode GraphQL responses, one JSON per problem."""
    return _sub("cache")


def problems_dir() -> Path:
    """Rendered <id>_problem.txt statement files."""
    return _sub("problems")


def scores_dir() -> Path:
    """Score cards written by the scoring agent."""
    return _sub("scores")


def logs_dir() -> Path:
    """Master-loop session logs."""
    return _sub("logs")


def session_file() -> Path:
    """Master-loop state, so a restart resumes on the same problem."""
    return agent_data_dir() / "session.json"


# ─── one problem's files ─────────────────────────────────────────────────────

class ProblemPaths:
    """
    The files that make up a single problem sitting at the repo root.

    `<id>_problem.txt` is new in this system; the other five are what
    fetch_problem.py already generates.
    """

    def __init__(self, pid: int | str, root: Path | None = None):
        self.pid = str(pid)
        self.root = root or repo_root()

    def _f(self, suffix: str) -> Path:
        return self.root / f"{self.pid}{suffix}"

    @property
    def solution(self) -> Path:
        return self._f(".cpp")

    @property
    def driver(self) -> Path:
        return self._f("_driver.cpp")

    @property
    def input(self) -> Path:
        return self._f("_input.txt")

    @property
    def expected(self) -> Path:
        return self._f("_expected.txt")

    @property
    def debug(self) -> Path:
        return self._f("_debug.txt")

    @property
    def problem(self) -> Path:
        """
        The question file, written at fetch time beside the code it describes.

        Unlike caches and score cards this is not a by-product — it is part of
        the problem scaffold, read while solving, and swapped out with the rest
        of the files when a new problem is fetched.
        """
        return self._f("_problem.txt")

    # ── archive counterparts ──
    @property
    def archive_dir(self) -> Path:
        return code_dirs() / self.pid

    @property
    def reference(self) -> Path:
        """The bulk-imported reference solution, when one exists."""
        return all_codes() / f"{self.pid}.cpp"

    # ── helpers ──
    def compile_target(self) -> Path | None:
        """
        The translation unit to hand g++.

        Mirrors run.sh: prefer `<id>_*.cpp` (the driver, which #includes the
        solution) over a bare `<id>.cpp`. Returns None when neither exists.
        """
        matches = sorted(self.root.glob(f"{self.pid}_*.cpp"))
        if matches:
            return matches[0]
        return self.solution if self.solution.is_file() else None

    def missing(self, *required: str) -> list[Path]:
        """Which of the named attributes point at files that aren't there."""
        names = required or ("input", "expected")
        return [p for p in (getattr(self, n) for n in names) if not p.is_file()]

    def __repr__(self) -> str:
        return f"ProblemPaths(pid={self.pid!r}, root={str(self.root)!r})"
