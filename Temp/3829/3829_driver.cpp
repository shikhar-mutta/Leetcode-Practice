#include <bits/stdc++.h>
using namespace std;
#include "3829.cpp"

// ── read helpers ──────────────────────────────────────────────────
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
vector<vector<long long>> _rargs() {
    string s; getline(cin,s);
    vector<vector<long long>> v;
    int dep = 0; string cur;
    for (char c : s) {
        if (c=='[') { dep++; if (dep>2) cur+=c; }
        else if (c==']') {
            dep--;
            if (dep==1) {
                vector<long long> row; stringstream ss(cur);
                string t; while(getline(ss,t,',')) if(!t.empty()) row.push_back(stoll(t));
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
        auto args = _rargs();

        vector<string> results;
        RideSharingSystem* sys = nullptr;
        for (int i = 0; i < (int)ops.size(); i++) {
            const string& op = ops[i];
            auto& a = args[i];
            if (op == "RideSharingSystem") {
                sys = new RideSharingSystem();
                results.push_back("null");
            } else if (op == "addRider") {
                sys->addRider((int)a[0]);
                results.push_back("null");
            } else if (op == "addDriver") {
                sys->addDriver((int)a[0]);
                results.push_back("null");
            } else if (op == "cancelRider") {
                sys->cancelRider((int)a[0]);
                results.push_back("null");
            } else if (op == "matchDriverWithRider") {
                auto res = sys->matchDriverWithRider();
                results.push_back("[" + to_string(res[0]) + ", " + to_string(res[1]) + "]");
            }
        }
        delete sys;

        cout << "[";
        for (int i = 0; i < (int)results.size(); i++) {
            if (i) cout << ", ";
            cout << results[i];
        }
        cout << "]\n";
    }
    return 0;
}
