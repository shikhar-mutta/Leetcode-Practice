#include <bits/stdc++.h>
using namespace std;
#include "381.cpp"

vector<string> parseOps(const string& s) {
    vector<string> v;
    string body = s.substr(1, s.size() - 2);
    bool in = false; string cur;
    for (char c : body) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

vector<vector<int>> parseArgs(const string& s) {
    vector<vector<int>> v;
    int dep = 0; string cur;
    for (char c : s) {
        if (c == '[') { dep++; if (dep > 2) cur += c; }
        else if (c == ']') {
            dep--;
            if (dep == 1) {
                vector<int> row; stringstream ss(cur);
                string t; while (getline(ss, t, ',')) if (!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur = "";
            } else if (dep > 0) cur += c;
        } else if (dep > 1) cur += c;
    }
    return v;
}

int main() {
    string tmp;
    getline(cin, tmp); // ignore leading count line
    string opsLine, argsLine;
    getline(cin, opsLine);
    getline(cin, argsLine);
    auto ops = parseOps(opsLine);
    auto args = parseArgs(argsLine);

    RandomizedCollection rc;
    multiset<int> ref;
    bool ok = true;
    for (size_t i = 1; i < ops.size(); i++) {
        if (ops[i] == "insert") {
            int val = args[i][0];
            bool expected = (ref.count(val) == 0);
            bool got = rc.insert(val);
            ref.insert(val);
            if (got != expected) ok = false;
        } else if (ops[i] == "remove") {
            int val = args[i][0];
            bool expected = (ref.count(val) > 0);
            bool got = rc.remove(val);
            if (got != expected) ok = false;
            if (got) ref.erase(ref.find(val));
        } else if (ops[i] == "getRandom") {
            int got = rc.getRandom();
            if (ref.count(got) == 0) ok = false;
        }
    }
    cout << (ok ? "PASS" : "FAIL") << "\n";
    return 0;
}
