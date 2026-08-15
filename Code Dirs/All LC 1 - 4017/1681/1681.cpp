// Link: https://leetcode.com/problems/minimum-incompatibility/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int groupSize = n / k;
        if (groupSize == 1) return 0;

        vector<int> cost(1 << n, -1);
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) != groupSize) continue;
            unordered_set<int> seen;
            int mn = INT_MAX, mx = INT_MIN;
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (seen.count(nums[i])) { valid = false; break; }
                    seen.insert(nums[i]);
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }
            if (valid) cost[mask] = mx - mn;
        }

        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == INT_MAX) continue;
            int rem = ((1 << n) - 1) ^ mask;
            for (int sub = rem; sub > 0; sub = (sub - 1) & rem) {
                if (cost[sub] == -1) continue;
                if (dp[mask] + cost[sub] < dp[mask | sub]) {
                    dp[mask | sub] = dp[mask] + cost[sub];
                }
            }
        }
        int full = (1 << n) - 1;
        return dp[full] == INT_MAX ? -1 : dp[full];
    }
};
