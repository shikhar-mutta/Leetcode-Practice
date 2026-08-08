#include <bits/stdc++.h>
using namespace std;
#include "1286.cpp"

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

vector<string> extractGroupsRaw(const string& s) {
    vector<string> parts;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 2) cur = "";
        } else if (c == ']') {
            depth--;
            if (depth == 1) parts.push_back(cur);
        } else if (depth >= 2) {
            cur += c;
        }
    }
    return parts;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto argGroups = extractGroupsRaw(argsLine);

        CombinationIterator* it = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ", ";
            if (ops[i] == "CombinationIterator") {
                string g = argGroups[i];
                size_t q1 = g.find('"'), q2 = g.find('"', q1 + 1);
                string chars = g.substr(q1 + 1, q2 - q1 - 1);
                int len = stoi(g.substr(q2 + 2));
                it = new CombinationIterator(chars, len);
                cout << "null";
            } else if (ops[i] == "next") {
                cout << "\"" << it->next() << "\"";
            } else if (ops[i] == "hasNext") {
                cout << (it->hasNext() ? "true" : "false");
            }
        }
        cout << "]\n";
    }
    return 0;
}
