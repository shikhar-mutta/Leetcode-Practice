// Link: https://leetcode.com/problems/predict-the-winner/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: interval DP - dp[l][r] = best score difference (current player
// minus opponent) achievable from range [l,r]
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                dp[l][r] = max(nums[l] - dp[l+1][r], nums[r] - dp[l][r-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};
