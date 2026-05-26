#include <bits/stdc++.h>
using namespace std;

#include "18.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        vector<vector<int>> ans = sol.fourSum(nums, target);
        for (auto& v : ans) sort(v.begin(), v.end());
        sort(ans.begin(), ans.end());
        if (ans.empty()) { cout << "\n"; continue; }
        for (auto& v : ans) {
            for (int i = 0; i < (int)v.size(); i++) cout << v[i] << " \n"[i == (int)v.size() - 1];
        }
        cout << "\n";
    }
    return 0;
}
