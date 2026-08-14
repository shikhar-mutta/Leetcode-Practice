// Link: https://leetcode.com/problems/find-the-minimum-cost-array-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        // dp[mask][last] = min cost to complete tour: visited 'mask' (must include bit0),
        // currently at 'last', still need to visit remaining bits then return to 0.
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        function<int(int,int)> solve = [&](int mask, int last) -> int {
            if (mask == (1 << n) - 1) return abs(last - nums[0]);
            if (dp[mask][last] != -1) return dp[mask][last];
            int best = INT_MAX;
            for (int nxt = 0; nxt < n; nxt++) {
                if (mask & (1 << nxt)) continue;
                int cost = abs(last - nums[nxt]) + solve(mask | (1 << nxt), nxt);
                best = min(best, cost);
            }
            return dp[mask][last] = best;
        };
        solve(1, 0);

        vector<int> perm = {0};
        int mask = 1, last = 0;
        while (mask != (1 << n) - 1) {
            for (int nxt = 0; nxt < n; nxt++) {
                if (mask & (1 << nxt)) continue;
                int cost = abs(last - nums[nxt]) + solve(mask | (1 << nxt), nxt);
                if (cost == dp[mask][last]) {
                    perm.push_back(nxt);
                    mask |= (1 << nxt);
                    last = nxt;
                    break;
                }
            }
        }
        return perm;
    }
};
