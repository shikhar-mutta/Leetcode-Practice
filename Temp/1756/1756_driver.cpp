#include <bits/stdc++.h>
using namespace std;
#include "1756.cpp"

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

vector<vector<long long>> extractGroups(const string& s) {
    vector<vector<long long>> res;
    int depth = 0; string cur;
    for (char c : s) {
        if (c == '[') { depth++; if (depth == 2) cur = ""; continue; }
        if (c == ']') {
            depth--;
            if (depth == 1) {
                vector<long long> row;
                stringstream ss(cur);
                string t;
                while (getline(ss, t, ',')) if (!t.empty()) row.push_back(stoll(t));
                res.push_back(row);
            }
            continue;
        }
        if (depth == 2) cur += c;
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
        auto groups = extractGroups(argsLine);

        MRUQueue* q = nullptr;
        vector<string> outputs;
        for (size_t i = 0; i < ops.size(); i++) {
            auto& op = ops[i];
            auto& args = groups[i];
            if (op == "MRUQueue") {
                q = new MRUQueue((int)args[0]);
                outputs.push_back("null");
            } else if (op == "fetch") {
                outputs.push_back(to_string(q->fetch((int)args[0])));
            }
        }
        delete q;

        cout << "[";
        for (size_t i = 0; i < outputs.size(); i++) {
            if (i) cout << ",";
            cout << outputs[i];
        }
        cout << "]\n";
    }
    return 0;
}
