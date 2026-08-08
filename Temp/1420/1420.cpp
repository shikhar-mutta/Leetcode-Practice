// Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k == 0) return 0;
        const long long MOD = 1e9 + 7;
        // dp[maxVal][cost]
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, 0));
        for (int v = 1; v <= m; v++) dp[v][1] = 1;

        for (int len = 2; len <= n; len++) {
            vector<vector<long long>> ndp(m + 1, vector<long long>(k + 1, 0));
            // prefix sums over maxVal for each cost, to speed up "new max" transition
            vector<vector<long long>> prefix(m + 2, vector<long long>(k + 1, 0));
            for (int v = 1; v <= m; v++) {
                for (int c = 0; c <= k; c++) {
                    prefix[v][c] = prefix[v-1][c] + dp[v][c];
                }
            }
            for (int v = 1; v <= m; v++) {
                for (int c = 1; c <= k; c++) {
                    // stay: pick value <= v, cost unchanged
                    long long stay = dp[v][c] * v % MOD;
                    // new max: previous max < v, cost-1 -> cost
                    long long newMax = prefix[v-1][c-1] % MOD;
                    ndp[v][c] = (stay + newMax) % MOD;
                }
            }
            dp = ndp;
        }

        long long total = 0;
        for (int v = 1; v <= m; v++) total = (total + dp[v][k]) % MOD;
        return (int)total;
    }
};
