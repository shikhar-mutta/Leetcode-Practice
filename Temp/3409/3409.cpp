// Link: https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int D = maxVal; // max possible diff
        vector<vector<int>> dp(maxVal + 1, vector<int>(D + 1, 0));
        vector<vector<int>> sufMax(maxVal + 1, vector<int>(D + 2, 0));

        int ans = 1;
        for (int v : nums) {
            vector<int> cur(D + 1, 0);
            for (int d = 0; d <= D; d++) {
                int candidate = 0;
                if (v - d >= 0) candidate = max(candidate, sufMax[v - d][d]);
                if (v + d <= maxVal) candidate = max(candidate, sufMax[v + d][d]);
                cur[d] = 1 + candidate;
                ans = max(ans, cur[d]);
            }
            for (int d = 0; d <= D; d++) dp[v][d] = max(dp[v][d], cur[d]);
            // rebuild suffix max for row v
            sufMax[v][D + 1] = 0;
            for (int d = D; d >= 0; d--) sufMax[v][d] = max(sufMax[v][d + 1], dp[v][d]);
        }
        return ans;
    }
};
