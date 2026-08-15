// Link: https://leetcode.com/problems/number-of-beautiful-partitions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrimeDigit(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }

    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        const long long MOD = 1e9 + 7;
        if (!isPrimeDigit(s[0]) || isPrimeDigit(s[n-1])) return 0;

        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int j = 1; j <= k; j++) {
            vector<long long> prefixSum(n, 0);
            prefixSum[0] = isPrimeDigit(s[0]) ? dp[j-1][0] : 0;
            for (int p = 1; p < n; p++) {
                prefixSum[p] = prefixSum[p-1];
                if (isPrimeDigit(s[p])) prefixSum[p] = (prefixSum[p] + dp[j-1][p]) % MOD;
            }
            for (int i = minLength; i <= n; i++) {
                if (!isPrimeDigit(s[i-1])) {
                    int p = i - minLength;
                    if (p >= 0) dp[j][i] = prefixSum[p];
                }
            }
        }
        return (int)dp[k][n];
    }
};
