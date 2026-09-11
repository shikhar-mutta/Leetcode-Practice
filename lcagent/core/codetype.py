#!/usr/bin/env python3
"""
What shape of code a problem needs — and so what its environment must carry.

Every LeetCode C++ problem is one of four shapes:

  function      class Solution { ret f(args); }             one call per test case
  design        class Foo { Foo(args); ret m(args); }        replay the ops/args script
  concurrency   methods take function<void()> callbacks      one thread per method
  interactive   a hidden API or interface the judge supplies (guess, MountainArray)

and any number of data structures cross its signature — a TreeNode, a Node that
is really a graph vertex, a NestedInteger. Those decide what the scaffold has
to provide beyond `class Solution`: the struct definition, a reader for the
input notation, a printer for the output, a mock of the hidden API. The shape
and structures are read off the signature and the type definitions, which is
all the information there is — the same text LeetCode ships as the snippet.
"""

from __future__ import annotations

import re
from dataclasses import dataclass, field

from . import stub

#: structure key → (what crosses the signature, the input notation it uses)
STRUCTURES: dict[str, tuple[str, str]] = {
    "tree":            ("TreeNode*", "level order, e.g. [3,9,20,null,null,15,7]"),
    "linked list":     ("ListNode*", "values in order, e.g. [1,2,3,4]"),
    "graph":           ("Node* {val, neighbors}", "adjacency list, e.g. [[2,4],[1,3],[2,4],[1,3]]"),
    "n-ary tree":      ("Node* {val, children}", "level order, null ends a child group, e.g. [1,null,3,2,4,null,5,6]"),
    "next pointers":   ("Node* {left, right, next}", "tree in level order; output walks next: [1,#,2,3,#]"),
    "random list":     ("Node* {next, random}", "[[val, random_index|null], ...]"),
    "multilevel list": ("Node* {prev, next, child}", "levels separated by nulls, e.g. [1,2,3,null,null,4,5]"),
    "quad tree":       ("Node* {isLeaf, topLeft, ...}", "level order of [isLeaf, val] pairs"),
    "parent pointers": ("Node* {left, right, parent}", "tree in level order, plus the nodes by value"),
    "nested list":     ("NestedInteger", "nested brackets, e.g. [1,[4,[6]]]"),
}

#: Fields that tell the many LeetCode `Node` structs apart, most specific first.
_NODE_KINDS = (
    ("neighbors", "graph"),
    ("children", "n-ary tree"),
    ("random", "random list"),
    ("child", "multilevel list"),
    ("topLeft", "quad tree"),
    ("parent", "parent pointers"),
    ("next", "next pointers"),
)

#: Capitalised names in a signature that are the standard library, not an interface.
_STD = frozenset({"Solution"})

_SIG_LINE = re.compile(r"^    (.+?\))[^()]*\{$", re.M)


@dataclass
class CodeType:
    shape: str                                         # function | design | concurrency | interactive
    cls: str                                           # Solution, MinStack, Foo ...
    methods: list[str] = field(default_factory=list)   # API signatures, ctors included
    structures: list[str] = field(default_factory=list)
    apis: list[str] = field(default_factory=list)      # hidden functions: guess(int) ...
    interfaces: list[str] = field(default_factory=list)  # judge-supplied classes: MountainArray ...

    @property
    def label(self) -> str:
        """One line: `function · tree`, `design · MinStack`, `interactive · API guess()`."""
        parts = [self.shape]
        if self.shape in ("design", "concurrency"):
            parts.append(self.cls)
        parts += self.structures
        if self.apis:
            parts.append("API " + ", ".join(f"{a}()" for a in self.apis))
        if self.interfaces:
            parts.append("interface " + ", ".join(self.interfaces))
        return " · ".join(parts)

    def environment(self) -> list[str]:
        """What the scaffold has to provide for this shape, one line each."""
        out = {
            "function": f"driver: one Solution call per test case",
            "design": f"driver: replays [\"{self.cls}\",\"op\",...] / [[args],...] and prints [null,...]",
            "concurrency": "driver: runs each method on its own thread, checks the combined output",
            "interactive": "driver: mocks what the judge supplies, backed by each case's data",
        }[self.shape]
        lines = [out]
        for s in self.structures:
            what, notation = STRUCTURES.get(s, (s, "LeetCode's own notation for it"))
            lines.append(f"{s}: {what} — {notation}")
        for a in self.apis:
            lines.append(f"hidden API: {a}() — declared in the solution, defined by the driver")
        for i in self.interfaces:
            lines.append(f"interface: {i} — the judge's class, mocked by the driver")
        return lines


def _uncomment(text: str) -> str:
    """Comment markers removed, text kept: LeetCode ships its types in comments."""
    text = re.sub(r"/\*+|\*+/", "\n", text)
    text = re.sub(r"^[ \t]*(?://+|\*)[ \t]?", "", text, flags=re.M)
    return text


def _definition(name: str, text: str) -> str:
    """Body of `struct|class name { ... };` wherever it appears, comments or not."""
    m = re.search(rf"\b(?:struct|class)\s+{re.escape(name)}\b[^;{{]*\{{(.*?)\n\s*\}};", text, re.S)
    return m.group(1) if m else ""


_CLASS_BLOCK = re.compile(r"\b(?:class|struct)\s+\w+[^;{]*\{.*?\n\s*\};", re.S)
_PROTOTYPE = re.compile(r"^\s*(?:[\w:<>]+[\s*&]+)+(\w+)\s*\(([^()]*)\)\s*;", re.M)


def _hidden_apis(text: str, s: str, methods: set[str]) -> list[str]:
    """
    Free functions the judge defines and the solution calls — `int guess(int
    num);` — from LeetCode's comments or declared ahead of the stub's class.

    Never from the solution's own code (its helpers are not an API), never
    from inside a commented interface class, and never from the "will be
    instantiated and called as such" usage note (`NestedIterator i(list);`).
    """
    notes = [c for c in re.findall(r"//[^\n]*|/\*.*?\*/", text, re.S)
             if "instantiated" not in c and "called as such" not in c]
    flat = _CLASS_BLOCK.sub("", _uncomment("\n".join(notes)) + "\n" + s)
    found = []
    for m in _PROTOTYPE.finditer(flat):
        name, params = m.group(1), m.group(2).strip()
        declared = params in ("", "void") or all(
            len(re.findall(r"\w+", p)) >= 2 for p in params.split(","))
        if declared and name not in methods and name not in found and not name[0].isupper():
            found.append(name)
    return found


def _has_methods(name: str, body: str) -> bool:
    """
    Whether a type definition declares member functions — an interface like
    MountainArray — or only data, like Employee. Constructors and their
    initialiser lists (`: val(x), left(NULL) {}`) are not methods.
    """
    return any(n != name for n in re.findall(
        r"[\w>*&]\s+\*?&?(\w+)\s*\([^()]*\)\s*(?:const\s*)?(?:=\s*0\s*)?[;{]", body))


def analyse(text: str, driver: str = "") -> CodeType | None:
    """
    The code type of a snippet, stub or solution (`driver` sharpens which
    methods are the API and may hold the type definitions). None when no
    solution class can be found.
    """
    s = stub.make_stub(text, driver)
    if s is None:
        return None
    heads = list(re.finditer(r"^(?:class|struct)\s+(\w+)([^{]*)\{$", s, re.M))
    cls, bases = heads[-1].group(1), heads[-1].group(2)
    body = s[heads[-1].end():]
    methods = [m.group(1) for m in _SIG_LINE.finditer(body)]
    names = {re.search(r"(\w+)\s*\(", m).group(1) for m in methods}

    sig_text = " ".join(methods)
    ctor_params = any(re.match(rf"{cls}\s*\(\s*[^)\s]", m) for m in methods)
    if "function<" in sig_text:
        shape = "concurrency"
    elif cls != "Solution" or ctor_params:
        shape = "design"
    else:
        shape = "function"

    sources = _uncomment(text) + "\n" + _uncomment(driver)
    structures, interfaces = [], []
    types = set(re.findall(r"\b([A-Z]\w*)\b", sig_text + " " + bases)) - {cls} - _STD
    for t in sorted(types, key=lambda t: sig_text.find(t)):
        if t == "TreeNode":
            kind = "tree"
        elif t == "ListNode":
            kind = "linked list"
        elif t == "NestedInteger":
            kind = "nested list"
        else:
            body_ = _definition(t, sources)
            kind = next((k for f, k in _NODE_KINDS if re.search(rf"\b{f}\b", body_)), None) \
                if t == "Node" else None
            if kind is None:
                # A judge class with methods is an interface to mock; a plain
                # data type (Employee, PolyNode) is just another structure.
                if not body_ or _has_methods(t, body_):
                    interfaces.append(t)
                    continue
                kind = t
        if kind not in structures:
            structures.append(kind)

    apis = _hidden_apis(text, s, names)
    if shape == "function" and (apis or interfaces):
        shape = "interactive"
    return CodeType(shape, cls, methods, structures, apis, interfaces)


def for_problem(ctx, snippet: str = "") -> CodeType | None:
    """
    The code type of a loaded problem: from LeetCode's snippet when there is
    one (it carries the hidden-API comments), else from the stub and driver on
    disk — premium problems have no snippet, but the archive has their code.
    """
    from . import leetcode

    def read(p) -> str:
        try:
            return p.read_text(encoding="utf-8", errors="replace") if p.is_file() else ""
        except OSError:
            return ""

    if not snippet:
        meta = ctx.problem or leetcode.cached_only(ctx.pid)
        snippet = (meta or {}).get("cpp_snippet") or ""
    driver = read(ctx.paths.driver)
    return (analyse(snippet, driver) if snippet else None) \
        or analyse(read(ctx.paths.solution), driver)
