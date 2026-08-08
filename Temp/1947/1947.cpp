// Link: https://leetcode.com/problems/maximum-compatibility-score-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size(), m = students[0].size();
        vector<vector<int>> score(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (students[i][k] == mentors[j][k]) score[i][j]++;
                }
            }
        }

        vector<int> dp(1 << n, INT_MIN);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == INT_MIN) continue;
            int i = __builtin_popcount(mask);
            if (i >= n) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                int nmask = mask | (1 << j);
                dp[nmask] = max(dp[nmask], dp[mask] + score[i][j]);
            }
        }
        return dp[(1 << n) - 1];
    }
};
