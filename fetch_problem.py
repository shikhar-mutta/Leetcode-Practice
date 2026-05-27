#!/usr/bin/env python3
"""
Fetches LeetCode problem data and auto-generates:
  {N}.cpp, {N}_driver.cpp, {N}_input.txt, {N}_expected.txt, {N}_debug.txt

Supports common types: int, long long, double, bool, string,
vector<int>, vector<long long>, vector<string>, vector<vector<int>>
"""

import sys, json, os, re
import urllib.request, urllib.error

LEETCODE_GRAPHQL = "https://leetcode.com/graphql"
HEADERS = {
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:120.0) Gecko/20100101 Firefox/120.0",
    "Referer": "https://leetcode.com",
    "Accept": "application/json",
}


# ─── LeetCode API ────────────────────────────────────────────────────────────

def post_json(url, data):
    body = json.dumps(data).encode()
    req = urllib.request.Request(url, data=body, headers=HEADERS, method="POST")
    with urllib.request.urlopen(req, timeout=20) as r:
        return json.loads(r.read().decode())


def fetch_problem(num):
    # 1. number → slug
    q1 = """query ql($f: QuestionListFilterInput) {
      questionList(categorySlug: "" limit: 5 skip: 0 filters: $f) {
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
        raise RuntimeError(f"Problem {num} not found on LeetCode")

    # 2. slug → full data
    q2 = """query qd($s: String!) {
      question(titleSlug: $s) {
        content exampleTestcases
        codeSnippets { langSlug code }
      }
    }"""
    r2 = post_json(LEETCODE_GRAPHQL, {"query": q2, "variables": {"s": slug}})
    d = r2["data"]["question"]
    d["title"] = title
    d["slug"] = slug
    return d


# ─── Signature Parser ─────────────────────────────────────────────────────────

def parse_signature(cpp_code):
    """Return (return_type, func_name, [(type, name), ...]) from a LeetCode C++ snippet."""
    m = re.search(r'^\s{4}(.+?)\s+(\w+)\s*\(([^)]*)\)\s*\{', cpp_code, re.MULTILINE)
    if not m:
        return None, None, []

    ret = m.group(1).strip()
    fn  = m.group(2).strip()
    ps  = m.group(3).strip()

    params = []
    if ps:
        # split on commas, respecting <> depth
        parts, depth, cur = [], 0, ""
        for c in ps:
            if c in '<(': depth += 1
            elif c in '>)': depth -= 1
            if c == ',' and depth == 0:
                parts.append(cur.strip()); cur = ""
            else:
                cur += c
        if cur.strip():
            parts.append(cur.strip())

        for p in parts:
            p = re.sub(r'\bconst\b', '', p).replace('&', '').strip()
            p = re.sub(r'\s+', ' ', p)
            m2 = re.match(r'^(.+)\s+(\w+)$', p)
            if m2:
                params.append((m2.group(1).strip(), m2.group(2).strip()))
            else:
                params.append((p, f"arg{len(params)}"))

    return ret, fn, params


def norm(t):
    return re.sub(r'\s+', '', t)   # "vector< int >" → "vector<int>"


# ─── C++ I/O Helpers (embedded in driver) ────────────────────────────────────

CPP_HELPERS = r"""
// ── read helpers ──────────────────────────────────────────────────
int           _ri()  { string s; getline(cin,s); return stoi(s); }
long long     _rll() { string s; getline(cin,s); return stoll(s); }
double        _rd()  { string s; getline(cin,s); return stod(s); }
bool          _rb()  { string s; getline(cin,s); return s=="true"||s=="1"; }
string        _rs()  { string s; getline(cin,s);
    if (s.size()>=2 && s.front()=='"' && s.back()=='"') s=s.substr(1,s.size()-2);
    return s; }

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}
vector<long long> _rvll() {
    string s; getline(cin,s);
    vector<long long> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoll(t)); }
    return v;
}
vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    auto body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}
vector<vector<int>> _rvvi() {
    string s; getline(cin,s);
    vector<vector<int>> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>1) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                vector<int> row; stringstream ss(cur);
                string t; while(getline(ss,t,',')) if(!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur="";
            } else if (dep>0) cur+=c;
        } else if (dep>1) cur+=c;
    }
    return v;
}
"""


def read_call(ptype, pname):
    t = norm(ptype)
    m = {
        "int":               f"int {pname} = _ri();",
        "longlong":          f"long long {pname} = _rll();",
        "int64_t":           f"long long {pname} = _rll();",
        "double":            f"double {pname} = _rd();",
        "float":             f"double {pname} = _rd();",
        "bool":              f"bool {pname} = _rb();",
        "string":            f"string {pname} = _rs();",
        "vector<int>":       f"auto {pname} = _rvi();",
        "vector<longlong>":  f"auto {pname} = _rvll();",
        "vector<int64_t>":   f"auto {pname} = _rvll();",
        "vector<string>":    f"auto {pname} = _rvs();",
        "vector<vector<int>>": f"auto {pname} = _rvvi();",
    }
    return m.get(t, f"// TODO: read {ptype} {pname}")


def print_call(return_type):
    t = norm(return_type)
    if t == "bool":
        return 'cout << (res ? "true" : "false") << "\\n";'
    if t in ("int", "longlong", "int64_t", "double", "float", "string"):
        return 'cout << res << "\\n";'
    if t in ("vector<int>", "vector<longlong>", "vector<string>"):
        return ('for (int _i=0;_i<(int)res.size();_i++){if(_i)cout<<" ";cout<<res[_i];}cout<<"\\n";')
    if t == "vector<vector<int>>":
        return ('for(auto&row:res){for(int _i=0;_i<(int)row.size();_i++){if(_i)cout<<" ";cout<<row[_i];}cout<<"\\n";}')
    return '// TODO: print result\ncout << "TODO\\n";'


# ─── Example Parser ───────────────────────────────────────────────────────────

def strip_html(html):
    for e, c in [('&lt;','<'),('&gt;','>'),('&amp;','&'),('&nbsp;',' '),
                 ('&quot;','"'),('&#39;',"'"),('&le;','≤'),('&ge;','≥')]:
        html = html.replace(e, c)
    return re.sub(r'<[^>]+>', '\n', html)


def parse_outputs(content_html, return_type):
    text = strip_html(content_html)
    lines = [l.strip() for l in text.split('\n') if l.strip()]
    outputs = []
    for i, line in enumerate(lines):
        # "Output: value" on same line
        m = re.match(r'[Oo]utput\s*[=:]\s*(.+)', line)
        if m:
            outputs.append(convert_output(m.group(1).strip(), return_type))
            continue
        # "Output:" label with value on the next line
        if re.match(r'^[Oo]utput\s*:?\s*$', line) and i + 1 < len(lines):
            outputs.append(convert_output(lines[i + 1].strip(), return_type))
    return outputs


def convert_output(raw, return_type):
    """Convert LeetCode output notation to what the driver prints."""
    t = norm(return_type)
    raw = raw.strip()
    if t in ("int", "longlong", "int64_t", "double", "float", "bool"):
        return raw
    if t == "string":
        return raw.strip('"')
    if t in ("vector<int>", "vector<longlong>"):
        nums = re.findall(r'-?\d+', raw)
        return ' '.join(nums)
    if t == "vector<string>":
        strings = re.findall(r'"([^"]*)"', raw)
        return ' '.join(strings)
    if t == "vector<vector<int>>":
        rows = re.findall(r'\[([^\[\]]*)\]', raw)
        lines = []
        for row in rows:
            nums = re.findall(r'-?\d+', row)
            lines.append(' '.join(nums))
        return '\n'.join(lines)
    return raw


# ─── File Builders ────────────────────────────────────────────────────────────

def build_solution_cpp(num, slug, cpp_snippet):
    """Skeleton solution file with correct link and class Solution."""
    link = f"https://leetcode.com/problems/{slug}/description/"

    # Extract the original function signature line from the LeetCode snippet
    # (preserves & / const / exact spacing as LeetCode provides it)
    m = re.search(r'^    (.+?\w+\s*\([^)]*\))\s*\{', cpp_snippet, re.MULTILINE)
    sig = m.group(1).rstrip() if m else "// TODO: paste function signature"

    return (
        f"// Link: {link}\n"
        f"\n"
        f"#include <bits/stdc++.h>\n"
        f"using namespace std;\n"
        f"\n"
        f"class Solution {{\n"
        f"public:\n"
        f"    {sig} {{\n"
        f"        \n"
        f"    }}\n"
        f"}};\n"
    )


def build_driver(num, func_name, return_type, params):
    reads = '\n'.join(f"        {read_call(t,n)}" for t,n in params) or "        // (no args)"
    param_names = ', '.join(n for _,n in params)
    if return_type.strip() == 'void':
        call  = f"        Solution sol;\n        sol.{func_name}({param_names});"
        print = ""
    else:
        call  = f"        Solution sol;\n        auto res = sol.{func_name}({param_names});"
        print = f"        {print_call(return_type)}"

    return f"""#include <bits/stdc++.h>
using namespace std;
#include "{num}.cpp"
{CPP_HELPERS}
int main() {{
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {{
{reads}
{call}
{print}
    }}
    return 0;
}}
"""


def build_input(example_testcases, num_params):
    lines = [l for l in example_testcases.strip().split('\n') if l.strip()]
    tc = max(1, len(lines) // num_params) if num_params else 1
    return str(tc) + '\n' + '\n'.join(lines) + '\n'


def build_debug(example_testcases, num_params):
    """First example test case only, for use with debug.sh."""
    lines = [l for l in example_testcases.strip().split('\n') if l.strip()]
    first_case = lines[:num_params] if num_params else lines[:1]
    return '1\n' + '\n'.join(first_case) + '\n'


# ─── Main ─────────────────────────────────────────────────────────────────────

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

    cpp = next((s["code"] for s in data.get("codeSnippets",[]) if s["langSlug"]=="cpp"), "")
    ret, fn, params = parse_signature(cpp)
    if not fn:
        print("ERROR: Could not parse C++ signature")
        sys.exit(1)

    sig = f"{ret} {fn}({', '.join(t+' '+n for t,n in params)})"
    print(f"      Signature: {sig}")

    examples_raw = data.get("exampleTestcases", "")
    content_html = data.get("content", "")
    num_params   = len(params)

    lines = [l for l in examples_raw.strip().split('\n') if l.strip()]
    tc_count = max(1, len(lines) // num_params) if num_params else 1

    print(f"[2/3] Parsing {tc_count} example test case(s)...")
    expected = parse_outputs(content_html, ret)

    print("[3/3] Writing files...")

    # {N}.cpp — solution skeleton
    path = os.path.join(work_dir, f"{num}.cpp")
    with open(path, 'w') as f:
        f.write(build_solution_cpp(num, data["slug"], cpp))
    print(f"      {num}.cpp")

    # driver.cpp
    path = os.path.join(work_dir, f"{num}_driver.cpp")
    with open(path, 'w') as f:
        f.write(build_driver(num, fn, ret, params))
    print(f"      {num}_driver.cpp")

    # input.txt
    path = os.path.join(work_dir, f"{num}_input.txt")
    with open(path, 'w') as f:
        f.write(build_input(examples_raw, num_params))
    print(f"      {num}_input.txt")

    # expected.txt
    path = os.path.join(work_dir, f"{num}_expected.txt")
    if expected:
        with open(path, 'w') as f:
            f.write('\n'.join(expected[:tc_count]) + '\n')
        print(f"      {num}_expected.txt  ({len(expected[:tc_count])} outputs)")
    else:
        with open(path, 'w') as f:
            f.write("# TODO: add expected outputs manually\n")
        print(f"WARNING: could not auto-parse expected output — fill {num}_expected.txt manually")

    # debug.txt — first example only, for debug.sh
    path = os.path.join(work_dir, f"{num}_debug.txt")
    with open(path, 'w') as f:
        f.write(build_debug(examples_raw, num_params))
    print(f"      {num}_debug.txt")

    print(f"\nDone. Problem {num} is ready.")


if __name__ == "__main__":
    main()
