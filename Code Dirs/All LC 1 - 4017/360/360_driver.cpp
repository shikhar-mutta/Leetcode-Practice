#include <bits/stdc++.h>
using namespace std;
#include "360.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }
vector<int> _rvi() {
    string s; getline(cin,s);
    vector<int> v; stringstream ss(s.substr(1,s.size()-2));
    string t; while(getline(ss,t,',')) { if(!t.empty()) v.push_back(stoi(t)); }
    return v;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        auto nums = _rvi();
        int a = _ri(), b = _ri(), c = _ri();
        Solution sol;
        auto res = sol.sortTransformedArray(nums, a, b, c);
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << " ";
            cout << res[i];
        }
        cout << "\n";
    }
    return 0;
}
