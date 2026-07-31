#include <bits/stdc++.h>
using namespace std;
#include "715.cpp"

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

    RangeModule rm;
    string out = "[null";
    for (size_t i = 1; i < ops.size(); i++) {
        if (ops[i] == "addRange") {
            rm.addRange(args[i][0], args[i][1]);
            out += ", null";
        } else if (ops[i] == "removeRange") {
            rm.removeRange(args[i][0], args[i][1]);
            out += ", null";
        } else if (ops[i] == "queryRange") {
            bool r = rm.queryRange(args[i][0], args[i][1]);
            out += r ? ", true" : ", false";
        }
    }
    out += "]";
    cout << out << "\n";
    return 0;
}
