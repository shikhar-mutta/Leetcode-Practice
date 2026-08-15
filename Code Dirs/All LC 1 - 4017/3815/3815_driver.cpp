#include <bits/stdc++.h>
using namespace std;
#include "3815.cpp"

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
        AuctionSystem* sys = nullptr;
        for (int i = 0; i < (int)ops.size(); i++) {
            const string& op = ops[i];
            auto& a = args[i];
            if (op == "AuctionSystem") {
                sys = new AuctionSystem();
                results.push_back("null");
            } else if (op == "addBid") {
                sys->addBid((int)a[0], (int)a[1], (int)a[2]);
                results.push_back("null");
            } else if (op == "updateBid") {
                sys->updateBid((int)a[0], (int)a[1], (int)a[2]);
                results.push_back("null");
            } else if (op == "removeBid") {
                sys->removeBid((int)a[0], (int)a[1]);
                results.push_back("null");
            } else if (op == "getHighestBidder") {
                results.push_back(to_string(sys->getHighestBidder((int)a[0])));
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
