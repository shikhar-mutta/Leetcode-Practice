// Link: https://leetcode.com/problems/maximum-path-intersection-sum-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(1)
//  Approach: For each row and column, calculate the maximum path sum by iterating through the grid and keeping track of the current sum and maximum sum encountered. Update the overall maximum score accordingly.
class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MIN;

        for (int i = 0; i < m; i++)
        {
            int cur = grid[i][0], curmax = INT_MIN;
            for (int j = 1; j < n; j++)
            {
                int val = cur + grid[i][j];
                curmax = max(curmax, val);
                if (i > 0 && i < m - 1 && j < n - 1)
                    curmax = max(curmax, grid[i][j]);
                cur = max(grid[i][j], val);
            }
            ans = max(ans, curmax);
        }
        for (int j = 0; j < n; j++)
        {
            int cur = grid[0][j], curmax = INT_MIN;
            for (int i = 1; i < m; i++)
            {
                int val = cur + grid[i][j];
                curmax = max(curmax, val);
                if (j > 0 && j < n - 1 && i < m - 1)
                    curmax = max(curmax, grid[i][j]);
                cur = max(grid[i][j], val);
            }
            ans = max(ans, curmax);
        }
        return ans;
    }
};