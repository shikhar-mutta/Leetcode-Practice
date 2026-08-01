// Link: https://leetcode.com/problems/minimum-partition-score/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * k)  SC: O(n * k)
// Approach: standard partition DP. dp[i][j] = min score splitting the
// first i elements into j contiguous subarrays; a subarray's value is the
// triangular number of its sum, s*(s+1)/2. Transition tries every previous
// split point: dp[i][j] = min over prev of dp[prev][j-1] + value(prefix[i]
// - prefix[prev]).
class Solution {
public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        auto value = [](long long s) { return s * (s + 1) / 2; };

        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                for (int prev = j - 1; prev < i; prev++) {
                    if (dp[prev][j-1] == INF) continue;
                    long long s = prefix[i] - prefix[prev];
                    dp[i][j] = min(dp[i][j], dp[prev][j-1] + value(s));
                }
            }
        }
        return dp[n][k];
    }
};
