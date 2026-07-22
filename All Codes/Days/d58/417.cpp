// Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(m*n)
//  Approach:
//   1. Create two boolean matrices to keep track of cells that can reach the Pacific and Atlantic oceans.
//   2. Perform DFS from the cells adjacent to the Pacific and Atlantic oceans
//   3. For each cell, if it can reach both oceans, add it to the result list.
//   4. Return the result list.
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
        return result;
    }

private:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int i, int j)
    {
        visited[i][j] = true;
        int m = heights.size(), n = heights[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dr[d], nj = j + dc[d];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && heights[ni][nj] >= heights[i][j])
                dfs(heights, visited, ni, nj);
        }
    }
};
