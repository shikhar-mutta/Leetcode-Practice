// Link: https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// SC: O(n)
// Approach: DP where dp[i] = max jumps to reach index i from index 0 (-1 if
// unreachable). For each i, try every earlier reachable j whose value is
// within `target` of nums[i], taking the best dp[j]+1. Answer is dp[n-1].
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp array to store max jumps till index i
        vector<int> dp(n, -1);

        // First index is reachable with 0 jumps
        dp[0]=0;

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                // Check if the condition holds true and prev index was visited
                if(abs(nums[i]-nums[j]) <= target && dp[j]>-1) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        return dp[n-1];
    }
};
