#include <bits/stdc++.h>
using namespace std;

#include "15.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        vector<vector<int>> ans = sol.threeSum(nums);
        for (auto& v : ans) sort(v.begin(), v.end());
        sort(ans.begin(), ans.end());
        if (ans.empty()) { cout << "\n"; continue; }
        for (auto& v : ans) {
            for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " \n"[i == (int)v.size() - 1];
        }
    }
    return 0;
}
