// Link: https://leetcode.com/problems/number-of-ways-to-earn-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (auto &t : types) {
            int count = t[0], marks = t[1];
            vector<long long> ndp(target + 1, 0);
            for (int s = 0; s <= target; s++) {
                if (dp[s] == 0) continue;
                for (int k = 0; k <= count; k++) {
                    long long ns = (long long)s + (long long)k * marks;
                    if (ns > target) break;
                    ndp[ns] = (ndp[ns] + dp[s]) % MOD;
                }
            }
            dp = ndp;
        }
        return (int)dp[target];
    }
};
