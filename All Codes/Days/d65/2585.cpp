// Link: https://leetcode.com/problems/number-of-ways-to-earn-points/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(numTypes * target * maxCount), SC: O(target)
// Approach: bounded knapsack DP. dp[s] = number of ways to reach score s using types processed
// so far; for each type, iterate score descending in outer count loop (0/1-per-question style
// with an explicit count bound) to avoid reusing the same type's question more than its count.
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const long long MOD = 1e9+7;
        vector<long long> dp(target+1, 0);
        dp[0] = 1;
        for (auto& t : types) {
            int count = t[0], marks = t[1];
            vector<long long> ndp(target+1, 0);
            for (int s = 0; s <= target; s++) {
                if (!dp[s]) continue;
                for (int c = 0; c <= count && s + (long long)c*marks <= target; c++) {
                    ndp[s + c*marks] = (ndp[s + c*marks] + dp[s]) % MOD;
                }
            }
            dp = ndp;
        }
        return (int)dp[target];
    }
};
