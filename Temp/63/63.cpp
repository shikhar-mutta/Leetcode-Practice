// Link: https://leetcode.com/problems/unique-paths-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(n)
// Approach: DP over a single row; obstacle cells force dp[j]=0, else dp[j]+=dp[j-1]
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long long> dp(n, 0);
        dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) { dp[j] = 0; continue; }
                if (j > 0) dp[j] += dp[j-1];
            }
        }
        return (int)dp[n-1];
    }
};
