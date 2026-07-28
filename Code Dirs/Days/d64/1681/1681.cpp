// Link: https://leetcode.com/problems/minimum-incompatibility/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int sz = n / k;
        if (sz == 1) return 0;
        int full = 1 << n;
        vector<int> groupCost(full, -1);
        for (int mask = 0; mask < full; mask++) {
            if (__builtin_popcount(mask) != sz) continue;
            unordered_set<int> seen;
            bool ok = true;
            int mn = INT_MAX, mx = INT_MIN;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (seen.count(nums[i])) { ok = false; break; }
                    seen.insert(nums[i]);
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }
            if (ok) groupCost[mask] = mx - mn;
        }
        vector<int> dp(full, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] == INT_MAX) continue;
            int rem = (full - 1) ^ mask;
            // iterate submasks of rem with size sz
            for (int sub = rem; sub > 0; sub = (sub - 1) & rem) {
                if (groupCost[sub] < 0) continue;
                int nmask = mask | sub;
                if (dp[mask] + groupCost[sub] < dp[nmask])
                    dp[nmask] = dp[mask] + groupCost[sub];
            }
        }
        return dp[full - 1] == INT_MAX ? -1 : dp[full - 1];
    }
};
