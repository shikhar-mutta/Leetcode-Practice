#include <bits/stdc++.h>
using namespace std;
#include "305.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

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
        int m = _ri();
        int n = _ri();
        auto positions = _rvvi();
        Solution sol;
        auto res = sol.numIslands2(m, n, positions);
        cout << "[";
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << ",";
            cout << res[i];
        }
        cout << "]\n";
    }
    return 0;
}
