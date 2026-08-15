#include <bits/stdc++.h>
using namespace std;
#include "737.cpp"

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

vector<vector<string>> _rvvs() {
    string s; getline(cin,s);
    vector<vector<string>> res;
    string inner = s.substr(1, s.size()-2);
    int depth = 0; string cur;
    vector<string> groups;
    for (char c : inner) {
        if (c == '[') { depth++; if (depth > 1) cur += c; }
        else if (c == ']') { depth--; if (depth >= 1) cur += c; else { groups.push_back(cur); cur.clear(); } }
        else if (depth >= 1) cur += c;
    }
    for (auto& g : groups) {
        vector<string> row;
        bool in = false; string tok;
        for (char c : g) {
            if (c == '"') { in = !in; continue; }
            if (c == ',' && !in) { row.push_back(tok); tok.clear(); continue; }
            tok += c;
        }
        if (!tok.empty()) row.push_back(tok);
        res.push_back(row);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto s1 = _rvs();
        auto s2 = _rvs();
        auto pairs = _rvvs();
        Solution sol;
        auto res = sol.areSentencesSimilarTwo(s1, s2, pairs);
        cout << (res ? "true" : "false") << "\n";
    }
    return 0;
}
