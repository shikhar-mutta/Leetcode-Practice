#include <bits/stdc++.h>
using namespace std;
#include "1483.cpp"

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

// extracts each top-level arg-group, preserving inner nested brackets
vector<string> extractGroupsRaw(const string& s) {
    vector<string> parts;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 2) cur = "";
            else if (depth > 2) cur += c;
        } else if (c == ']') {
            if (depth == 2) parts.push_back(cur);
            else if (depth > 2) cur += c;
            depth--;
        } else if (depth >= 2) {
            cur += c;
        }
    }
    return parts;
}

vector<string> splitTopTokens(const string& raw) {
    vector<string> toks;
    int depth = 0;
    string cur;
    for (char c : raw) {
        if (c == '[') { depth++; cur += c; continue; }
        if (c == ']') { depth--; cur += c; continue; }
        if (c == ',' && depth == 0) { toks.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) toks.push_back(cur);
    return toks;
}

vector<int> parseIntArray(const string& s) {
    vector<int> v;
    string body = s;
    if (!body.empty() && body.front() == '[') body = body.substr(1, body.size() - 2);
    stringstream ss(body);
    string tok;
    while (getline(ss, tok, ',')) if (!tok.empty()) v.push_back(stoi(tok));
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        TreeAncestor* ta = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ", ";
            auto toks = splitTopTokens(groups[i]);

            if (ops[i] == "TreeAncestor") {
                int n = stoi(toks[0]);
                auto parent = parseIntArray(toks[1]);
                ta = new TreeAncestor(n, parent);
                cout << "null";
            } else if (ops[i] == "getKthAncestor") {
                cout << ta->getKthAncestor(stoi(toks[0]), stoi(toks[1]));
            }
        }
        cout << "]\n";
        delete ta;
    }
    return 0;
}
