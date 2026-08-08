#include <bits/stdc++.h>
using namespace std;
#include "715.cpp"

vector<string> _rvs() {
    string s; getline(cin,s);
    vector<string> v;
    if (s.size() < 2) return v;
    auto body = s.substr(1, s.size()-2);
    bool in = false; string cur;
    for (char c : body) {
        if (c=='"') { in=!in; continue; }
        if (c==',' && !in) { v.push_back(cur); cur=""; continue; }
        if (c==' ' && !in && cur.empty()) continue;
        cur += c;
    }
    if (!cur.empty()) v.push_back(cur);
    return v;
}
vector<vector<int>> _rvvi() {
    string s; getline(cin,s);
    vector<vector<int>> v;
    int dep=0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if(dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                vector<int> row; stringstream ss(cur);
                string t; while(getline(ss,t,',')) if(!t.empty()) row.push_back(stoi(t));
                v.push_back(row); cur="";
            } else if (dep>0) cur+=c;
        } else if (dep>1) cur+=c;
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto ops = _rvs();
        auto args = _rvvi();
        int n = ops.size();
        RangeModule* rm = nullptr;
        vector<string> outputs;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "RangeModule") { rm = new RangeModule(); outputs.push_back("null"); }
            else if (ops[i] == "addRange") { rm->addRange(args[i][0], args[i][1]); outputs.push_back("null"); }
            else if (ops[i] == "removeRange") { rm->removeRange(args[i][0], args[i][1]); outputs.push_back("null"); }
            else if (ops[i] == "queryRange") { outputs.push_back(rm->queryRange(args[i][0], args[i][1]) ? "true" : "false"); }
        }
        cout << "[";
        for (int i = 0; i < n; i++) { if(i) cout << ", "; cout << outputs[i]; }
        cout << "]\n";
        delete rm;
    }
    return 0;
}
