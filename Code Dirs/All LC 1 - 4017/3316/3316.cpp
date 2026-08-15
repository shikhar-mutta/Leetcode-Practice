// Link: https://leetcode.com/problems/find-maximum-removals-from-source-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size(), m = pattern.size();
        vector<bool> isTarget(n, false);
        for (int idx : targetIndices) isTarget[idx] = true;

        const int NEG = INT_MIN / 2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, NEG));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (dp[i][j] <= NEG / 2) continue;
                int val = dp[i][j];
                // delete (only if target)
                if (isTarget[i]) {
                    dp[i+1][j] = max(dp[i+1][j], val + 1);
                }
                // keep, don't use for pattern
                dp[i+1][j] = max(dp[i+1][j], val);
                // keep, use for pattern
                if (j < m && source[i] == pattern[j]) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], val);
                }
            }
        }

        return dp[n][m];
    }
};
