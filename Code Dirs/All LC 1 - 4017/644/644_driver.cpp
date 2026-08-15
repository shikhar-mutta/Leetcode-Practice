#include <bits/stdc++.h>
using namespace std;
#include "644.cpp"

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
        auto nums = _rvi();
        int k = _ri();
        Solution sol;
        auto res = sol.findMaxAverage(nums, k);
        cout << fixed << setprecision(5) << res << "\n";
    }
    return 0;
}
