#!/usr/bin/env python3
"""
Appending to the hand-written notes files, in each file's own format.

These three files are the user's own knowledge base, built up by hand over
hundreds of problems. They are not agent-owned data, so this module does two
things above all: it copies a file aside before touching it, and it reproduces
the existing layout byte-for-byte rather than imposing a new one.

The three formats differ, and each is derived from the file as it stands:

  imp DS.txt     `50. std::nth_element — ...`, entries separated by U+2500 x62,
                 new entries APPENDED at the end of the file.
  formula.txt    `[16] Digital Root Formula (LC 258)`, separated by '-' x40,
                 the file ends with a '=' x40 footer, so new entries are
                 INSERTED above that footer.
  algo_name.txt  a plain numbered list under the `Algorithms` heading, with
                 unrelated notes below it — new entries are INSERTED after the
                 last numbered item, not appended to the file.
"""

from __future__ import annotations

import re
import shutil
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path

from . import paths

SEP_DS = "─" * 62          # ──────… as used in imp DS.txt
SEP_FORMULA = "-" * 40
FOOTER_FORMULA = "=" * 40
INDENT = "    "
WRAP = 74                  # prose column in both files, including the indent


@dataclass(frozen=True)
class Target:
    key: str
    label: str
    what: str                    # what belongs in this file, for the model prompt

    @property
    def path(self) -> Path:
        return _PATHS[self.key]()


_PATHS = {
    "ds": lambda: paths.notes_dir() / "imp DS.txt",
    "formula": lambda: paths.formula_file(),
    "algo": lambda: paths.notes_dir() / "algo_name.txt",
}

TARGETS = {
    "ds": Target("ds", "imp DS.txt",
                 "a C++ STL feature, container, idiom or data-structure trick "
                 "— something with syntax worth remembering"),
    "formula": Target("formula", "formula.txt",
                      "a mathematical or bit-manipulation identity — a closed "
                      "form, a derivation, a counting formula"),
    "algo": Target("algo", "algo_name.txt",
                   "a NAMED algorithm (Kadane, KMP, Hierholzer) that is not "
                   "already in the list — one line, no code"),
}


def _read(t: Target) -> str:
    return t.path.read_text(encoding="utf-8")


def backup(t: Target) -> Path:
    """Copy the notes file aside before any write. Never skipped."""
    d = paths.agent_data_dir() / "notes_backups"
    d.mkdir(parents=True, exist_ok=True)
    dest = d / f"{t.path.stem} {datetime.now():%Y-%m-%d_%H%M%S}{t.path.suffix}"
    shutil.copy2(t.path, dest)
    return dest


# ── reading the existing entries ─────────────────────────────────────────────

_HEAD_DS = re.compile(r"^(\d+)\.\s+(.*)$")
_HEAD_FORMULA = re.compile(r"^\[(\d+)\]\s*(.*)$")
_ITEM_ALGO = re.compile(r"^(\d+)\.\s+(.*)$")


def _algo_section(lines: list[str]) -> tuple[int, int]:
    """(first, last) line indices of the numbered list under `Algorithms`."""
    start = next((i for i, l in enumerate(lines) if l.strip() == "Algorithms"), -1)
    if start < 0:
        raise ValueError("algo_name.txt has no `Algorithms` heading")
    i = start + 1
    while i < len(lines) and not lines[i].strip():
        i += 1
    first = i
    while i < len(lines) and _ITEM_ALGO.match(lines[i].strip()):
        i += 1
    if i == first:
        raise ValueError("no numbered items under `Algorithms`")
    return first, i - 1


def entries(t: Target) -> list[tuple[int, str]]:
    """[(number, title)] already in the file, in file order."""
    lines = _read(t).split("\n")
    out: list[tuple[int, str]] = []
    if t.key == "ds":
        for l in lines:
            m = _HEAD_DS.match(l)               # headings sit at column 0
            if m and not l.startswith(" "):
                out.append((int(m.group(1)), m.group(2).strip()))
    elif t.key == "formula":
        for l in lines:
            m = _HEAD_FORMULA.match(l.strip())
            if m:
                out.append((int(m.group(1)), m.group(2).strip()))
    else:
        first, last = _algo_section(lines)
        for l in lines[first:last + 1]:
            m = _ITEM_ALGO.match(l.strip())
            if m:
                out.append((int(m.group(1)), m.group(2).strip()))
    return out


def next_number(t: Target) -> int:
    e = entries(t)
    return (max(n for n, _ in e) + 1) if e else 1


# ── duplicate detection ──────────────────────────────────────────────────────

_STOP = {"the", "a", "an", "of", "for", "in", "to", "and", "or", "with",
         "lc", "leetcode", "using", "via"}


def _tokens(s: str) -> set[str]:
    return {w for w in re.findall(r"[a-z0-9_]+", s.lower()) if w not in _STOP and len(w) > 1}


def duplicate(t: Target, title: str, pid: str | int | None = None) -> str | None:
    """
    The existing entry this one would duplicate, or None.

    Three checks, cheapest first: the same problem already cited, the same
    title, or a title that shares most of its meaningful words with an
    existing one. Appending a near-duplicate to a hand-curated file is worse
    than skipping a genuine new entry, so this errs toward reporting a match.
    """
    if pid is not None:
        text = _read(t)
        if re.search(rf"\b(?:LC|LeetCode)\s*{int(pid)}\b", text, re.I):
            for n, existing in entries(t):
                if re.search(rf"\b(?:LC|LeetCode)\s*{int(pid)}\b", existing, re.I):
                    return f"{n}. {existing}"
            return f"problem {pid} is already cited in {t.label}"

    want = _tokens(title)
    if not want:
        return None
    for n, existing in entries(t):
        have = _tokens(existing)
        if not have:
            continue
        if want == have:
            return f"{n}. {existing}"
        overlap = len(want & have) / min(len(want), len(have))
        if overlap >= 0.6:
            return f"{n}. {existing}"
    return None


# ── rendering and writing ────────────────────────────────────────────────────

#: Characters models reach for that the notes files never use. The em dash and
#: the arrow are deliberately absent — both already appear in the files.
_NORMALISE = {
    "\u2011": "-",      # non-breaking hyphen
    "\u2013": "-",      # en dash
    "\u00a0": " ",      # non-breaking space
    "\u2018": "'", "\u2019": "'",
    "\u201c": '"', "\u201d": '"',
    "\u200b": "", "\ufeff": "",
}


def _clean(s: str) -> str:
    for bad, good in _NORMALISE.items():
        s = s.replace(bad, good)
    return s


def _wrap(line: str, width: int) -> list[str]:
    """Greedy wrap, hanging-indented under a leading `- ` bullet."""
    if len(line) <= width:
        return [line]
    hang = "  " if line.lstrip().startswith("- ") else ""
    out, cur = [], ""
    for word in line.split(" "):
        cand = f"{cur} {word}".strip() if cur else word
        if cur and len(cand) + (len(hang) if out else 0) > width:
            out.append(cur if not out else hang + cur)
            cur = word
        else:
            cur = cand
    if cur:
        out.append(cur if not out else hang + cur)
    return out


_BULLET = re.compile(r"^(?:[-*\u2022]\s|\d+[.)]\s)")


def _indent(body: str, width: int = WRAP) -> str:
    """
    4-space indent, matching the files; blank lines stay truly empty.

    Prose is REFLOWED, not wrapped line by line: the model brings its own line
    breaks at whatever column it likes, and re-wrapping those individually
    leaves orphan fragments ("temporary copy," alone on a line). Consecutive
    prose lines are joined into a paragraph and wrapped once.

    A line the model indented is a code snippet and is passed through
    untouched — the indent is the only reliable signal for that, and
    reflowing code would corrupt it.
    """
    out: list[str] = []
    para: list[str] = []

    def flush() -> None:
        if not para:
            return
        joined = " ".join(x.strip() for x in para)
        out.extend(INDENT + w for w in _wrap(joined, width - len(INDENT)))
        para.clear()

    for line in _clean(body).rstrip().split("\n"):
        line = line.rstrip()
        if not line:
            flush()
            out.append("")
        elif line[0].isspace():
            flush()
            out.append(INDENT + line)
        elif _BULLET.match(line) or (para and para[-1].rstrip().endswith(":")):
            flush()                       # a bullet or a lead-in starts a new block
            para.append(line)
        else:
            para.append(line)
    flush()

    while out and not out[-1]:
        out.pop()
    return "\n".join(out)


def render(t: Target, number: int, title: str, body: str = "") -> str:
    """The exact text that would be added, for previewing before a write."""
    title = _clean(title).strip()
    if t.key == "ds":
        return f"{SEP_DS}\n\n{number}. {title}\n\n{_indent(body)}\n"
    if t.key == "formula":
        return f"{SEP_FORMULA}\n\n[{number}] {title}\n\n{_indent(body)}\n"
    return f"{str(number) + '.':<4}{title}\n"


def append(t: Target, title: str, body: str = "") -> tuple[int, Path, str]:
    """
    Add one entry. Returns (number, backup path, the text that was added).

    The backup happens before the write, so a bad entry is always one `cp`
    away from being undone.
    """
    n = next_number(t)
    added = render(t, n, title, body)
    bak = backup(t)
    text = _read(t)

    if t.key == "ds":
        if not text.endswith("\n"):
            text += "\n"
        text += "\n" + added

    elif t.key == "formula":
        lines = text.split("\n")
        foot = [i for i, l in enumerate(lines) if l.strip() == FOOTER_FORMULA]
        if not foot:
            raise ValueError("formula.txt is missing its trailing '=' footer")
        i = foot[-1]
        lines[i:i] = added.rstrip("\n").split("\n") + [""]
        text = "\n".join(lines)

    else:
        lines = text.split("\n")
        _, last = _algo_section(lines)
        lines[last + 1:last + 1] = added.rstrip("\n").split("\n")
        text = "\n".join(lines)

    t.path.write_text(text, encoding="utf-8")
    return n, bak, added
