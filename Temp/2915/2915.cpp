// Link: https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int x : nums) {
            for (int s = target; s >= x; s--) {
                if (dp[s - x] != INT_MIN) dp[s] = max(dp[s], dp[s - x] + 1);
            }
        }
        return dp[target] == INT_MIN ? -1 : dp[target];
    }
};
