// Link: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R*C)  SC: O(R*C)
//  Approach: memoized DFS. dp[i][j] = number of strictly-increasing paths
//  starting at (i,j) (including the trivial single-cell path). Sum dp over
//  all cells for the total count mod 1e9+7.
class Solution
{
public:
    long long MOD = 1000000007;
    void dfs(vector<vector<int>> &grid, vector<vector<long long>> &count, int i,
             int j, int m, int n, long long &ans)
    {
        if (i >= m || j >= n || i < 0 || j < 0)
            return;
        long long sum = 0;
        if (i - 1 >= 0 && grid[i - 1][j] > grid[i][j])
        {
            if (count[i - 1][j] != -1)
            {
                sum += count[i - 1][j];
                sum = sum % MOD;
            }
            else
            {
                dfs(grid, count, i - 1, j, m, n, ans);
                sum += count[i - 1][j];
                sum = sum % MOD;
            }
        }
        if (i + 1 < m && grid[i + 1][j] > grid[i][j])
        {
            if (count[i + 1][j] != -1)
            {
                sum += count[i + 1][j];
                sum = sum % MOD;
            }
            else
            {
                dfs(grid, count, i + 1, j, m, n, ans);
                sum += count[i + 1][j];
                sum = sum % MOD;
            }
        }
        if (j - 1 >= 0 && grid[i][j - 1] > grid[i][j])
        {
            if (count[i][j - 1] != -1)
            {
                sum += count[i][j - 1];
                sum = sum % MOD;
            }
            else
            {
                dfs(grid, count, i, j - 1, m, n, ans);
                sum += count[i][j - 1];
                sum = sum % MOD;
            }
        }
        if (j + 1 < n && grid[i][j + 1] > grid[i][j])
        {
            if (count[i][j + 1] != -1)
            {
                sum += count[i][j + 1];
                sum = sum % MOD;
            }
            else
            {
                dfs(grid, count, i, j + 1, m, n, ans);
                sum += count[i][j + 1];
                sum = sum % MOD;
            }
        }
        sum += 1;
        count[i][j] = sum;
        ans = (ans + sum) % MOD;
        return;
    }
    int countPaths(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> count(m, vector<long long>(n, -1));
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (count[i][j] != -1)
                    continue;
                dfs(grid, count, i, j, m, n, ans);
            }
        }
        return ans;
    }
};