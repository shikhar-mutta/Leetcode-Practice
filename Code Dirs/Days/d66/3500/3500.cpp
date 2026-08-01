// Link: https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^3)  SC: O(n^2)
// Approach: the i-th subarray nums[l..r] costs
// (prefixNums[r+1] + k*i) * (prefixCost[r+1] - prefixCost[l]), where
// prefixNums is measured from the START of the whole array (not the
// subarray). DP dp[j][i] = min cost to partition the first j elements
// into exactly i subarrays; transition tries every previous boundary l
// as the start of the i-th subarray. Answer is the min over all segment
// counts of dp[n][i].
class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        vector<long long> prefixNums(n + 1, 0), prefixCost(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixNums[i+1] = prefixNums[i] + nums[i];
            prefixCost[i+1] = prefixCost[i] + cost[i];
        }
        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
        dp[0][0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= j; i++) {
                for (int l = 0; l < j; l++) {
                    if (dp[l][i-1] >= INF) continue;
                    long long segCost = (prefixNums[j] + (long long)k * i) * (prefixCost[j] - prefixCost[l]);
                    dp[j][i] = min(dp[j][i], dp[l][i-1] + segCost);
                }
            }
        }
        long long ans = INF;
        for (int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);
        return ans;
    }
};
