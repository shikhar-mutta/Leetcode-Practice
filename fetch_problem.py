#!/usr/bin/env python3
"""
Fetches LeetCode problem data and auto-generates:
  {N}.cpp, {N}_driver.cpp, {N}_input.txt, {N}_expected.txt, {N}_debug.txt

Two problem shapes are handled:
  * plain  — class Solution { ret f(args); }        one call per test case
  * design — class Foo { Foo(args); ret m(args); }  the driver replays the
             ["Foo","m",...] / [[...],[...]] op/arg script LeetCode uses,
             and prints the result array as [null, 4, 5] to match the
             expected output shown in the problem statement.

Supported types: int, long long, double, bool, char, string and vectors
thereof, plus vector<vector<int|long long|char|string>>, and TreeNode* /
ListNode* (built from and printed back as LeetCode's [3,9,20,null,null,15,7]
form) whenever the snippet defines the struct.

The driver is matched to the code type (see environment()):
  * the six structures LeetCode calls `Node` — graph, n-ary tree, next
    pointers, random pointer, multilevel list, quad tree — told apart by
    their fields, each with its own reader and printer;
  * NestedInteger and the PeekingIterator base class, mocked in the driver
    before the #include, never in {N}.cpp (the judge supplies them);
  * hidden APIs — guess(), isBadVersion(), rand7() — declared in {N}.cpp and
    defined in the driver, backed by each case's extra input line;
  * iterators LeetCode drains with `while (i.hasNext())`, and concurrency
    classes, which get a driver that says a thread harness is needed.

Anything else lands in the driver as a "// TODO: parse ..." line that still
consumes its input line, so the file compiles and the gap is obvious.
"""

import sys, json, os, re, time
import urllib.request, urllib.error

LEETCODE_GRAPHQL = "https://leetcode.com/graphql"
HEADERS = {
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:120.0) Gecko/20100101 Firefox/120.0",
    "Referer": "https://leetcode.com",
    "Accept": "application/json",
}


# ─── LeetCode API ────────────────────────────────────────────────────────────

def post_json(url, data, tries=4):
    """POST with backoff — LeetCode rate-limits bursts and occasionally 5xx's."""
    body = json.dumps(data).encode()
    last = None
    for attempt in range(tries):
        try:
            req = urllib.request.Request(url, data=body, headers=HEADERS, method="POST")
            with urllib.request.urlopen(req, timeout=20) as r:
                return json.loads(r.read().decode())
        except (urllib.error.URLError, urllib.error.HTTPError, TimeoutError, OSError,
                json.JSONDecodeError) as e:
            last = e
            if attempt < tries - 1:
                time.sleep(1.5 * (attempt + 1))
    raise RuntimeError(f"LeetCode request failed after {tries} tries: {last}")


def fetch_problem(num):
    # 1. number → slug
    # The keyword search ranks loosely ("1" also matches "Number of 1 Bits"),
    # so ask for a wide page and pick the exact frontend id out of it.
    q1 = """query ql($f: QuestionListFilterInput) {
      questionList(categorySlug: "" limit: 30 skip: 0 filters: $f) {
        data { questionFrontendId titleSlug title }
      }
    }"""
    r1 = post_json(LEETCODE_GRAPHQL, {"query": q1, "variables": {"f": {"searchKeywords": str(num)}}})
    slug = title = None
    for q in r1["data"]["questionList"]["data"]:
        if str(q["questionFrontendId"]) == str(num):
            slug, title = q["titleSlug"], q["title"]
            break
    if not slug:
        raise RuntimeError(f"Problem {num} not found on LeetCode "
                           f"(search returned no entry with frontend id {num})")

    # 2. slug → full data
    q2 = """query qd($s: String!) {
      question(titleSlug: $s) {
        content exampleTestcases
        codeSnippets { langSlug code }
      }
    }"""
    r2 = post_json(LEETCODE_GRAPHQL, {"query": q2, "variables": {"s": slug}})
    d = r2["data"]["question"]
    if not d:
        raise RuntimeError(f"LeetCode returned no data for {slug}")
    d["title"] = title
    d["slug"] = slug
    return d


# ─── Snippet Parsing ──────────────────────────────────────────────────────────

def strip_block_comments(code):
    """Remove /* ... */ blocks so signature regexes can't match commented-out code."""
    return re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)


def extract_definitions(cpp_snippet):
    """LeetCode ships TreeNode / ListNode / Node definitions inside a comment block.
    Return them as live code so the generated solution file compiles standalone.

    Two comment styles occur: doc-style (/** ... every line prefixed with " * ")
    and plain (/* ... raw code). Both are normalised here."""
    defs = []
    for block in re.findall(r'/\*(.*?)\*/', cpp_snippet, re.DOTALL):
        if not re.search(r'\b(struct|class)\s+\w+\s*\{', block):
            continue  # not a definition block (e.g. the "instantiated as such" note)

        # Drop the " * " decoration that doc-style blocks put on every line.
        lines = [re.sub(r'^\s*\*[ \t]?', '', ln) for ln in block.split('\n')]

        # Keep only the definition itself, dropping surrounding prose.
        start = next((i for i, ln in enumerate(lines)
                      if re.match(r'^\s*(struct|class)\s+\w+', ln)), None)
        end = next((i for i in range(len(lines) - 1, -1, -1)
                    if re.match(r'^\s*\};', lines[i])), None)
        if start is None or end is None or end < start:
            continue
        text = '\n'.join(lines[start:end + 1]).rstrip()
        # An interface — methods declared, never defined (NestedInteger,
        # MountainArray) — is the judge's; live, it would only fail to link.
        if is_interface(text):
            continue
        defs.append(text)
    return '\n\n'.join(defs)


def is_interface(definition):
    """Whether a class declares methods without bodies. Bodies are removed
    first, so `neighbors = vector<Node*>();` inside a constructor is not one."""
    body = re.sub(r'//.*', '', definition)
    body = body[body.find('{') + 1:body.rfind('}')]
    while True:
        stripped = re.sub(r'\{[^{}]*\}', '', body)
        if stripped == body:
            break
        body = stripped
    return re.search(r'\)\s*(?:const\s*)?;', body) is not None


def hidden_apis(cpp_snippet):
    """
    [(name, prototype)] for free functions the judge supplies — `int guess(int
    num);`, `bool isBadVersion(int version);` — found in the snippet's
    comments, outside any commented class and outside the usage note.
    """
    notes = [c for c in re.findall(r'//[^\n]*|/\*.*?\*/', cpp_snippet, re.DOTALL)
             if "instantiated" not in c and "called as such" not in c]
    text = re.sub(r'/\*+|\*+/', '\n', "\n".join(notes))
    text = re.sub(r'^[ \t]*(?://+|\*)[ \t]?', '', text, flags=re.MULTILINE)
    text = re.sub(r'\b(?:class|struct)\s+\w+[^;{]*\{.*?\n\s*\};', '', text, flags=re.DOTALL)
    out = []
    for m in re.finditer(r'^\s*((?:[\w:<>]+[\s*&]+)+(\w+)\s*\(([^()]*)\)\s*;)', text, re.MULTILINE):
        proto, name, params = m.group(1).strip(), m.group(2), m.group(3).strip()
        declared = params in ("", "void") or all(len(re.findall(r'\w+', p)) >= 2
                                                   for p in params.split(','))
        if declared and not name[0].isupper() and name not in [n for n, _ in out]:
            out.append((name, proto))
    return out


def split_decl(text):
    """'ListNode *head' → ('ListNode*', 'head');  'vector<int>& nums' → ('vector<int>', 'nums').
    Returns None when there is no name to split off (a constructor head, say).
    Pointer stars bind to the type however LeetCode spaced them."""
    t = re.sub(r'\bconst\b', '', text).replace('&', '').strip()
    t = re.sub(r'\s+', ' ', t)
    m = re.match(r'^(.+?)\s*(\*+)\s*(\w+)$', t)
    if m:
        return m.group(1).strip() + m.group(2), m.group(3)
    m = re.match(r'^(.+)\s+(\w+)$', t)
    if m:
        return m.group(1).strip(), m.group(2).strip()
    return None


def split_params(ps):
    """'int k, vector<int>& nums' → [('int','k'), ('vector<int>','nums')]"""
    ps = ps.strip()
    if not ps:
        return []
    parts, depth, cur = [], 0, ""
    for c in ps:
        if c in '<(':  depth += 1
        elif c in '>)': depth -= 1
        if c == ',' and depth == 0:
            parts.append(cur.strip()); cur = ""
        else:
            cur += c
    if cur.strip():
        parts.append(cur.strip())

    params = []
    for p in parts:
        d = split_decl(p)
        params.append(d if d else (re.sub(r'\s+', ' ', p.strip()), f"arg{len(params)}"))
    return params


# Every member function of the snippet class, at one indent (4 spaces, or the
# tab a few snippets use — 284). A constructor may carry an initialiser list:
# `PeekingIterator(const vector<int>& nums) : Iterator(nums) {`.
MEMBER_RE = re.compile(r'^(?: {4}|\t)([A-Za-z_~][^;(]*?)\(([^)]*)\)\s*(?:const\s*)?'
                       r'(?::[^{;]*)?\{', re.MULTILINE)


def parse_members(cpp_code):
    """Return [{kind, ret, name, params, sig}, ...] for the snippet's members.
    `sig` is the source text, so & / const / spacing survive verbatim."""
    out = []
    for m in MEMBER_RE.finditer(strip_block_comments(cpp_code)):
        head = m.group(1).strip()
        if head.startswith('~'):
            continue  # destructor
        sig = f"{head}({m.group(2)})".rstrip()
        hm = split_decl(head)
        if hm:
            out.append({"kind": "method", "ret": hm[0], "name": hm[1],
                        "params": split_params(m.group(2)), "sig": sig})
        else:
            out.append({"kind": "ctor", "ret": "", "name": head,
                        "params": split_params(m.group(2)), "sig": sig})
    return out


def parse_snippet(cpp_code):
    """Classify the snippet.  Returns (design_class_or_None, members)."""
    code = strip_block_comments(cpp_code)
    m = re.search(r'^\s*class\s+(\w+)\s*(?::[^{;]*)?\{', code, re.MULTILINE)   # `: public Iterator`
    cls = m.group(1) if m else None
    members = parse_members(cpp_code)
    if cls and cls != "Solution" and any(x["kind"] == "ctor" and x["name"] == cls for x in members):
        return cls, members
    return None, [x for x in members if x["kind"] == "method"]


def norm(t):
    return re.sub(r'\s+', '', t)   # "vector< int >" → "vector<int>"


# ─── C++ helpers embedded in every driver ─────────────────────────────────────

CPP_HELPERS = r"""
// ── token utils ───────────────────────────────────────────────────
static string _trim(const string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    return s.substr(a, s.find_last_not_of(" \t\r\n") - a + 1);
}
static string _unwrap(const string& s) {          // "[1,2]" → "1,2"
    string x = _trim(s);
    if (x.size() >= 2 && x.front() == '[' && x.back() == ']') return x.substr(1, x.size() - 2);
    return x;
}
static vector<string> _splitTop(const string& body) {   // split on depth-0 commas
    vector<string> out; int dep = 0; bool ins = false; string cur;
    for (size_t i = 0; i < body.size(); i++) {
        char c = body[i];
        if (c == '"' && (i == 0 || body[i-1] != '\\')) ins = !ins;
        if (!ins) {
            if (c == '[' || c == '{') dep++;
            else if (c == ']' || c == '}') dep--;
            else if (c == ',' && dep == 0) { out.push_back(cur); cur = ""; continue; }
        }
        cur += c;
    }
    if (!_trim(cur).empty()) out.push_back(cur);
    return out;
}
static string _join(const vector<string>& v) {           // ["1","2"] → "[1, 2]"
    string r = "[";
    for (size_t i = 0; i < v.size(); i++) { if (i) r += ", "; r += v[i]; }
    return r + "]";
}

// ── token → value ─────────────────────────────────────────────────
static int       _toI (const string& s) { return stoi(_trim(s)); }
static long long _toLL(const string& s) { return stoll(_trim(s)); }
static double    _toD (const string& s) { return stod(_trim(s)); }
static bool      _toB (const string& s) { string x = _trim(s); return x == "true" || x == "1"; }
static string    _toS (const string& s) {
    string x = _trim(s);
    if (x.size() >= 2 && x.front() == '"' && x.back() == '"') x = x.substr(1, x.size() - 2);
    return x;
}
static char      _toC (const string& s) { string x = _toS(s); return x.empty() ? ' ' : x[0]; }

template<class F> static auto _toV(const string& s, F f) -> vector<decltype(f(s))> {
    vector<decltype(f(s))> v;
    for (const string& t : _splitTop(_unwrap(s))) v.push_back(f(t));
    return v;
}
static vector<int>            _toVI (const string& s) { return _toV(s, _toI);  }
static vector<long long>      _toVLL(const string& s) { return _toV(s, _toLL); }
static vector<double>         _toVD (const string& s) { return _toV(s, _toD);  }
static vector<bool>           _toVB (const string& s) { return _toV(s, _toB);  }
static vector<char>           _toVC (const string& s) { return _toV(s, _toC);  }
static vector<string>         _toVS (const string& s) { return _toV(s, _toS);  }
static vector<vector<int>>    _toVVI(const string& s) { return _toV(s, _toVI); }
static vector<vector<long long>> _toVVLL(const string& s) { return _toV(s, _toVLL); }
static vector<vector<char>>   _toVVC(const string& s) { return _toV(s, _toVC); }
static vector<vector<string>> _toVVS(const string& s) { return _toV(s, _toVS); }

// ── line readers ──────────────────────────────────────────────────
// The raw line is echoed to stderr so run.sh can show the input of a failing
// case; debug.sh compiles with -DDEBUG and keeps stderr for your own prints.
static string _line() {
    string s; getline(cin, s);
#ifndef DEBUG
    cerr << s << "\n";
#endif
    return s;
}
static int       _ri()   { return _toI (_line()); }
static long long _rll()  { return _toLL(_line()); }
static double    _rd()   { return _toD (_line()); }
static bool      _rb()   { return _toB (_line()); }
static string    _rs()   { return _toS (_line()); }
static char      _rc()   { return _toC (_line()); }
static vector<int>            _rvi()  { return _toVI (_line()); }
static vector<long long>      _rvll() { return _toVLL(_line()); }
static vector<double>         _rvd()  { return _toVD (_line()); }
static vector<bool>           _rvb()  { return _toVB (_line()); }
static vector<char>           _rvc()  { return _toVC (_line()); }
static vector<string>         _rvs()  { return _toVS (_line()); }
static vector<vector<int>>    _rvvi() { return _toVVI(_line()); }
static vector<vector<long long>> _rvvll() { return _toVVLL(_line()); }
static vector<vector<char>>   _rvvc() { return _toVVC(_line()); }
static vector<vector<string>> _rvvs() { return _toVVS(_line()); }
static void _endCase() {
#ifndef DEBUG
    cerr << "---\n";
#endif
}
"""

# Extra printers, only needed by design drivers (output is a JSON-ish array).
CPP_JSON_PRINT = r"""
// ── value → JSON-ish token (design output) ────────────────────────
static void _pj(bool v)          { cout << (v ? "true" : "false"); }
static void _pj(int v)           { cout << v; }
static void _pj(long long v)     { cout << v; }
static void _pj(double v)        { cout << v; }
static void _pj(char v)          { cout << '"' << v << '"'; }
static void _pj(const string& v) { cout << '"' << v << '"'; }
static void _pj(const vector<bool>& v) {
    cout << '[';
    for (size_t i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << (v[i] ? "true" : "false"); }
    cout << ']';
}
template<class T> static void _pj(const vector<T>& v) {
    cout << '[';
    for (size_t i = 0; i < v.size(); i++) { if (i) cout << ", "; _pj(v[i]); }
    cout << ']';
}
"""


# Emitted only when the solution defines the struct AND a signature uses it.
CPP_TREE_HELPERS = r"""
// ── TreeNode ↔ [3,9,20,null,null,15,7] ────────────────────────────
static TreeNode* _toTree(const string& s) {
    vector<string> t = _splitTop(_unwrap(s));
    if (t.empty() || _trim(t[0]) == "null" || _trim(t[0]).empty()) return nullptr;
    TreeNode* root = new TreeNode(_toI(t[0]));
    queue<TreeNode*> q; q.push(root);
    size_t i = 1;
    while (!q.empty() && i < t.size()) {
        TreeNode* n = q.front(); q.pop();
        if (i < t.size()) { string v = _trim(t[i++]); if (v != "null") q.push(n->left  = new TreeNode(_toI(v))); }
        if (i < t.size()) { string v = _trim(t[i++]); if (v != "null") q.push(n->right = new TreeNode(_toI(v))); }
    }
    return root;
}
static string _sTree(TreeNode* root) {            // trailing nulls trimmed, like LeetCode
    vector<string> out; queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front(); q.pop();
        if (!n) { out.push_back("null"); continue; }
        out.push_back(to_string(n->val)); q.push(n->left); q.push(n->right);
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    string r = "[";
    for (size_t i = 0; i < out.size(); i++) { if (i) r += ", "; r += out[i]; }
    return r + "]";
}
static vector<TreeNode*> _toVTree(const string& s) {
    vector<TreeNode*> v;
    for (const string& t : _splitTop(_unwrap(s))) v.push_back(_toTree(t));
    return v;
}
static string _sVTree(const vector<TreeNode*>& v) {
    string r = "[";
    for (size_t i = 0; i < v.size(); i++) { if (i) r += ", "; r += _sTree(v[i]); }
    return r + "]";
}
static TreeNode*         _rtree()  { return _toTree (_line()); }
static vector<TreeNode*> _rvtree() { return _toVTree(_line()); }
"""

CPP_LIST_HELPERS = r"""
// ── ListNode ↔ [1,2,4] ────────────────────────────────────────────
static ListNode* _toList(const string& s) {
    ListNode head(0), *cur = &head;
    for (const string& t : _splitTop(_unwrap(s))) cur = cur->next = new ListNode(_toI(t));
    return head.next;
}
static string _sList(ListNode* h) {
    string r = "[";
    for (bool first = true; h; h = h->next, first = false) {
        if (!first) r += ", ";
        r += to_string(h->val);
    }
    return r + "]";
}
static vector<ListNode*> _toVList(const string& s) {
    vector<ListNode*> v;
    for (const string& t : _splitTop(_unwrap(s))) v.push_back(_toList(t));
    return v;
}
static string _sVList(const vector<ListNode*>& v) {
    string r = "[";
    for (size_t i = 0; i < v.size(); i++) { if (i) r += ", "; r += _sList(v[i]); }
    return r + "]";
}
static ListNode*         _rlist()  { return _toList (_line()); }
static vector<ListNode*> _rvlist() { return _toVList(_line()); }
"""

# ─── the many LeetCode `Node`s ────────────────────────────────────────────────
# LeetCode reuses the name Node for six different structures, each with its own
# notation. The fields of the definition tell them apart (most specific first),
# and every variant exposes the same three names — _toNode, _sNode, _rnode — so
# the reader/printer tables need only one entry for Node*.
NODE_KINDS = (
    ("neighbors", "graph"),
    ("children", "n-ary tree"),
    ("random", "random list"),
    ("child", "multilevel list"),
    ("topLeft", "quad tree"),
    ("next", "next pointers"),
)

NODE_VARIANT_HELPERS = {
    "graph": r"""
// ── graph Node ↔ adjacency list [[2,4],[1,3],...] — node k is row k-1 ──
static Node* _toNode(const string& s) {
    vector<vector<int>> adj = _toVVI(s);
    if (adj.empty()) return nullptr;
    vector<Node*> ns;
    for (size_t i = 0; i < adj.size(); i++) ns.push_back(new Node((int)i + 1));
    for (size_t i = 0; i < adj.size(); i++)
        for (int j : adj[i]) ns[i]->neighbors.push_back(ns[j - 1]);
    return ns[0];
}
static string _sNode(Node* start) {
    if (!start) return "[]";
    map<int, Node*> seen{{start->val, start}};
    queue<Node*> q; q.push(start);
    while (!q.empty()) {
        Node* n = q.front(); q.pop();
        for (Node* m : n->neighbors) if (m && !seen.count(m->val)) { seen[m->val] = m; q.push(m); }
    }
    vector<string> rows;
    for (auto& [v, n] : seen) {
        vector<string> nb;
        for (Node* m : n->neighbors) nb.push_back(to_string(m->val));
        rows.push_back(_join(nb));
    }
    return _join(rows);
}
""",
    "n-ary tree": r"""
// ── n-ary Node ↔ [1,null,3,2,4,null,5,6] — null closes a child group ──
static Node* _toNode(const string& s) {
    vector<string> t = _splitTop(_unwrap(s));
    if (t.empty() || _trim(t[0]) == "null") return nullptr;
    Node* root = new Node(_toI(t[0]));
    queue<Node*> q; q.push(root);
    size_t i = 2;                                   // t[1] is the null after the root
    while (!q.empty() && i < t.size()) {
        Node* p = q.front(); q.pop();
        for (; i < t.size() && _trim(t[i]) != "null"; i++) {
            Node* c = new Node(_toI(t[i]));
            p->children.push_back(c); q.push(c);
        }
        i++;
    }
    return root;
}
static string _sNode(Node* root) {
    if (!root) return "[]";
    vector<string> out{to_string(root->val), "null"};
    queue<Node*> q; q.push(root);
    while (!q.empty()) {
        Node* p = q.front(); q.pop();
        for (Node* c : p->children) { out.push_back(to_string(c->val)); q.push(c); }
        out.push_back("null");
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    return _join(out);
}
""",
    "next pointers": r"""
// ── Node{left,right,next}: level order in, [1,#,2,3,#] out ───────────
static Node* _toNode(const string& s) {
    vector<string> t = _splitTop(_unwrap(s));
    if (t.empty() || _trim(t[0]) == "null") return nullptr;
    Node* root = new Node(_toI(t[0]));
    queue<Node*> q; q.push(root);
    size_t i = 1;
    while (!q.empty() && i < t.size()) {
        Node* n = q.front(); q.pop();
        if (i < t.size()) { string v = _trim(t[i++]); if (v != "null") q.push(n->left  = new Node(_toI(v))); }
        if (i < t.size()) { string v = _trim(t[i++]); if (v != "null") q.push(n->right = new Node(_toI(v))); }
    }
    return root;
}
static string _sNode(Node* root) {                  // walk each level along next
    vector<string> out;
    for (Node* level = root; level; ) {
        Node* below = nullptr;
        for (Node* n = level; n; n = n->next) {
            out.push_back(to_string(n->val));
            if (!below) below = n->left ? n->left : n->right;
        }
        out.push_back("#");
        level = below;
    }
    return _join(out);
}
""",
    "random list": r"""
// ── Node{next,random} ↔ [[7,null],[13,0],...] ──────────────────────
static Node* _toNode(const string& s) {
    vector<string> rows = _splitTop(_unwrap(s));
    vector<Node*> ns;
    for (const string& r : rows) ns.push_back(new Node(_toI(_splitTop(_unwrap(r))[0])));
    for (size_t i = 0; i < ns.size(); i++) {
        if (i + 1 < ns.size()) ns[i]->next = ns[i + 1];
        string idx = _trim(_splitTop(_unwrap(rows[i]))[1]);
        if (idx != "null") ns[i]->random = ns[stoi(idx)];
    }
    return ns.empty() ? nullptr : ns[0];
}
static string _sNode(Node* head) {
    unordered_map<Node*, int> at; int k = 0;
    for (Node* n = head; n; n = n->next) at[n] = k++;
    vector<string> out;
    for (Node* n = head; n; n = n->next)
        out.push_back("[" + to_string(n->val) + ", " +
                      (n->random ? to_string(at[n->random]) : string("null")) + "]");
    return _join(out);
}
""",
    "multilevel list": r"""
// ── Node{prev,next,child} ↔ [1,2,3,null,null,4,5] — k nulls: child of node k-1 ──
static Node* _toNode(const string& s) {
    vector<string> t = _splitTop(_unwrap(s));
    size_t i = 0;
    auto level = [&]() {                            // values up to the next null
        vector<Node*> r;
        for (; i < t.size() && _trim(t[i]) != "null"; i++) {
            Node* n = new Node();
            n->val = _toI(t[i]); n->prev = n->next = n->child = nullptr;
            if (!r.empty()) { r.back()->next = n; n->prev = r.back(); }
            r.push_back(n);
        }
        return r;
    };
    vector<Node*> above = level();
    Node* head = above.empty() ? nullptr : above[0];
    while (i < t.size()) {
        size_t nulls = 0;
        while (i < t.size() && _trim(t[i]) == "null") { nulls++; i++; }
        vector<Node*> below = level();
        if (below.empty() || nulls == 0 || nulls > above.size()) break;
        above[nulls - 1]->child = below[0];
        above = below;
    }
    return head;
}
static string _sNode(Node* head) {                  // the flattened list, along next
    vector<string> out;
    for (Node* n = head; n; n = n->next) out.push_back(to_string(n->val));
    return _join(out);
}
""",
    "quad tree": r"""
// ── quad-tree Node ↔ [[isLeaf,val],...] level order, null for no node ──
static Node* _quadAt(const string& tok) {
    string x = _trim(tok);
    if (x == "null" || x.empty()) return nullptr;
    vector<int> p = _toVI(x);
    return new Node(p[1], p[0]);                    // Node(val, isLeaf)
}
static Node* _toNode(const string& s) {
    vector<string> t = _splitTop(_unwrap(s));
    Node* root = t.empty() ? nullptr : _quadAt(t[0]);
    queue<Node*> q; if (root) q.push(root);
    size_t i = 1;
    while (!q.empty() && i < t.size()) {
        Node* n = q.front(); q.pop();
        for (Node** k : {&n->topLeft, &n->topRight, &n->bottomLeft, &n->bottomRight})
            if (i < t.size()) { *k = _quadAt(t[i++]); if (*k) q.push(*k); }
    }
    return root;
}
static string _sNode(Node* root) {
    vector<string> out; queue<Node*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        Node* n = q.front(); q.pop();
        if (!n) { out.push_back("null"); continue; }
        // A non-leaf's val is "either is accepted", so it is not compared.
        out.push_back(n->isLeaf ? "[1, " + to_string((int)n->val) + "]" : string("[0, *]"));
        for (Node* c : {n->topLeft, n->topRight, n->bottomLeft, n->bottomRight})
            q.push(n->isLeaf ? nullptr : c);
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    return _join(out);
}
""",
}
_NODE_READER = r"""static Node* _rnode() { return _toNode(_line()); }
"""

# ─── judge-supplied classes ───────────────────────────────────────────────────
# Interfaces the judge implements. The mock goes in the driver *before* the
# #include: defining it in {N}.cpp compiles locally but is a redefinition the
# moment the file is submitted.
CPP_NESTED_MOCK = r"""
// ── NestedInteger — the judge's interface, mocked ────────────────────
class NestedInteger {
    bool _isInt = false; int _v = 0; vector<NestedInteger> _list;
public:
    NestedInteger() {}
    NestedInteger(int value) : _isInt(true), _v(value) {}
    bool isInteger() const { return _isInt; }
    int getInteger() const { return _v; }
    void setInteger(int value) { _isInt = true; _v = value; _list.clear(); }
    void add(const NestedInteger& ni) { _isInt = false; _list.push_back(ni); }
    const vector<NestedInteger>& getList() const { return _list; }
};
"""
CPP_NESTED_HELPERS = r"""
// ── NestedInteger ↔ [1,[4,[6]]] ───────────────────────────────────────
static NestedInteger _toNI(const string& s) {
    string x = _toS(s);                             // "[123,[456]]" arrives quoted in 385
    if (x.empty() || x[0] != '[') return NestedInteger(stoi(x));
    NestedInteger ni;
    for (const string& t : _splitTop(_unwrap(x))) ni.add(_toNI(t));
    return ni;
}
static vector<NestedInteger> _toVNI(const string& s) { return _toNI(s).getList(); }
static string _sNI(const NestedInteger& ni) {
    if (ni.isInteger()) return to_string(ni.getInteger());
    vector<string> out;
    for (const NestedInteger& c : ni.getList()) out.push_back(_sNI(c));
    return _join(out);
}
static string _sVNI(const vector<NestedInteger>& v) {
    vector<string> out;
    for (const NestedInteger& c : v) out.push_back(_sNI(c));
    return _join(out);
}
static NestedInteger         _rni()  { return _toNI (_line()); }
static vector<NestedInteger> _rvni() { return _toVNI(_line()); }
"""
CPP_ITERATOR_MOCK = r"""
// ── Iterator — the judge's base class, mocked ────────────────────────
class Iterator {
    struct Data { vector<int> v; size_t i = 0; };
    Data* d;
public:
    Iterator(const vector<int>& nums) : d(new Data{nums}) {}
    Iterator(const Iterator& iter) : d(new Data(*iter.d)) {}
    virtual ~Iterator() { delete d; }
    int next() { return d->v[d->i++]; }
    bool hasNext() const { return d->i < d->v.size(); }
};
"""

#: Hidden APIs with known semantics: each is backed by one extra input line
#: per test case (`n` then `pick` for guess), read after the visible arguments.
HIDDEN_APIS = {
    "guess": ("_pick", "int guess(int num) { return num > _pick ? -1 : num < _pick ? 1 : 0; }"),
    "isBadVersion": ("_bad", "bool isBadVersion(int version) { return version >= _bad; }"),
    "rand7": (None, "int rand7() { return rand() % 7 + 1; }"),
}

# type → the function that renders it as a LeetCode-style bracket literal
NODE_SERIALIZERS = {
    "TreeNode*": "_sTree",  "vector<TreeNode*>": "_sVTree",
    "ListNode*": "_sList",  "vector<ListNode*>": "_sVList",
    "Node*": "_sNode",
    "NestedInteger": "_sNI", "vector<NestedInteger>": "_sVNI",
}
NODE_STRUCTS = {"TreeNode": "CPP_TREE_HELPERS", "ListNode": "CPP_LIST_HELPERS", "Node": None}


def node_kind(solution_src):
    """Which LeetCode Node this is, from its fields — None when not one we know."""
    m = re.search(r'\b(?:struct|class)\s+Node\b[^{;]*\{(.*?)\n\s*\};', solution_src, re.S)
    if not m:
        return None
    return next((k for f, k in NODE_KINDS if re.search(r'\b%s\b' % f, m.group(1))), None)


def needed_nodes(solution_src, members):
    """Which node helper blocks this driver needs: the struct must appear in a
    signature AND be defined in {N}.cpp, or the helpers would not compile.
    A Node additionally has to be a variant with known notation."""
    used = " ".join(norm(t) for mem in members
                    for t in [x[0] for x in mem["params"]] + [mem["ret"]])
    return [s for s in NODE_STRUCTS
            if re.search(r'\b%s\b' % s, used)
            and re.search(r'\b(struct|class)\s+%s\b' % s, solution_src)
            and (s != "Node" or node_kind(solution_src))]


def node_helpers(nodes, solution_src=""):
    blocks = {"TreeNode": CPP_TREE_HELPERS, "ListNode": CPP_LIST_HELPERS}
    out = ''.join(blocks[n] for n in nodes if n in blocks)
    if "Node" in nodes:
        out += NODE_VARIANT_HELPERS[node_kind(solution_src)] + _NODE_READER
    return out


READERS = {
    "int": "_ri", "longlong": "_rll", "int64_t": "_rll",
    "double": "_rd", "float": "_rd", "bool": "_rb",
    "string": "_rs", "char": "_rc",
    "vector<int>": "_rvi", "vector<longlong>": "_rvll", "vector<int64_t>": "_rvll",
    "vector<double>": "_rvd", "vector<bool>": "_rvb", "vector<char>": "_rvc",
    "vector<string>": "_rvs",
    "vector<vector<int>>": "_rvvi", "vector<vector<char>>": "_rvvc",
    "vector<vector<string>>": "_rvvs", "vector<vector<longlong>>": "_rvvll",
    "TreeNode*": "_rtree", "ListNode*": "_rlist",
    "vector<TreeNode*>": "_rvtree", "vector<ListNode*>": "_rvlist",
    "Node*": "_rnode",
    "NestedInteger": "_rni", "vector<NestedInteger>": "_rvni",
}

CONVERTERS = {
    "int": "_toI", "longlong": "_toLL", "int64_t": "_toLL",
    "double": "_toD", "float": "_toD", "bool": "_toB",
    "string": "_toS", "char": "_toC",
    "vector<int>": "_toVI", "vector<longlong>": "_toVLL", "vector<int64_t>": "_toVLL",
    "vector<double>": "_toVD", "vector<bool>": "_toVB", "vector<char>": "_toVC",
    "vector<string>": "_toVS",
    "vector<vector<int>>": "_toVVI", "vector<vector<char>>": "_toVVC",
    "vector<vector<string>>": "_toVVS", "vector<vector<longlong>>": "_toVVLL",
    "TreeNode*": "_toTree", "ListNode*": "_toList",
    "vector<TreeNode*>": "_toVTree", "vector<ListNode*>": "_toVList",
    "Node*": "_toNode",
    "NestedInteger": "_toNI", "vector<NestedInteger>": "_toVNI",
}

_STRUCT_IN = re.compile(r'\b(TreeNode|ListNode|Node|NestedInteger)\b')


def usable(t, have):
    """A structure type only has a reader/printer when its helper block is in
    the driver — `have` names the ones that are. Plain types always do."""
    m = _STRUCT_IN.search(t)
    return not m or m.group(1) in have


def read_call(ptype, pname, have=()):
    """One input line → a named local of type `ptype`."""
    fn = READERS.get(norm(ptype))
    if fn and usable(ptype, have):
        return [f"{ptype} {pname} = {fn}();"]
    # Unknown type: still consume the line so later reads stay aligned.
    return [f"// TODO: parse {ptype} {pname} from this line",
            f"{ptype} {pname}{{}}; _line();"]


def conv_call(ptype, pname, expr, have=()):
    """One already-split token → a named local of type `ptype`."""
    fn = CONVERTERS.get(norm(ptype))
    if fn and usable(ptype, have):
        return [f"{ptype} {pname} = {fn}({expr});"]
    return [f"// TODO: parse {ptype} {pname} from {expr}",
            f"{ptype} {pname}{{}};"]


def print_call(return_type, var="_res", have=()):
    """Plain-driver output: one line per case, space-separated."""
    t = norm(return_type)
    if t in NODE_SERIALIZERS and usable(t, have):
        return f'cout << {NODE_SERIALIZERS[t]}({var}) << "\\n";'
    if t == "vector<bool>":                     # LeetCode's own form: [true,false]
        return (f'cout << "[";for (int _i=0;_i<(int){var}.size();_i++){{if(_i)cout<<",";'
                f'cout<<({var}[_i]?"true":"false");}}cout<<"]\\n";')
    if t == "bool":
        return f'cout << ({var} ? "true" : "false") << "\\n";'
    if t in ("double", "float"):
        # LeetCode prints doubles with five fixed decimals ("2.00000"), which is
        # what the fetched _expected.txt contains; default precision gives "2".
        return f'cout << fixed << setprecision(5) << {var} << "\\n";'
    if t in ("int", "longlong", "int64_t", "string", "char"):
        return f'cout << {var} << "\\n";'
    if t == "vector<double>":
        return (f'cout << fixed << setprecision(5);'
                f'for (int _i=0;_i<(int){var}.size();_i++){{if(_i)cout<<" ";cout<<{var}[_i];}}cout<<"\\n";')
    if t in ("vector<int>", "vector<longlong>", "vector<int64_t>",
             "vector<string>", "vector<char>"):
        return (f'for (int _i=0;_i<(int){var}.size();_i++){{if(_i)cout<<" ";cout<<{var}[_i];}}cout<<"\\n";')
    if t in ("vector<vector<int>>", "vector<vector<char>>", "vector<vector<string>>",
             "vector<vector<longlong>>"):
        return (f'for(auto&_row:{var}){{for(int _i=0;_i<(int)_row.size();_i++)'
                f'{{if(_i)cout<<" ";cout<<_row[_i];}}cout<<"\\n";}}')
    return f'// TODO: print result\n        cout << "TODO\\n";'


# ─── Example / expected-output parsing ────────────────────────────────────────

def strip_html(html):
    for e, c in [('&lt;','<'),('&gt;','>'),('&amp;','&'),('&nbsp;',' '),
                 ('&quot;','"'),('&#39;',"'"),('&le;','≤'),('&ge;','≥')]:
        html = html.replace(e, c)
    return re.sub(r'<[^>]+>', '\n', html)


def split_top(body):
    """Python twin of the driver's _splitTop."""
    out, dep, ins, cur = [], 0, False, ""
    for i, c in enumerate(body):
        if c == '"' and (i == 0 or body[i-1] != '\\'):
            ins = not ins
        if not ins:
            if c in '[{':
                dep += 1
            elif c in ']}':
                dep -= 1
            elif c == ',' and dep == 0:
                out.append(cur); cur = ""; continue
        cur += c
    if cur.strip():
        out.append(cur)
    return out


def norm_json(tok):
    """Canonicalise spacing so expected output matches what the driver prints."""
    tok = tok.strip()
    if tok.startswith('[') and tok.endswith(']'):
        return '[' + ', '.join(norm_json(x) for x in split_top(tok[1:-1])) + ']'
    return tok


def parse_outputs(content_html, return_type, design=False):
    text = strip_html(content_html)
    lines = [l.strip() for l in text.split('\n') if l.strip()]
    outputs = []
    for i, line in enumerate(lines):
        # "Output: value" on the same line
        m = re.match(r'[Oo]utput\s*[=:]\s*(.+)', line)
        if m:
            outputs.append(convert_output(m.group(1).strip(), return_type, design))
            continue
        # "Output:" label with the value on the next line
        if re.match(r'^[Oo]utput\s*:?\s*$', line) and i + 1 < len(lines):
            outputs.append(convert_output(lines[i + 1].strip(), return_type, design))
    return outputs


def convert_output(raw, return_type, design=False):
    """Convert LeetCode output notation to what the driver prints."""
    raw = raw.strip()
    if design:
        return norm_json(raw)
    t = norm(return_type)
    if t in NODE_SERIALIZERS:
        return norm_json(raw)
    if t in ("int", "longlong", "int64_t", "double", "float", "bool"):
        return raw
    if t in ("string", "char"):
        return raw.strip('"')
    if t == "vector<bool>":
        return '[' + ','.join(re.findall(r'true|false', raw)) + ']'
    if t in ("vector<int>", "vector<longlong>", "vector<int64_t>"):
        return ' '.join(re.findall(r'-?\d+', raw))
    if t == "vector<double>":
        return ' '.join(re.findall(r'-?\d+(?:\.\d+)?', raw))
    if t in ("vector<string>", "vector<char>"):
        return ' '.join(re.findall(r'"([^"]*)"', raw))
    if t in ("vector<vector<int>>", "vector<vector<longlong>>"):
        return '\n'.join(' '.join(re.findall(r'-?\d+', row))
                         for row in re.findall(r'\[([^\[\]]*)\]', raw))
    if t in ("vector<vector<string>>", "vector<vector<char>>"):
        return '\n'.join(' '.join(re.findall(r'"([^"]*)"', row))
                         for row in re.findall(r'\[([^\[\]]*)\]', raw))
    return raw


# ─── File builders ────────────────────────────────────────────────────────────

def build_solution_cpp(num, slug, cpp_snippet, design_cls, members, apis=()):
    """Skeleton solution file: link header, node definitions, hidden-API
    declarations, empty class."""
    link = f"https://leetcode.com/problems/{slug}/description/"
    header = (f"// Link: {link}\n"
              f"\n"
              f"#include <bits/stdc++.h>\n"
              f"using namespace std;\n"
              f"\n")

    # Node definitions must be live (not commented) for the file to compile.
    defs = extract_definitions(cpp_snippet)
    defs_block = f"{defs}\n\n" if defs else ""
    # `int guess(int num);` — a redeclaration the judge accepts, and what lets
    # the solution call the API it is given.
    if apis:
        defs_block += "\n".join(proto for _, proto in apis) + "\n\n"

    if design_cls:
        # Keep LeetCode's own class body — it already has the right members and
        # empty bodies; only the surrounding comment blocks need to go.
        body = strip_block_comments(cpp_snippet).strip()
        body = re.sub(r'\n{3,}', '\n\n', body) + "\n"
        return header + defs_block + body

    sig = members[0]["sig"] if members else "// TODO: paste function signature"
    return (header + defs_block +
            f"class Solution {{\n"
            f"public:\n"
            f"    {sig} {{\n"
            f"        \n"
            f"    }}\n"
            f"}};\n")


class Env:
    """What a driver carries beyond the standard helpers, decided by the code type."""

    def __init__(self):
        self.have = set()        # structures whose reader/printer is in the driver
        self.pre = ""            # judge mocks — before the #include
        self.helpers = ""        # readers/printers for those structures
        self.post = ""           # hidden-API definitions
        self.backing = []        # per-case globals behind the hidden APIs
        self.notes = []          # what is left for a human, as WARNING lines


def environment(cpp, solution_src, members, design_cls, apis):
    """
    Match the driver to the code type: node helpers for whichever TreeNode,
    ListNode or Node variant crosses the signature, a NestedInteger or Iterator
    mock, definitions behind hidden APIs — and a note for anything unmet.
    """
    env = Env()
    nodes = needed_nodes(solution_src, members)
    env.have.update(nodes)
    env.helpers = node_helpers(nodes, solution_src)
    used = " ".join(norm(t) for m in members for t in [x[0] for x in m["params"]] + [m["ret"]])

    if re.search(r'\bNestedInteger\b', used):
        env.pre += CPP_NESTED_MOCK
        env.helpers += CPP_NESTED_HELPERS
        env.have.add("NestedInteger")
    if design_cls and re.search(r'\bclass\s+%s\s*:\s*(?:public\s+)?Iterator\b' % design_cls, cpp):
        env.pre += CPP_ITERATOR_MOCK

    for name, proto in apis:
        if name in HIDDEN_APIS:
            var, definition = HIDDEN_APIS[name]
            if var:
                env.post += f"static int {var};\n"
                env.backing.append(var)
            env.post += definition + "\n"
        else:
            env.notes.append(f"hidden API {name}(): define `{proto}` in the driver")

    if re.search(r'\bNode\b', used) and "Node" not in nodes:
        env.notes.append("Node: not a variant with a known notation — the driver has TODOs")
    known = {"TreeNode", "ListNode", "Node", "NestedInteger", design_cls or "Solution"}
    for t in sorted(set(re.findall(r'\b([A-Z]\w+)\b', used)) - known):
        if not re.search(r'\b(struct|class)\s+%s\b' % t, solution_src):
            env.notes.append(f"interface {t}: the judge's class — mock it in the "
                             f"driver, before the #include")
    return env


def build_driver(num, member, env=None):
    """Plain driver: read args, call Solution::f once, print the result."""
    env = env or Env()
    reads = []
    for t, n in member["params"]:
        reads += read_call(t, n, env.have)
    reads += [f"{var} = _ri();   // backs the hidden API" for var in env.backing]
    read_block = '\n'.join(f"        {l}" for l in reads) or "        // (no args)"
    args = ', '.join(n for _, n in member["params"])

    if norm(member["ret"]) == "void":
        call = f"        Solution sol;\n        sol.{member['name']}({args});"
        out  = ""
    else:
        call = f"        Solution sol;\n        auto _res = sol.{member['name']}({args});"
        out  = f"        {print_call(member['ret'], have=env.have)}"

    return f"""#include <bits/stdc++.h>
using namespace std;
{env.pre}#include "{num}.cpp"
{CPP_HELPERS}{env.helpers}{env.post}
int main() {{
    string _t; getline(cin, _t);
    int _T = stoi(_trim(_t));
    while (_T--) {{
{read_block}
{call}
{out}
        _endCase();
    }}
    return 0;
}}
"""


def build_design_driver(num, cls, members, env=None):
    """Design driver: replay the ops/args script and print [null, x, y, ...]."""
    env = env or Env()
    branches = []
    for mem in members:
        decls = []
        for j, (t, n) in enumerate(mem["params"]):
            decls += conv_call(t, n, f"_a[{j}]", env.have)
        body = '\n'.join(f"                {l}" for l in decls)
        args = ', '.join(n for _, n in mem["params"])

        if mem["kind"] == "ctor":
            action = (f"                delete _obj;\n"
                      f"                _obj = new {cls}({args});\n"
                      f'                cout << "null";')
        elif norm(mem["ret"]) == "void":
            action = (f"                _obj->{mem['name']}({args});\n"
                      f'                cout << "null";')
        else:
            call = f"_obj->{mem['name']}({args})"
            ser = NODE_SERIALIZERS.get(norm(mem["ret"])) if usable(mem["ret"], env.have) else None
            emit = f"cout << {ser}({call});" if ser else f"_pj({call});"
            action = f"                {emit}"

        head = "if" if not branches else "} else if"
        branches.append(f"            {head} (_op == \"{mem['name']}\") {{\n"
                        + (body + "\n" if body else "") + action)

    dispatch = '\n'.join(branches) + (
        "\n            } else {\n"
        "                cerr << \"unknown op: \" << _op << \"\\n\";\n"
        "                cout << \"null\";\n"
        "            }" if branches else "")

    return f"""#include <bits/stdc++.h>
using namespace std;
{env.pre}#include "{num}.cpp"
{CPP_HELPERS}{env.helpers}{env.post}{CPP_JSON_PRINT}
int main() {{
    string _t; getline(cin, _t);
    int _T = stoi(_trim(_t));
    while (_T--) {{
        vector<string> _ops = _rvs();
        vector<vector<string>> _args;
        for (const string& _g : _splitTop(_unwrap(_line()))) _args.push_back(_splitTop(_unwrap(_g)));

        {cls}* _obj = nullptr;
        cout << "[";
        for (size_t _k = 0; _k < _ops.size(); _k++) {{
            if (_k) cout << ", ";
            const string& _op = _ops[_k];
            vector<string> _a = _k < _args.size() ? _args[_k] : vector<string>();
{dispatch}
        }}
        cout << "]\\n";
        delete _obj;
        _endCase();
    }}
    return 0;
}}
"""


def build_drain_driver(num, cls, ctor, env=None):
    """
    Iterator driver, for classes LeetCode drives as `X i(args); while
    (i.hasNext()) out.push_back(i.next());` — the input is the constructor's
    arguments, not an ops script, and the output is everything next() gave.
    """
    env = env or Env()
    reads = []
    for t, n in ctor["params"]:
        reads += read_call(t, n, env.have)
    read_block = '\n'.join(f"        {l}" for l in reads)
    args = ', '.join(n for _, n in ctor["params"])
    return f"""#include <bits/stdc++.h>
using namespace std;
{env.pre}#include "{num}.cpp"
{CPP_HELPERS}{env.helpers}{env.post}
int main() {{
    string _t; getline(cin, _t);
    int _T = stoi(_trim(_t));
    while (_T--) {{
{read_block}
        {cls} _it({args});
        vector<string> _out;
        while (_it.hasNext()) _out.push_back(to_string(_it.next()));
        cout << _join(_out) << "\\n";
        _endCase();
    }}
    return 0;
}}
"""


_ROUNDTRIP = re.compile(r'(\w+)\s*(?:\.|->)\s*(\w+)\s*\(\s*(\w+)\s*(?:\.|->)\s*(\w+)\s*\(')


def roundtrip(cpp, members):
    """
    (inner, outer, shared) for classes LeetCode drives as a round trip —
    `deser.deserialize(ser.serialize(root))` (Codec, two objects),
    `solution.decode(solution.encode(url))` (one object, state may be kept in
    it) — read off the usage note, nested or as two statements.
    """
    methods = {m["name"]: m for m in members if m["kind"] == "method"}
    if len(methods) != 2:
        return None
    for note in re.findall(r'/\*.*?\*/|(?://[^\n]*\n?)+', cpp, re.DOTALL):
        m = _ROUNDTRIP.search(note)
        if m and m.group(2) in methods and m.group(4) in methods:
            return methods[m.group(4)], methods[m.group(2)], m.group(1) == m.group(3)
        order = sorted((note.find(n + "("), n) for n in methods if note.find(n + "(") >= 0)
        if len(order) == 2:
            return methods[order[0][1]], methods[order[1][1]], False
    return None


def build_roundtrip_driver(num, cls, inner, outer, shared=False, env=None):
    """Round-trip driver: feed each case through inner, then outer, print outer's result."""
    env = env or Env()
    objects = f"{cls} _a; {cls}& _b = _a;" if shared else f"{cls} _a, _b;"
    reads = []
    for t, n in inner["params"]:
        reads += read_call(t, n, env.have)
    read_block = '\n'.join(f"        {l}" for l in reads)
    args = ', '.join(n for _, n in inner["params"])
    return f"""#include <bits/stdc++.h>
using namespace std;
{env.pre}#include "{num}.cpp"
{CPP_HELPERS}{env.helpers}{env.post}
int main() {{
    string _t; getline(cin, _t);
    int _T = stoi(_trim(_t));
    while (_T--) {{
{read_block}
        {objects}
        auto _res = _b.{outer['name']}(_a.{inner['name']}({args}));
        {print_call(outer['ret'], have=env.have)}
        _endCase();
    }}
    return 0;
}}
"""


def build_concurrency_driver(num, cls):
    """
    Concurrency problems (methods taking function<void()> callbacks) each need
    their own thread harness; this driver compiles, says so, and fails loudly
    rather than replaying an ops script that does not exist.
    """
    return f"""#include <bits/stdc++.h>
using namespace std;
#include "{num}.cpp"
{CPP_HELPERS}
int main() {{
    // TODO: concurrency harness for {cls} — start one thread per method, give
    // each function<void()> callback a lambda that appends its output to a
    // mutex-guarded string, join the threads, print the string per case.
    cerr << "{cls}: concurrency harness not written yet — see {num}_driver.cpp\\n";
    return 1;
}}
"""


def build_input(example_testcases, lines_per_case):
    lines = [l for l in example_testcases.strip().split('\n') if l.strip()]
    tc = case_count(example_testcases, lines_per_case)
    return str(tc) + '\n' + '\n'.join(lines) + '\n'


def build_debug(example_testcases, lines_per_case):
    """First example test case only, for use with debug.sh."""
    lines = [l for l in example_testcases.strip().split('\n') if l.strip()]
    return '1\n' + '\n'.join(lines[:max(1, lines_per_case)]) + '\n'


def case_count(example_testcases, lines_per_case):
    lines = [l for l in example_testcases.strip().split('\n') if l.strip()]
    return max(1, len(lines) // lines_per_case) if lines_per_case else 1


# ─── Main ─────────────────────────────────────────────────────────────────────

_DRAIN = re.compile(r'while\s*\(\s*\w+\s*\.\s*hasNext\s*\(\s*\)\s*\)')


def generate(num, data, work_dir):
    """
    Write the five scaffold files for problem `num` into `work_dir` from its
    LeetCode data (content, exampleTestcases, codeSnippets, slug). The driver
    is matched to the code type — see environment(). Raises RuntimeError when
    the snippet has no signature to work from.
    """
    # `.get(k, default)` does not apply the default when the key exists with a
    # null value, which is what LeetCode returns for premium problems.
    cpp = next((s["code"] for s in (data.get("codeSnippets") or []) if s["langSlug"] == "cpp"), "")
    design_cls, members = parse_snippet(cpp)
    if not members:
        raise RuntimeError("Could not parse C++ signature")
    apis = hidden_apis(cpp)
    solution_src = build_solution_cpp(num, data["slug"], cpp, design_cls, members, apis)
    env = environment(cpp, solution_src, members, design_cls, apis)

    ctor = next((m for m in members if m["kind"] == "ctor"), None)
    concurrency = any("function<" in norm(t) for m in members for t, _ in m["params"])
    rt = None if design_cls else roundtrip(cpp, members)
    if rt:
        inner, outer, shared = rt
        cls = re.search(r'^\s*class\s+(\w+)', strip_block_comments(cpp), re.MULTILINE).group(1)
        print(f"      Round trip: {cls}.{outer['name']}({cls}.{inner['name']}(...))")
        ret, lines_per_case = outer["ret"], max(1, len(inner["params"]))
        driver = build_roundtrip_driver(num, cls, inner, outer, shared, env)
    elif design_cls and concurrency:
        print(f"      Concurrency class: {design_cls}")
        ret, lines_per_case = "", 1
        driver = build_concurrency_driver(num, design_cls)
        env.notes.append(f"concurrency: {num}_driver.cpp needs a thread harness for {design_cls}")
    elif design_cls and ctor and _DRAIN.search(cpp):
        print(f"      Iterator class: {design_cls} (drained with hasNext/next)")
        ret, lines_per_case = "", max(1, len(ctor["params"]))
        driver = build_drain_driver(num, design_cls, ctor, env)
    elif design_cls:
        print(f"      Design class: {design_cls}")
        for mem in members:
            kind = "ctor  " if mem["kind"] == "ctor" else "method"
            print(f"        {kind} {mem['sig']}")
        ret, lines_per_case = "", 2
        driver = build_design_driver(num, design_cls, members, env)
    else:
        mem = members[0]
        ret, lines_per_case = mem["ret"], len(mem["params"]) + len(env.backing)
        print(f"      Signature: {mem['sig']}")
        driver = build_driver(num, mem, env)
    for name, _ in apis:
        print(f"      Hidden API: {name}()")

    examples_raw = data.get("exampleTestcases", "")
    content_html = data.get("content", "")
    tc_count = case_count(examples_raw, lines_per_case)

    print(f"[2/3] Parsing {tc_count} example test case(s)...")
    expected = parse_outputs(content_html, ret, design=bool(design_cls))
    if "Node" in env.have and node_kind(solution_src) == "quad tree":
        expected = [re.sub(r'\[0, [01]\]', '[0, *]', e) for e in expected]

    print("[3/3] Writing files...")

    def write(name, text):
        with open(os.path.join(work_dir, name), 'w') as f:
            f.write(text)

    write(f"{num}.cpp", solution_src)
    print(f"      {num}.cpp")

    write(f"{num}_driver.cpp", driver)
    print(f"      {num}_driver.cpp")
    for note in env.notes:
        print(f"WARNING: {note}")

    write(f"{num}_input.txt", build_input(examples_raw, lines_per_case))
    print(f"      {num}_input.txt  ({tc_count} case(s))")

    if expected:
        write(f"{num}_expected.txt", '\n'.join(expected[:tc_count]) + '\n')
        print(f"      {num}_expected.txt  ({len(expected[:tc_count])} outputs)")
        if len(expected) < tc_count:
            print(f"WARNING: only {len(expected)} expected output(s) for {tc_count} case(s)"
                  f" — check {num}_expected.txt")
    else:
        write(f"{num}_expected.txt", "# TODO: add expected outputs manually\n")
        print(f"WARNING: could not auto-parse expected output — fill {num}_expected.txt manually")

    write(f"{num}_debug.txt", build_debug(examples_raw, lines_per_case))
    print(f"      {num}_debug.txt")


def main():
    if len(sys.argv) < 2:
        print("Usage: fetch_problem.py <number>")
        sys.exit(1)

    num = sys.argv[1]
    work_dir = os.path.dirname(os.path.abspath(__file__))

    print(f"[1/3] Fetching problem {num} from LeetCode...")
    try:
        data = fetch_problem(num)
    except Exception as e:
        print(f"ERROR: {e}")
        sys.exit(1)
    print(f"      {data['title']}")

    try:
        generate(num, data, work_dir)
    except RuntimeError as e:
        print(f"ERROR: {e}")
        sys.exit(1)
    print(f"\nDone. Problem {num} is ready.")


if __name__ == "__main__":
    main()
