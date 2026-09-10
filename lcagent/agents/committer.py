#!/usr/bin/env python3
"""
CommitterAgent — commit the solved problem in the repo's own convention.

The history is a flat run of `U1`, `U2`, … `U12`, one commit per problem, so
the next number is derived from the log rather than guessed. Commits are always
opt-in: nothing here runs without being asked for.
"""

from __future__ import annotations

import re
import subprocess

from ..core import paths
from ..core.state import Context
from .base import Agent, AgentResult

U_RE = re.compile(r"^U(\d+)$")


class CommitterAgent(Agent):
    name = "committer"
    role = "Stage and commit the solved problem as the next U<n>"
    requires_llm = False

    def run(self, ctx: Context, *, message: str | None = None,
            require_pass: bool = True, dry_run: bool = False, **_) -> AgentResult:
        if require_pass and not (ctx.report and ctx.report.all_passed):
            return self.fail("tests are not passing — refusing to commit")

        root = paths.repo_root()
        status = self._git(root, "status", "--porcelain")
        if status.returncode != 0:
            return self.fail(f"git: {status.stderr.strip()}")
        if not status.stdout.strip():
            return self.ok("nothing to commit — the working tree is clean", committed=False)

        msg = message or f"U{self._next_number(root)}"
        changed = [l[3:] for l in status.stdout.splitlines()][:12]
        if dry_run:
            return self.ok(f"would commit {len(status.stdout.splitlines())} path(s) as {msg!r}",
                           committed=False, commit_message=msg, files=changed)

        add = self._git(root, "add", "-A")
        if add.returncode != 0:
            return self.fail(f"git add: {add.stderr.strip()}")
        com = self._git(root, "commit", "-m", msg)
        if com.returncode != 0:
            return self.fail(f"git commit: {(com.stderr or com.stdout).strip()[:300]}")

        sha = self._git(root, "rev-parse", "--short", "HEAD").stdout.strip()
        ctx.note(self.name, f"committed {sha} {msg}")
        return self.ok(f"committed {sha} as {msg}", committed=True,
                       commit_message=msg, sha=sha, files=changed)

    def _next_number(self, root) -> int:
        """
        One past the U number on the most recent U commit.

        Not the global maximum: this history reuses numbers (21 commits are
        titled `U11`, spread over a week, and numbers above the current head
        exist further back). The most recent one is what the convention is
        actually following — U12 → U13 → U14 — so the next is derived from
        that. The proposed message is always shown before anything is
        committed, and `-m` overrides it.
        """
        log = self._git(root, "log", "--format=%s", "-500")
        for line in log.stdout.splitlines():
            m = U_RE.match(line.strip())
            if m:
                return int(m.group(1)) + 1      # first match = most recent
        return 1

    @staticmethod
    def _git(root, *args) -> subprocess.CompletedProcess:
        return subprocess.run(["git", *args], cwd=str(root), capture_output=True,
                              text=True, errors="replace", timeout=60)
