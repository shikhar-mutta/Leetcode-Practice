#include <bits/stdc++.h>
using namespace std;
#include "1272.cpp"

vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
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
        auto intervals = _rvvi();
        auto toBeRemoved = _rvi();
        Solution sol;
        auto res = sol.removeInterval(intervals, toBeRemoved);
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << " ";
            cout << "[" << res[i][0] << "," << res[i][1] << "]";
        }
        cout << "\n";
    }
    return 0;
}
