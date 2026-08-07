#include <bits/stdc++.h>
using namespace std;
#include "635.cpp"

vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    if (s.size() < 2) return v;
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

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        int n = ops.size();
        vector<vector<string>> args(n);
        for (int i = 0; i < n; i++) args[i] = _rvs();
        LogSystem* ls = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "LogSystem") { ls = new LogSystem(); outputs.push_back("null"); }
            else if (ops[i] == "put") { ls->put(stoi(args[i][0]), args[i][1]); outputs.push_back("null"); }
            else if (ops[i] == "retrieve") {
                auto res = ls->retrieve(args[i][0], args[i][1], args[i][2]);
                string s = "[";
                for (size_t j = 0; j < res.size(); j++) { if(j) s+=","; s+=to_string(res[j]); }
                s += "]";
                outputs.push_back(s);
            }
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ","; cout << outputs[i]; }
        cout << "]\n";
        delete ls;
    }
    return 0;
}
