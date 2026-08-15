// Link: https://leetcode.com/problems/count-distinct-ways-to-form-target-from-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007;

    long long solveCount(const string &word1, const string &word2, const string &target, bool useWord2) {
        int n1 = word1.size();
        int n2 = useWord2 ? word2.size() : 0;
        int m = target.size();
        vector<vector<long long>> dp(n1 + 1, vector<long long>(n2 + 1, 1));
        for (int p = m - 1; p >= 0; p--) {
            vector<vector<long long>> ndp(n1 + 1, vector<long long>(n2 + 1, 0));
            char c = target[p];
            for (int idx2 = 0; idx2 <= n2; idx2++) {
                long long suf = 0;
                for (int idx1 = n1 - 1; idx1 >= 0; idx1--) {
                    if (word1[idx1] == c) suf = (suf + dp[idx1 + 1][idx2]) % MOD;
                    ndp[idx1][idx2] = (ndp[idx1][idx2] + suf) % MOD;
                }
            }
            for (int idx1 = 0; idx1 <= n1; idx1++) {
                long long suf = 0;
                for (int idx2 = n2 - 1; idx2 >= 0; idx2--) {
                    if (useWord2 && word2[idx2] == c) suf = (suf + dp[idx1][idx2 + 1]) % MOD;
                    ndp[idx1][idx2] = (ndp[idx1][idx2] + suf) % MOD;
                }
            }
            dp = ndp;
        }
        return dp[0][0];
    }

    int interleaveCharacters(string word1, string word2, string target) {
        long long total = solveCount(word1, word2, target, true);
        long long only1 = solveCount(word1, word2, target, false);
        long long only2 = solveCount(word2, word1, target, false);
        long long ans = ((total - only1 - only2) % MOD + MOD) % MOD;
        return (int)ans;
    }
};
