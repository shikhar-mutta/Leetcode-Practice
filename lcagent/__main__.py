#!/usr/bin/env python3
"""
Entry point: `python -m lcagent` for the loop, `python -m lcagent run 2859`
for a single command. Identical on Windows and Linux.
"""

from __future__ import annotations

import sys
from pathlib import Path

# Allow `python lcagent/__main__.py` as well as `python -m lcagent`.
if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

from lcagent.agents.master import MasterAgent  # noqa: E402
from lcagent.core import ui  # noqa: E402


def main(argv: list[str] | None = None) -> int:
    argv = sys.argv[1:] if argv is None else argv
    # Setup runs before anything else is imported, so it can still report a
    # missing dependency that would otherwise crash the import itself.
    if argv and argv[0] in ("setup", "doctor", "install"):
        from lcagent.bootstrap import main as setup_main
        return setup_main(argv[1:] if argv[0] != "doctor" else ["--check", *argv[1:]])
    master = MasterAgent()
    if argv:
        return master.one_shot(argv)
    try:
        master.loop()
    except KeyboardInterrupt:
        print("\n" + ui.dim("interrupted."))
        return 130
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
