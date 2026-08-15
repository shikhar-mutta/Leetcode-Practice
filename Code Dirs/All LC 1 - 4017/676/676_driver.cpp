#include <bits/stdc++.h>
using namespace std;
#include "676.cpp"

vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    if (s.size() < 2) return v;
    auto body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        if (c==' ' && !in && cur.empty()) continue;
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

// splits top-level bracket groups from a line like "[grp1, grp2, grp3]"
vector<string> splitTopLevel(const string& line) {
    string inner = line.substr(1, line.size()-2); // strip outer [ ]
    vector<string> groups;
    int depth = 0; string cur;
    for (char c : inner) {
        if (c == '[') { depth++; cur += c; }
        else if (c == ']') { depth--; cur += c; }
        else if (c == ',' && depth == 0) { groups.push_back(cur); cur.clear(); }
        else if (c == ' ' && cur.empty()) continue;
        else cur += c;
    }
    if (!cur.empty()) groups.push_back(cur);
    return groups;
}

vector<string> parseStrList(string s) {
    // s like "[]" or "[\"hello\",\"leetcode\"]" or "[[\"hello\",\"leetcode\"]]"
    vector<string> v;
    if (s.size() < 2) return v;
    string body = s.substr(1, s.size()-2);
    if (!body.empty() && body.front() == '[') {
        // nested single-element array
        return parseStrList(body);
    }
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        int n = ops.size();
        string argsLine; getline(cin, argsLine);
        auto groups = splitTopLevel(argsLine);
        vector<vector<string>> args(n);
        for (int i = 0; i < n && i < (int)groups.size(); i++) args[i] = parseStrList(groups[i]);
        MagicDictionary* md = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "MagicDictionary") { md = new MagicDictionary(); outputs.push_back("null"); }
            else if (ops[i] == "buildDict") { md->buildDict(args[i]); outputs.push_back("null"); }
            else if (ops[i] == "search") { outputs.push_back(md->search(args[i][0]) ? "true" : "false"); }
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ", "; cout << outputs[i]; }
        cout << "]\n";
        delete md;
    }
    return 0;
}
