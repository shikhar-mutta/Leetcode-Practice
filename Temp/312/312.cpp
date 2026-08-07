// Link: https://leetcode.com/problems/burst-balloons/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)  SC: O(n^2)
// Approach: interval DP - pad with 1s at both ends, dp[l][r] = max coins for
// bursting all balloons strictly between l and r, trying each last balloon k
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++) a[i + 1] = nums[i];

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len <= n + 1; len++) {
            for (int l = 0; l + len <= n + 1; l++) {
                int r = l + len;
                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
