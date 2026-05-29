// Link: https://leetcode.com/problems/surface-area-of-3d-shapes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] > 0)
                {
                    area += 2 + 4 * grid[i][j];
                    if (i > 0)
                        area -= 2 * min(grid[i][j], grid[i - 1][j]);
                    if (j > 0)
                        area -= 2 * min(grid[i][j], grid[i][j - 1]);
                }
            }
        }
        return area;
    }
};
