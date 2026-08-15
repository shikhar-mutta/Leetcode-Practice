#include <bits/stdc++.h>
using namespace std;
#include "1429.cpp"

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
            else cur += c;
        } else if (c == ']') {
            depth--;
            if (depth == 1) parts.push_back(cur);
            else cur += c;
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
        auto groups = extractGroupsRaw(argsLine);

        FirstUnique* fu = nullptr;
        cout << "[";
        for (int i = 0; i < (int)ops.size(); i++) {
            if (i) cout << ", ";
            if (ops[i] == "FirstUnique") {
                string g = groups[i];
                if (!g.empty() && g.front() == '[' && g.back() == ']') g = g.substr(1, g.size() - 2);
                vector<int> nums;
                stringstream ss(g);
                string tok;
                while (getline(ss, tok, ',')) if (!tok.empty()) nums.push_back(stoi(tok));
                fu = new FirstUnique(nums);
                cout << "null";
            } else if (ops[i] == "showFirstUnique") {
                cout << fu->showFirstUnique();
            } else if (ops[i] == "add") {
                int val = stoi(groups[i]);
                fu->add(val);
                cout << "null";
            }
        }
        cout << "]\n";
        delete fu;
    }
    return 0;
}
