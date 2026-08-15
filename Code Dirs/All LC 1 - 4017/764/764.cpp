// Link: https://leetcode.com/problems/largest-plus-sign/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: for each cell compute the run length of consecutive non-mine cells in each of the 4 directions using DP sweeps; the plus-sign order at a cell is the min of the 4 directional run lengths. Track the max.
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<bool>> mine(n, vector<bool>(n, false));
        for (auto& m : mines) mine[m[0]][m[1]] = true;
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) { count = mine[i][j] ? 0 : count+1; dp[i][j] = min(dp[i][j], count); }
            count = 0;
            for (int j = n-1; j >= 0; j--) { count = mine[i][j] ? 0 : count+1; dp[i][j] = min(dp[i][j], count); }
        }
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) { count = mine[i][j] ? 0 : count+1; dp[i][j] = min(dp[i][j], count); }
            count = 0;
            for (int i = n-1; i >= 0; i--) { count = mine[i][j] ? 0 : count+1; dp[i][j] = min(dp[i][j], count); }
        }
        int best = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) best = max(best, dp[i][j]);
        return best;
    }
};
