// Link: https://leetcode.com/problems/minimum-cost-to-split-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: dp[i] = min cost for nums[0:i]. For each i, scan the last segment's start j from
// i-1 down to 0, maintaining a running frequency count so trimmed-length (dupCount) updates
// incrementally: +2 when a value first becomes duplicated, +1 for each further repeat.
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> freq(n, 0);
            int dupCount = 0;
            for (int j = i-1; j >= 0; j--) {
                int v = nums[j];
                freq[v]++;
                if (freq[v] == 2) dupCount += 2;
                else if (freq[v] > 2) dupCount += 1;
                if (dp[j] != INT_MAX) dp[i] = min(dp[i], dp[j] + k + dupCount);
            }
        }
        return dp[n];
    }
};
