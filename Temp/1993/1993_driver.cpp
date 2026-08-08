#include <bits/stdc++.h>
using namespace std;
#include "1993.cpp"

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
            if (depth == 1) res.push_back(cur);
            else if (depth >= 2) cur += c;
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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        string argsLine; getline(cin, argsLine);
        auto groups = extractGroupsRaw(argsLine);

        LockingTree* obj = nullptr;
        vector<string> outputs;
        for (size_t i = 0; i < ops.size(); i++) {
            auto& op = ops[i];
            auto& argStr = groups[i];
            if (op == "LockingTree") {
                string inner = argStr;
                if (!inner.empty() && inner.front() == '[' && inner.back() == ']') {
                    inner = inner.substr(1, inner.size() - 2);
                }
                auto parentArr = parseIntList(inner);
                obj = new LockingTree(parentArr);
                outputs.push_back("null");
            } else if (op == "lock") {
                auto args = parseIntList(argStr);
                outputs.push_back(obj->lock(args[0], args[1]) ? "true" : "false");
            } else if (op == "unlock") {
                auto args = parseIntList(argStr);
                outputs.push_back(obj->unlock(args[0], args[1]) ? "true" : "false");
            } else if (op == "upgrade") {
                auto args = parseIntList(argStr);
                outputs.push_back(obj->upgrade(args[0], args[1]) ? "true" : "false");
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
