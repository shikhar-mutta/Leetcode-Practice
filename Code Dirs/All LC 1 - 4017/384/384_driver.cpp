#include <bits/stdc++.h>
using namespace std;
#include "384.cpp"

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
        Solution sol(nums);
        multiset<int> expected(nums.begin(), nums.end());
        bool ok = true;

        auto check = [&](vector<int>& v) {
            multiset<int> got(v.begin(), v.end());
            if (got != expected) ok = false;
        };

        auto s1 = sol.shuffle(); check(s1);
        auto r1 = sol.reset();
        if (r1 != nums) ok = false;
        auto s2 = sol.shuffle(); check(s2);

        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
