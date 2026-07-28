// Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const long long MOD = 1e9 + 7;
        int L = words[0].size();
        vector<vector<int>> cnt(L, vector<int>(26, 0));
        for (auto& w : words)
            for (int j = 0; j < L; j++)
                cnt[j][w[j] - 'a']++;
        int m = target.size();
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < L; j++) {
            for (int i = m - 1; i >= 0; i--) {
                int c = cnt[j][target[i] - 'a'];
                if (c > 0) dp[i+1] = (dp[i+1] + dp[i] * c) % MOD;
            }
        }
        return (int)dp[m];
    }
};
