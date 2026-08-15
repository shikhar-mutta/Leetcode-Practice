// Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX / 2));
        dp[0][0] = 0;

        for (int day = 1; day <= d; day++) {
            for (int i = day; i <= n; i++) {
                int maxDiff = 0;
                for (int j = i; j >= day; j--) {
                    maxDiff = max(maxDiff, jobDifficulty[j-1]);
                    dp[day][i] = min(dp[day][i], dp[day-1][j-1] + maxDiff);
                }
            }
        }
        return dp[d][n];
    }
};
