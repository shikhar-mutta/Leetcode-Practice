#!/usr/bin/env python3
"""
TrackerAgent — mark a problem solved in LC Tracker.xlsx.

The sheet is months of work and the only record of what has been solved, so
every write is preceded by a timestamped backup and neither destroys existing
annotation: a ⭐ is never overwritten with ✅, and an existing topic is kept
unless explicitly replaced.
"""

from __future__ import annotations

from ..core import paths, tracker_io
from ..core.state import Context
from .base import Agent, AgentResult


class TrackerAgent(Agent):
    name = "tracker"
    role = "Mark the problem solved in LC Tracker.xlsx and record its topic"
    requires_llm = False

    def run(self, ctx: Context, *, topic: str | None = None,
            overwrite_topic: bool = False, require_pass: bool = True, **_) -> AgentResult:
        if require_pass and not (ctx.report and ctx.report.all_passed):
            return self.fail("tests are not passing — refusing to mark it solved")

        topic = topic or ctx.topic
        try:
            before, after, bak = tracker_io.mark(ctx.pid, topic,
                                                 overwrite_topic=overwrite_topic)
        except (tracker_io.MissingDependency, ValueError) as e:
            return self.fail(str(e))
        except (OSError, PermissionError) as e:
            return self.fail(f"could not write the tracker ({e}) — "
                             f"is it open in LibreOffice or Excel?")

        col = chr(ord("A") + after.col - 1)
        where = f"{col}{after.row}"
        changes = []
        if not before.solved and after.solved:
            changes.append("marked solved")
        if before.topic != after.topic:
            changes.append(f"topic → {after.topic}")
        elif topic and before.topic and before.topic != topic:
            changes.append(f"kept existing topic {before.topic!r} (--overwrite to replace)")
        if not changes:
            changes.append("already up to date")

        ctx.note(self.name, f"{where}: {', '.join(changes)}")
        return self.ok(f"row {after.row}, block {col} — {', '.join(changes)}",
                       cell=where, topic=after.topic,
                       backup=str(bak.relative_to(paths.repo_root())))
