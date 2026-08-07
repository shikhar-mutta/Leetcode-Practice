// Link: https://leetcode.com/problems/dungeon-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(n)
// Approach: DP backward from the bottom-right; dp[i][j] = min HP needed entering cell (i,j) to survive
// the rest of the path, clamped to at least 1
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n-1] = dp[m-1][n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(1, need);
            }
        }
        return dp[0][0];
    }
};
