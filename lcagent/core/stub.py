#!/usr/bin/env python3
"""
Turn an archived, solved solution back into the empty stub a fresh fetch gives.

The local archive (`Code Dirs/All LC 1 - 4017/<id>/`) holds a driver, input and
expected file for every problem — many repaired by hand, which a fresh LeetCode
fetch would regenerate broken — but its `<id>.cpp` is the finished solution.
Handing that back defeats the point of re-solving, so the fetcher writes this
stub in its place:

  * the `// Link:` header and the includes;
  * any type the API or the driver needs — TreeNode, a mock Iterator or
    CustomFunction, the `int guess(int num);` declaration — kept verbatim;
  * the solution class with its public API methods, bodies emptied.

Everything that *is* the solution — helpers, members, private methods, helper
structs, comments — is dropped. Which methods count as the API is read off the
driver: whatever it calls (`sol.twoSum(`, `obj->push(`, `"push"`) survives.

This is not a C++ parser. Comments, literals and preprocessor lines are blanked
first, which leaves a brace/paren scan that is enough for the shapes LeetCode
solutions take; every archived problem was checked by compiling its stub
against its own driver.
"""

from __future__ import annotations

import re
from dataclasses import dataclass

_TYPE_HEAD = re.compile(r"^(?:template\s*<.*>\s*)?(?:class|struct|union|enum|typedef)\b", re.S)
_CLASS_HEAD = re.compile(r"^(?:template\s*<.*>\s*)?(class|struct)\s+(\w+)\s*(?:final\b)?\s*(:.*)?$", re.S)
_ACCESS = re.compile(r"\s*(public|private|protected)\s*:(?!:)")
_ALIAS = re.compile(r"^(?:using\s+(\w+)\s*=|typedef\b.*?(\w+)\s*;$)", re.S)
_INCLUDE = re.compile(r"^[ \t]*#[ \t]*include\b.*$", re.M)
_LINK = re.compile(r"^//\s*Link:.*$", re.M)
_TEMPLATE = re.compile(r"template\s*<")
_DEFINE = re.compile(r"^[ \t]*#[ \t]*define[ \t]+(\w+)(?![\w(])[ \t]*(.*?)\s*$", re.M)
_ATTRIBUTE = re.compile(r"__attribute__\s*\(\(.*?\)\)|\[\[.*?\]\]")
#: Never expanded even when #defined — `#define int long long` must not turn
#: LeetCode's `int` API into `long long`.
_KEYWORDS = frozenset("int long short char bool float double void unsigned signed auto "
                      "const static inline virtual".split())


# ─── masking ─────────────────────────────────────────────────────────────────

def _mask(src: str) -> tuple[str, str]:
    """
    Two same-length copies of `src`, newlines preserved:

      code  — comments, string/char literals and preprocessor lines blanked,
              so braces and semicolons can be counted naively;
      clean — only the comments blanked, for text that is copied out.
    """
    code, clean = list(src), list(src)
    n, i, line_start = len(src), 0, True

    def blank(buf: list[str], a: int, b: int) -> None:
        for k in range(a, b):
            if buf[k] != "\n":
                buf[k] = " "

    while i < n:
        c = src[i]
        if c == "\n":
            line_start, i = True, i + 1
            continue
        if line_start and c == "#":                    # to end of line, with `\` continuations
            j = i
            while j < n and src[j] != "\n":
                j += 2 if src[j] == "\\" and j + 1 < n else 1
            blank(code, i, j)
            i = j
            continue
        if not c.isspace():
            line_start = False
        if src.startswith("//", i):
            j = src.find("\n", i)
            j = n if j < 0 else j
            blank(code, i, j), blank(clean, i, j)
            i = j
            continue
        if src.startswith("/*", i):
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            blank(code, i, j), blank(clean, i, j)
            i = j
            continue
        if c == '"':
            raw = re.search(r"(?:^|\W)(?:u8|u|U|L)?R$", src[max(0, i - 3):i])
            if raw and "(" in src[i:i + 18]:
                delim = src[i + 1:src.index("(", i)]
                j = src.find(")" + delim + '"', i)
                j = n if j < 0 else j + len(delim) + 2
            else:
                j = i + 1
                while j < n and src[j] not in '"\n':
                    j += 2 if src[j] == "\\" else 1
                j = min(j + 1, n)
            blank(code, i + 1, j - 1)
            i = j
            continue
        # `'` after an identifier character is a digit separator (1'000'000).
        if c == "'" and not (i and (src[i - 1].isalnum() or src[i - 1] == "_")):
            j = i + 1
            while j < n and src[j] not in "'\n":
                j += 2 if src[j] == "\\" else 1
            j = min(j + 1, n)
            blank(code, i + 1, j - 1)
            i = j
            continue
        i += 1
    return "".join(code), "".join(clean)


def _pairs(code: str) -> dict[int, int]:
    """Opening bracket index → its closing index, per bracket kind."""
    opens: dict[str, list[int]] = {"(": [], "[": [], "{": []}
    closer = {")": "(", "]": "[", "}": "{"}
    out: dict[int, int] = {}
    for i, c in enumerate(code):
        if c in opens:
            opens[c].append(i)
        elif c in closer and opens[closer[c]]:
            out[opens[closer[c]].pop()] = i
    return out


def _skip_angles(code: str, pairs: dict[int, int], lt: int, b: int) -> int:
    """Index just past the `>` closing the template parameter list opened at `lt`."""
    depth, i = 0, lt
    while i < b:
        c = code[i]
        if c in "([":
            i = pairs.get(i, b - 1) + 1
            continue
        if c == "<":
            depth += 1
        elif c == ">":
            depth -= 1
            if depth == 0:
                return i + 1
        elif c in "{;":
            return i
        i += 1
    return b


def _segments(code: str, pairs: dict[int, int], a: int, b: int) -> list[tuple[int, int]]:
    """
    Split code[a:b] into declarations, as (start, end) spans.

    A declaration ends at a `;`, or at the `}` closing a function or namespace
    body. Type definitions and initialisers (`struct X {...};`, `int d[] =
    {...};`, `auto f = [](){...}();`) run on to their `;`.
    """
    segs: list[tuple[int, int]] = []
    i = a
    while i < b:
        while i < b and code[i].isspace():
            i += 1
        if i >= b:
            break
        start, assign = i, False
        t = _TEMPLATE.match(code, i, b)
        if t:                           # `template <class T = int>` is not an initialiser
            i = _skip_angles(code, pairs, t.end() - 1, b)
        while i < b:
            c = code[i]
            if c in "([":
                i = min(pairs.get(i, b - 1), b - 1) + 1
            elif c == ";":
                i += 1
                break
            elif c == "=":
                if (code[i + 1:i + 2] != "=" and code[i - 1:i] not in ("=", "!", "<", ">")
                        and not re.search(r"operator\s*\W*$", code[start:i])):
                    assign = True
                i += 1
            elif c == "{":
                runs_on = assign or bool(_TYPE_HEAD.match(code[start:i].strip()))
                i = min(pairs.get(i, b - 1), b - 1) + 1
                if not runs_on:
                    break
            else:
                i += 1
        segs.append((start, i))
    return segs


# ─── declarations ────────────────────────────────────────────────────────────

@dataclass
class _Func:
    name: str
    sig: str          # "int twoSum(vector<int>& nums, int target)" — cleaned, one line
    public: bool
    ctor: bool
    params: bool      # takes at least one parameter


def _flat(text: str) -> str:
    return re.sub(r"\s+", " ", text).strip()


def _top_paren(code: str, pairs: dict[int, int], a: int, b: int) -> int | None:
    """The first `(` at this nesting level before any `{` or initialiser `=`."""
    i = a
    while i < b:
        c = code[i]
        if c == "(":
            return i
        if c == "[":
            i = pairs.get(i, b) + 1
            continue
        if c in "{;" or (c == "=" and not re.search(r"operator\s*\W*$", code[a:i])):
            return None
        i += 1
    return None


def _ctor_bases(code: str, clean: str, pairs: dict[int, int], close: int, b: int,
                bases: set[str]) -> str:
    """
    The base-class entries of a constructor's initialiser list.

    Member initialisers are the solution and go; `: Iterator(nums)` is what
    lets `PeekingIterator` compile at all, so it stays.
    """
    i = close + 1
    while i < b and code[i].isspace():
        i += 1
    if code[i:i + 1] != ":" or code[i:i + 2] == "::":
        return ""
    kept, i = [], i + 1
    while i < b:
        j = i
        while j < b and code[j] not in "({;":
            j += 1
        if j >= b or code[j] == ";":
            break
        end = pairs.get(j, b - 1)
        name = re.sub(r"<.*>", "", code[i:j]).strip().split("::")[-1]
        if name in bases:
            kept.append(_flat(clean[i:end + 1]))
        i = end + 1
        while i < b and code[i].isspace():
            i += 1
        if code[i:i + 1] != ",":
            break
        i += 1
    return " : " + ", ".join(kept) if kept else ""


def _members(code: str, clean: str, pairs: dict[int, int],
             cls: str, is_struct: bool, bases: set[str], open_: int) -> list[_Func]:
    """Every member function of the class whose body opens at `open_`."""
    close = pairs[open_]
    public = is_struct
    out: list[_Func] = []
    for s, e in _segments(code, pairs, open_ + 1, close):
        while m := _ACCESS.match(code, s, e):          # peel `public:` etc.
            public = m.group(1) == "public"
            s = m.end()
        p = _top_paren(code, pairs, s, e)
        if p is None:
            continue
        head = code[s:p].rstrip()
        name_m = re.search(r"(~?)\s*(\w+)$", head)
        if not name_m or name_m.group(1) or re.search(r"\boperator\b", head):
            continue                                     # destructor / operator
        name = name_m.group(2)
        pclose = pairs.get(p)
        if pclose is None or pclose > e:
            continue
        ctor = name == cls
        tail = ""
        if ctor:
            tail = _ctor_bases(code, clean, pairs, pclose, e, bases)
        else:
            # Only real qualifiers survive — not a body, `= 0`, or a macro
            # like OUTL_ATTR whose #define the stub no longer carries.
            q = re.split(r"[{;=]", code[pclose + 1:e], maxsplit=1)[0]
            arrow = re.search(r"->.*", q)
            words = re.findall(r"\b(?:const|noexcept|override|final)\b", q[:arrow.start()] if arrow else q)
            tail = "".join(" " + w for w in words) + (" " + _flat(arrow.group(0)) if arrow else "")
        sig = _flat(clean[s:pclose + 1]) + tail
        params = code[p + 1:pclose].strip()
        out.append(_Func(name, sig, public, ctor, bool(params) and params != "void"))
    return out


def _decl_name(code: str, pairs: dict[int, int], s: int, e: int) -> str | None:
    """The name a non-class top-level declaration introduces."""
    p = _top_paren(code, pairs, s, e)
    head = code[s:p] if p is not None else re.split(r"[=\[{;]", code[s:e], maxsplit=1)[0]
    m = re.search(r"(::)?\s*(\w+)\s*$", head)
    # `vector<int> Solution::v;` defines a member the stub has dropped.
    return m.group(2) if m and not m.group(1) else None


def _aliases(src: str, code: str) -> tuple[dict[str, str], dict[str, tuple[str, str]]]:
    """
    Plain aliases (`using ll = long long;`, `typedef long long ll;`,
    `#define ll long long`) and one-parameter alias templates
    (`template <class T> using V = vector<T>;` → {"V": ("T", "vector<T>")}).
    """
    plain: dict[str, str] = {}
    templates: dict[str, tuple[str, str]] = {}
    for m in re.finditer(r"(template\s*<\s*(?:typename|class)\s+(\w+)\s*>\s*)?"
                         r"\busing\s+(\w+)\s*=\s*([^;{}]+);", code):
        if m.group(1):
            templates[m.group(3)] = (m.group(2), _flat(m.group(4)))
        else:
            plain[m.group(3)] = m.group(4)
    for m in re.finditer(r"\btypedef\s+([^;{}()]+?)\s+(\w+)\s*;", code):
        plain[m.group(2)] = m.group(1)
    for m in _DEFINE.finditer(src):
        plain[m.group(1)] = m.group(2)
    return {k: _flat(v) for k, v in plain.items() if k not in _KEYWORDS}, templates


def _expand(sig: str, aliases: dict[str, str], templates: dict[str, tuple[str, str]]) -> str:
    """
    A signature in plain types: `ll target` → `long long target`,
    `V<int>& a` → `vector<int>& a`.

    The alias may live inside the dropped class body, and LeetCode's own
    signature never uses one, so expanding beats carrying the alias along.
    """
    for _ in range(5):
        new = re.sub(r"\b\w+\b", lambda m: aliases.get(m.group(0), m.group(0)), sig)
        for name, (param, body) in templates.items():
            m = re.search(rf"\b{re.escape(name)}\s*<", new)
            while m:
                depth, j = 0, m.end() - 1
                for j in range(m.end() - 1, len(new)):
                    depth += {"<": 1, ">": -1}.get(new[j], 0)
                    if depth == 0:
                        break
                else:
                    break                                # unbalanced — leave it
                arg = new[m.end():j].strip()
                new = new[:m.start()] + re.sub(rf"\b{re.escape(param)}\b", arg, body) + new[j + 1:]
                m = re.search(rf"\b{re.escape(name)}\s*<", new)
        if new == sig:
            break
        sig = new
    return _flat(_ATTRIBUTE.sub("", sig))


def _api_sig(sig: str) -> str:
    """
    The signature as LeetCode states it: no `static`/`inline`, and no
    parameter with a default value — `int ans = INF` is part of a solution.
    """
    sig = re.sub(r"^(?:(?:static|inline|constexpr)\s+)+", "", sig)
    lp = sig.find("(")
    if lp < 0:
        return sig
    depth, rp = 0, -1
    for k in range(lp, len(sig)):
        depth += {"(": 1, ")": -1}.get(sig[k], 0)
        if depth == 0:
            rp = k
            break
    if rp < 0:
        return sig
    params, cur, d = [], "", 0
    for c in sig[lp + 1:rp]:
        d += {"<": 1, "(": 1, "[": 1, "{": 1, ">": -1, ")": -1, "]": -1, "}": -1}.get(c, 0)
        if c == "," and d == 0:
            params.append(cur)
            cur = ""
        else:
            cur += c
    params.append(cur)
    kept = [p.strip() for p in params if p.strip() and not re.search(r"(?<![=!<>])=(?!=)", p)]
    return sig[:lp + 1] + ", ".join(kept) + sig[rp:]


# ─── the stub ────────────────────────────────────────────────────────────────

def _called(driver: str) -> set[str]:
    """Every name the driver could be calling on the solution object."""
    return (set(re.findall(r"(?:\.|->)\s*(\w+)\s*\(", driver))
            | set(re.findall(r"::\s*(\w+)", driver))
            | set(re.findall(r'"(\w+)"', driver)))


def _mentions(name: str, text: str) -> bool:
    return re.search(rf"(?<![\w]){re.escape(name)}(?![\w])", text) is not None


def make_stub(src: str, driver: str = "") -> str | None:
    """
    The empty stub for an archived solution, or None when the solution class
    or its API cannot be found — the caller then falls back to LeetCode.
    """
    code, clean = _mask(src)
    pairs = _pairs(code)

    classes = []           # (name, is_struct, bases_text, start, open_brace, end)
    others = []            # (kind, name, start, end)
    for s, e in _segments(code, pairs, 0, len(code)):
        brace = code.find("{", s, e)
        head = code[s:brace].strip() if brace >= 0 else ""
        m = _CLASS_HEAD.match(head) if head else None
        if m and pairs.get(brace, e) < e:
            classes.append((m.group(2), m.group(1) == "struct", m.group(3) or "", s, brace, e))
            continue
        a = _ALIAS.match(_flat(code[s:e]))
        if a:
            others.append(("alias", a.group(1) or a.group(2), s, e))
        elif not code[s:e].lstrip().startswith(("using namespace", "namespace")):
            others.append(("decl", _decl_name(code, pairs, s, e), s, e))

    if not classes:
        return None
    names = [c[0] for c in classes]
    if "Solution" in names:
        sol = classes[len(names) - 1 - names[::-1].index("Solution")]
    else:
        referenced = [c for c in classes if _mentions(c[0], driver)]
        sol = (referenced or classes)[-1]
    cls, is_struct, bases_text, s0, open_, e0 = sol

    bases = {w for w in re.findall(r"\w+", re.sub(r"<.*?>", "", bases_text))
             if w not in ("public", "private", "protected", "virtual")}
    funcs = [f for f in _members(code, clean, pairs, cls, is_struct, bases, open_) if f.public]
    called = _called(driver)
    keep = [f for f in funcs
            if (f.ctor and (cls != "Solution" or f.params)) or (not f.ctor and f.name in called)]
    if not any(not f.ctor for f in keep):           # driver named nothing: keep the public API
        keep = [f for f in funcs if not f.ctor or cls != "Solution" or f.params]
    if not any(not f.ctor for f in keep):
        return None
    aliases, templates = _aliases(src, code)
    for f in keep:
        f.sig = _expand(_api_sig(f.sig), aliases, templates)

    # Types and declarations the kept signatures or the driver still need,
    # followed transitively (a kept Node may mention another kept type).
    refs = " ".join(f.sig for f in keep) + " " + _flat(clean[s0:open_]) + " " + driver
    kept_spans: set[tuple[int, int]] = set()
    pool = [(c[0], c[3], c[5]) for c in classes if c is not sol]
    pool += [(o[1], o[2], o[3]) for o in others if o[1]]
    grew = True
    while grew:
        grew = False
        for name, s, e in pool:
            if (s, e) not in kept_spans and _mentions(name, refs):
                kept_spans.add((s, e))
                refs += " " + clean[s:e]
                grew = True
    kept = [_dedent_blanks(clean[s:e]) for s, e in sorted(kept_spans)]

    link = _LINK.search(src)
    includes = _INCLUDE.findall(src) or ["#include <bits/stdc++.h>"]
    out = []
    if link:
        out += [link.group(0).rstrip(), ""]
    out += [ln.strip() for ln in dict.fromkeys(includes)]
    out += ["using namespace std;", ""]
    for block in kept:
        out += [block, ""]
    out.append(f"{_flat(clean[s0:open_])} {{")
    out.append("public:")
    for k, f in enumerate(keep):
        if k:
            out.append("")
        out += [f"    {f.sig} {{", "        ", "    }"]
    out.append("};")
    return "\n".join(out) + "\n"


def _dedent_blanks(block: str) -> str:
    """Kept text verbatim, minus the runs of blank lines stripped comments leave."""
    lines = [ln.rstrip() for ln in block.splitlines()]
    out: list[str] = []
    for ln in lines:
        if ln or (out and out[-1]):
            out.append(ln)
    return "\n".join(out).strip("\n")


def is_untouched(src: str, driver: str = "") -> bool:
    """
    True when `src` is nothing but its own empty stub — no work to lose.

    Compared with whitespace removed and comments kept, so a stub the user has
    only written notes into still counts as work.
    """
    stub = make_stub(src, driver)
    if stub is None:
        return False
    squash = lambda t: re.sub(r"\s+", "", t)          # noqa: E731
    return squash(stub) == squash(src)
