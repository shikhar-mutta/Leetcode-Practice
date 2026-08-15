// Link: https://leetcode.com/problems/valid-permutations-for-di-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPermsDISequence(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 1);
        for (char c : s) {
            int m = dp.size();
            vector<long long> next(m - 1, 0);
            if (c == 'I') {
                for (int j = 0; j < m - 1; j++) {
                    for (int k = 0; k <= j; k++) next[j] = (next[j] + dp[k]) % MOD;
                }
            } else {
                for (int j = 0; j < m - 1; j++) {
                    for (int k = j + 1; k < m; k++) next[j] = (next[j] + dp[k]) % MOD;
                }
            }
            dp = next;
        }
        long long res = 0;
        for (long long v : dp) res = (res + v) % MOD;
        return (int)res;
    }
};
