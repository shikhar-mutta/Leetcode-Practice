// Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: dp[i][j] = length of common suffix ending at nums1[i-1], nums2[j-1]; if equal, dp[i][j] = dp[i-1][j-1]+1, else 0. Track max.
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int best = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    best = max(best, dp[i][j]);
                }
            }
        }
        return best;
    }
};
