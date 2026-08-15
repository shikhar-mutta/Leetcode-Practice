#include <bits/stdc++.h>
using namespace std;
#include "398.cpp"

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
        vector<int> targets = _rvi();
        Solution sol(nums);
        bool ok = true;
        for (int target : targets) {
            int idx = sol.pick(target);
            if (idx < 0 || idx >= (int)nums.size() || nums[idx] != target) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
