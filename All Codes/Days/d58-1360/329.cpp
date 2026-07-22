// Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) where m is the number of rows and n is the number of columns in the input matrix a.
// SC: O(m*n) for the dp array used to store the length of the longest increasing path starting from each cell in the matrix.
// Approach:
//   1. We can use a depth-first search (DFS) approach to solve this problem. We start by initializing a 2D dp array to store the length of the longest increasing path starting from each cell in the matrix. We also define a helper function dfs that takes the current cell coordinates (i, j) and the input matrix a as parameters. In the dfs function, we first check if the length of the longest increasing path starting from the current cell has already been computed and stored in the dp array. If it has, we return the stored value. Otherwise, we initialize a variable ans to 0 and iterate through the four possible directions (up, down, left, right) to explore the neighboring cells. For each neighboring cell, we check if it is within the bounds of the matrix and if its value is greater than the value of the current cell. If both conditions are satisfied, we recursively call the dfs function on the neighboring cell and update ans with the maximum length of the increasing path found so far. Finally, we store the computed length of the longest increasing path starting from the current cell in the dp array and return the value. In the longestIncreasingPath function, we iterate through all the cells in the matrix and call the dfs function on each cell to compute the length of the longest increasing path starting from that cell. We keep track of the maximum length found and return it as the final answer.
class Solution
{
public:
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int dp[201][201];
    int dfs(int i, int j, vector<vector<int>> &a)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for (int k = 0; k < 4; k++)
        {
            int ti = i + dx[k];
            int tj = j + dy[k];
            if (ti < 0 or tj < 0 or ti >= m or tj >= n or a[ti][tj] <= a[i][j])
                continue;
            ans = max(ans, dfs(ti, tj, a));
        }
        return dp[i][j] = ans + 1;
    }
    int longestIncreasingPath(vector<vector<int>> &a)
    {
        m = a.size();
        n = a[0].size();
        int ans = 1;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, dfs(i, j, a));
            }
        }
        return ans;
    }
};