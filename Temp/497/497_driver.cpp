#include <bits/stdc++.h>
using namespace std;
#include "497.cpp"

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
int _ri() { string s; getline(cin,s); return stoi(s); }

bool inside(vector<vector<int>>& rects, int x, int y) {
    for (auto& r : rects) {
        if (x >= r[0] && x <= r[2] && y >= r[1] && y <= r[3]) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto rects = _rvvi();
        int n = _ri();
        Solution sol(rects);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            auto p = sol.pick();
            if (!inside(rects, p[0], p[1])) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
