#include <bits/stdc++.h>
using namespace std;
#include "1865.cpp"

vector<string> _rvs() {
    string s; getline(cin, s);
    vector<string> v;
    auto body = s.substr(1, s.size() - 2);
    bool in = false; string cur;
    for (char c : body) {
        if (c == '"') { in = !in; continue; }
        if (c == ',' && !in) { v.push_back(cur); cur = ""; continue; }
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}

// Extract each top-level arg-group; preserves nested brackets when depth>2 (args containing arrays)
vector<string> extractGroupsRaw(const string& s) {
    vector<string> res;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') {
            depth++;
            if (depth == 2) cur = "";
            else if (depth > 2) cur += c;
            continue;
        }
        if (c == ']') {
            depth--;
            if (depth == 1) {
                res.push_back(cur);
            } else if (depth >= 2) {
                cur += c;
            }
            continue;
        }
        if (depth >= 2) cur += c;
    }
    return res;
}

vector<int> parseIntList(const string& s) {
    vector<int> v;
    stringstream ss(s);
    string t;
    while (getline(ss, t, ',')) if (!t.empty()) v.push_back(stoi(t));
    return v;
}

// splits a string like "[1,2,3],[4,5,6]" into ["1,2,3","4,5,6"]
vector<string> splitTopArrays(const string& s) {
    vector<string> res;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') { depth++; if (depth == 1) cur = ""; continue; }
        if (c == ']') { depth--; if (depth == 0) res.push_back(cur); continue; }
        if (depth >= 1) cur += c;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        FindSumPairs* obj = nullptr;
        vector<string> outputs;
        for (size_t i = 0; i < ops.size(); i++) {
            auto& op = ops[i];
            auto& argStr = groups[i];
            if (op == "FindSumPairs") {
                auto arrs = splitTopArrays(argStr);
                vector<int> n1 = parseIntList(arrs[0]);
                vector<int> n2 = parseIntList(arrs[1]);
                obj = new FindSumPairs(n1, n2);
                outputs.push_back("null");
            } else if (op == "add") {
                auto args = parseIntList(argStr);
                obj->add(args[0], args[1]);
                outputs.push_back("null");
            } else if (op == "count") {
                auto args = parseIntList(argStr);
                outputs.push_back(to_string(obj->count(args[0])));
            }
        }
        delete obj;

        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) {
            if (i) cout << ",";
            cout << outputs[i];
        }
        cout << "]\n";
    }
    return 0;
}
