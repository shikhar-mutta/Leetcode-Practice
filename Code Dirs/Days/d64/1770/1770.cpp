// Link: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int left = i; left >= 0; left--) {
                int right = n - 1 - (i - left);
                int useLeft = multipliers[i] * nums[left] + dp[i+1][left+1];
                int useRight = multipliers[i] * nums[right] + dp[i+1][left];
                dp[i][left] = max(useLeft, useRight);
            }
        }
        return dp[0][0];
    }
};
