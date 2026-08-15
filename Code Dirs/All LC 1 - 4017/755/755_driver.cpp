#include <bits/stdc++.h>
using namespace std;
#include "755.cpp"

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
        auto heights = _rvi();
        int volume = _ri();
        int k = _ri();
        Solution sol;
        auto res = sol.pourWater(heights, volume, k);
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) { if(i) cout << ","; cout << res[i]; }
        cout << "]\n";
    }
    return 0;
}
