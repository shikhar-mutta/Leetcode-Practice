// Link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const long long MOD = 1e9 + 7;
        int n = hats.size();
        vector<vector<int>> peopleForHat(41);
        for (int p = 0; p < n; p++) {
            for (int h : hats[p]) peopleForHat[h].push_back(p);
        }

        int full = 1 << n;
        vector<long long> dp(full, 0);
        dp[0] = 1;

        for (int h = 1; h <= 40; h++) {
            vector<long long> ndp = dp;
            for (int p : peopleForHat[h]) {
                for (int mask = 0; mask < full; mask++) {
                    if (mask & (1 << p)) continue;
                    ndp[mask | (1 << p)] = (ndp[mask | (1 << p)] + dp[mask]) % MOD;
                }
            }
            dp = ndp;
        }
        return (int)dp[full - 1];
    }
};
