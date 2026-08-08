// Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const long long MOD = 1e9 + 7;
        int n = words[0].size();
        vector<vector<long long>> cnt(26, vector<long long>(n, 0));
        for (auto& w : words)
            for (int j = 0; j < n; j++)
                cnt[w[j] - 'a'][j]++;

        int m = target.size();
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i >= 0; i--) {
                long long c = cnt[target[i] - 'a'][j];
                if (c) dp[i+1] = (dp[i+1] + dp[i] * c) % MOD;
            }
        }
        return (int)dp[m];
    }
};
