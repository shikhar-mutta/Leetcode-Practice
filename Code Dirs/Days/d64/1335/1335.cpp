// Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * d)  SC: O(n * d)
// Approach: dp[i][day] = min total difficulty to schedule the first i
// jobs over `day` days. Transition: for the last day's segment
// [j+1..i], its cost is the max difficulty in that range; try every
// split point j, tracking the running max as j decreases from i-1.
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int day = 1; day <= min(i, d); day++) {
                int maxDiff = 0;
                for (int j = i - 1; j >= day - 1; j--) {
                    maxDiff = max(maxDiff, jobDifficulty[j]);
                    dp[i][day] = min(dp[i][day], dp[j][day - 1] + maxDiff);
                }
            }
        }
        return dp[n][d];
    }
};
