#include <bits/stdc++.h>
using namespace std;
#include "666.cpp"

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
        Solution sol;
        auto res = sol.pathSum(nums);
        cout << res << "\n";
    }
    return 0;
}
