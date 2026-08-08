// Link: https://leetcode.com/problems/longest-arithmetic-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        int best = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int len = 2;
                if (dp[j].count(diff)) len = dp[j][diff] + 1;
                dp[i][diff] = max(dp[i][diff], len);
                best = max(best, dp[i][diff]);
            }
        }
        return best;
    }
};
