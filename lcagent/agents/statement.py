#!/usr/bin/env python3
"""
StatementAgent — renders <id>_problem.txt: the question, its constraints, and
every example test case with its expected result.

LeetCode ships the statement as HTML. The naive strip in fetch_problem.py
replaces every tag with a newline, which destroys `10<sup>5</sup>` (it becomes
"10\\n5\\n") — exactly the constraint numbers that decide which complexity you
need. This parser resolves superscripts and subscripts *before* stripping tags.

Works offline: with no network it falls back to the cache, then to the local
_input/_expected files plus the archived reference for the signature.
"""

from __future__ import annotations

import html as _html
import re
import textwrap

from ..core import leetcode
from ..core.state import Context
from .base import Agent, AgentResult

WIDTH = 74
RULE = "═" * WIDTH


# ─── HTML → text ─────────────────────────────────────────────────────────────

def _resolve_marks(s: str) -> str:
    r"""
    Superscripts/subscripts carry meaning: 10<sup>5</sup> must survive as 10^5.

    LeetCode frequently lets these tags straddle a line break — `100<sub>2 \n
    </sub>Indices ...` — so a plain \s* strip would weld two sentences
    together. Any newline inside the tag is preserved.
    """
    def sub_repl(m: "re.Match[str]") -> str:
        inner = m.group(1)
        return inner.strip() + ("\n" if "\n" in inner else "")

    def sup_repl(m: "re.Match[str]") -> str:
        inner = m.group(1)
        return "^" + inner.strip() + ("\n" if "\n" in inner else "")

    s = re.sub(r"<sup>(.*?)</sup>", sup_repl, s, flags=re.DOTALL)
    s = re.sub(r"<sub>(.*?)</sub>", sub_repl, s, flags=re.DOTALL)
    return s


def _text(s: str) -> str:
    """Strip tags to plain text, preserving block boundaries as newlines."""
    s = _resolve_marks(s)
    s = re.sub(r"<br\s*/?>", "\n", s, flags=re.I)
    s = re.sub(r"</(p|li|ul|ol|div|pre|h[1-6])>", "\n", s, flags=re.I)
    s = re.sub(r"<li>", "  - ", s, flags=re.I)
    s = re.sub(r"<[^>]+>", "", s)
    s = _html.unescape(s)
    # LeetCode sprinkles non-breaking, thin and zero-width characters through
    # its HTML. Left in, they render as phantom indentation and blank lines.
    s = s.replace("\xa0", " ").replace("\u2009", " ")
    for _zw in ("\u200b", "\u200c", "\u200d", "\u2060", "\ufeff"):
        s = s.replace(_zw, "")
    s = re.sub(r"[ \t]+", " ", s)
    s = re.sub(r"\n{3,}", "\n\n", s)
    return "\n".join(ln.rstrip() for ln in s.splitlines()).strip()


def _wrap(text: str, indent: str = "  ") -> str:
    """Wrap to WIDTH, hanging-indenting bullet lines under their marker."""
    out = []
    for para in text.split("\n"):
        stripped = para.strip()
        if not stripped:
            out.append("")
        elif stripped.startswith("- "):
            out.append(textwrap.fill(
                stripped[2:], WIDTH,
                initial_indent=indent + "- ",
                subsequent_indent=indent + "  ",
                break_long_words=False,
            ))
        else:
            out.append(textwrap.fill(
                stripped, WIDTH,
                initial_indent=indent, subsequent_indent=indent,
                break_long_words=False,
            ))
    return "\n".join(out).rstrip()


# ─── section extraction ──────────────────────────────────────────────────────

def parse_sections(content_html: str) -> dict:
    """Split the statement HTML into description / examples / constraints / follow-up."""
    body = content_html or ""

    # Examples come in two markups. Older problems use a single <pre> block;
    # problems added more recently use <div class="example-block"> with the
    # values wrapped in <span class="example-io">. Both are matched, in
    # document order, so a mixed or transitional page still parses.
    raw_blocks = [
        (m.start(), m.group(1) or m.group(2))
        for m in re.finditer(
            r"<pre>(.*?)</pre>"
            r"|<div class=\"example-block\">(.*?)</div>",
            body, flags=re.DOTALL | re.I)
    ]
    examples = [_parse_example(b) for _, b in sorted(raw_blocks)]
    examples = [e for e in examples if e.get("input") or e.get("output")]

    # Constraints: the <ul> following the "Constraints:" heading.
    constraints: list[str] = []
    m = re.search(r"Constraints:?\s*</strong>\s*</p>(.*?)(?:</ul>|$)", body, flags=re.DOTALL | re.I)
    if m:
        constraints = [_text(li) for li in re.findall(r"<li>(.*?)</li>", m.group(1), flags=re.DOTALL | re.I)]
    constraints = [c.lstrip("- ").strip() for c in constraints if c.strip()]

    # Follow-up, when present.
    follow = ""
    fm = re.search(r"Follow[ -]?up:?\s*</strong>(.*?)(?:</p>|$)", body, flags=re.DOTALL | re.I)
    if fm:
        follow = _text(fm.group(1))

    # Description: everything before the first example / constraints block.
    cut = len(body)
    for pat in (r"<strong class=\"example\">", r"<p><strong>Example", r"<strong>Constraints:"):
        mm = re.search(pat, body, flags=re.I)
        if mm:
            cut = min(cut, mm.start())
    description = _text(body[:cut])

    return {
        "description": description,
        "examples": examples,
        "constraints": constraints,
        "follow_up": follow,
    }


def _parse_example(block_html: str) -> dict:
    """Pull Input / Output / Explanation out of one example block, either markup."""
    txt = _text(block_html)
    out: dict[str, str] = {}
    current = None
    buf: list[str] = []
    for line in txt.splitlines():
        m = re.match(r"\s*(Input|Output|Explanation)\s*:?\s*(.*)$", line, flags=re.I)
        if m:
            if current:
                out[current] = "\n".join(buf).strip()
            current = m.group(1).lower()
            buf = [m.group(2)]
        elif current:
            buf.append(line)
    if current:
        out[current] = "\n".join(buf).strip()
    return out


def extract_signatures(cpp_snippet: str) -> list[str]:
    """The public method declarations from LeetCode's C++ snippet."""
    if not cpp_snippet:
        return []
    code = re.sub(r"/\*.*?\*/", "", cpp_snippet, flags=re.DOTALL)
    code = re.sub(r"//.*", "", code)
    sigs = []
    for line in code.splitlines():
        s = line.strip()
        if not s or s.startswith(("class", "public", "private", "#", "}", "*", "struct")):
            continue
        if "(" in s and ")" in s and not s.startswith("return"):
            sigs.append(s.rstrip("{ ").rstrip() + ";" if not s.rstrip().endswith(";") else s)
    return sigs


# ─── the agent ───────────────────────────────────────────────────────────────

class StatementAgent(Agent):
    name = "statement"
    role = "Render the question, constraints and example test cases to a readable text file"
    requires_llm = False

    def run(self, ctx: Context, *, refresh: bool = False, brief: bool = True, **_) -> AgentResult:
        data = ctx.problem
        source = "cache"
        if data is None or refresh:
            try:
                data = leetcode.fetch_question(ctx.pid, refresh=refresh)
                source = "leetcode"
            except leetcode.OfflineError as e:
                data = leetcode.cached_only(ctx.pid)
                if data is None:
                    return self.fail(f"offline and nothing cached for {ctx.pid}: {e}")
                source = "cache (offline)"
            except RuntimeError as e:
                return self.fail(str(e))
        ctx.problem = data

        sections = parse_sections(data.get("content", ""))
        text = self.render(ctx, data, sections, brief=brief)

        target = ctx.paths.problem
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(text, encoding="utf-8")

        ctx.note(self.name, f"wrote {target.name} from {source}")
        note = " [PREMIUM — statement unavailable]" if data.get("locked") else ""
        return self.ok(
            f"{data['title']} ({data.get('difficulty','?')}){note} — "
            f"{len(sections['examples'])} examples, {len(sections['constraints'])} constraints",
            artifacts=[target],
            examples=len(sections["examples"]),
            constraints=len(sections["constraints"]),
            source=source,
        )

    # ── rendering ──
    def render(self, ctx: Context, d: dict, sec: dict, *, brief: bool = True) -> str:
        """
        The question, its constraints, and each test case with its result.

        `brief` (the default) omits the hints — they are spoilers, and on a
        hard problem they run longer than the statement itself. Pass
        brief=False to include them.
        """
        L: list[str] = []
        tags = ", ".join(d.get("tags") or []) or "—"
        L += [RULE,
              f" {d['id']}. {d['title']}",
              f" {d.get('difficulty') or '?'}  |  Tags: {tags}",
              f" {leetcode.problem_url(d['slug'])}",
              RULE, ""]

        if d.get("locked"):
            L += ["PROBLEM",
                  _wrap("This is a LeetCode Premium problem. The statement, "
                        "constraints and code snippet are not served by the API "
                        "without a subscription — only the title, difficulty, tags "
                        "and example test cases below are available."),
                  ""]
        else:
            L += ["PROBLEM", _wrap(sec["description"]) or "  (unavailable)", ""]

        if sec["constraints"]:
            L.append("CONSTRAINTS")
            for c in sec["constraints"]:
                L.append(f"  {c}")
            L.append("")

        L.append("TEST CASES")
        if sec["examples"]:
            for i, ex in enumerate(sec["examples"], 1):
                L.append(f"  [{i}] Input    : {ex.get('input','?')}")
                L.append(f"      Expected : {ex.get('output','?')}")
                if ex.get("explanation"):
                    expl = [ln.strip() for ln in ex["explanation"].splitlines() if ln.strip()]
                    limit = 3 if brief else len(expl)
                    if expl:
                        L.append(f"      Why      : {expl[0]}")
                        for extra in expl[1:limit]:
                            L.append(f"                 {extra}")
                        if len(expl) > limit:
                            L.append(f"                 … ({len(expl) - limit} more)")
                L.append("")
        else:
            L += self._local_cases(ctx)

        if sec["follow_up"]:
            L += ["FOLLOW UP", _wrap(sec["follow_up"]), ""]

        if d.get("hints") and not brief:
            L.append("HINTS  (spoilers)")
            for i, h in enumerate(d["hints"], 1):
                L.append(textwrap.fill(f"{i}. {_text(h)}", WIDTH,
                                       initial_indent="  ", subsequent_indent="     ",
                                       break_long_words=False))
            L.append("")

        sigs = extract_signatures(d.get("cpp_snippet", ""))
        if sigs:
            L.append("SIGNATURE")
            for s in sigs:
                L.append(f"  {s}")
            L.append("")

        L += ["FILES",
              f"  edit : {ctx.paths.solution.name}",
              f"  test : lc run {ctx.pid}",
              RULE]
        return "\n".join(L) + "\n"

    def _local_cases(self, ctx: Context) -> list[str]:
        """Offline fallback: pair up the fetched _input.txt / _expected.txt."""
        if not (ctx.paths.input.is_file() and ctx.paths.expected.is_file()):
            return ["  (no examples available)", ""]
        raw = ctx.paths.input.read_text(encoding="utf-8", errors="replace").splitlines()
        exp = ctx.paths.expected.read_text(encoding="utf-8", errors="replace").splitlines()
        if not raw:
            return ["  (no examples available)", ""]
        count = int(raw[0].strip() or 0)
        rest = raw[1:]
        per = len(rest) // count if count else 0
        out = ["  (recovered from local test files)", ""]
        for i in range(count):
            block = rest[i * per:(i + 1) * per]
            out.append(f"  [{i+1}] Input    : {' | '.join(block)}")
            out.append(f"      Expected : {exp[i] if i < len(exp) else '?'}")
            out.append("")
        return out
