// Link: https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 1));
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int p = 0; p < i; p++) {
                    if (nums[p] == nums[i]) {
                        dp[i][j] = max(dp[i][j], dp[p][j] + 1);
                    } else if (j > 0) {
                        dp[i][j] = max(dp[i][j], dp[p][j-1] + 1);
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
