// Link: https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n) SC: O(m * n)
// Approach: the start cell (0,0) is entered for free (no preceding wait
// needed), and the final destination is never waited at (the path stops
// on arrival). Every OTHER visited cell always gets exactly one wait
// right after being entered, since moves and waits strictly alternate
// and the path length is fixed. So dp[i][j] = min(dp[i-1][j], dp[i][j-1])
// + entryCost(i,j), then immediately add waitCost[i][j] unless (i,j) is
// (0,0) or the destination.
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long entry = (long long)(i + 1) * (j + 1);
                long long val;
                if (i == 0 && j == 0) {
                    val = entry;
                } else {
                    long long best = LLONG_MAX;
                    if (i > 0) best = min(best, dp[i-1][j]);
                    if (j > 0) best = min(best, dp[i][j-1]);
                    val = best + entry;
                }
                bool isStart = (i == 0 && j == 0);
                bool isDest = (i == m - 1 && j == n - 1);
                if (!isStart && !isDest) val += waitCost[i][j];
                dp[i][j] = val;
            }
        }
        return dp[m-1][n-1];
    }
};
