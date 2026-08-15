#include <bits/stdc++.h>
using namespace std;
#include "528.cpp"

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
        auto w = _rvi();
        int n = _ri();
        Solution sol(w);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int idx = sol.pickIndex();
            if (idx < 0 || idx >= (int)w.size()) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
