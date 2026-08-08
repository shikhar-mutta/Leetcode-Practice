#include <bits/stdc++.h>
using namespace std;
#include "710.cpp"

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}
int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n = _ri();
        auto blacklist = _rvi();
        int numPicks = _ri();
        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());
        Solution sol(n, blacklist);
        bool ok = true;
        for (int i = 0; i < numPicks; i++) {
            int p = sol.pick();
            if (p < 0 || p >= n || blackSet.count(p)) { ok = false; break; }
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
