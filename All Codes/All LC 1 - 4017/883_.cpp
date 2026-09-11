// Link: https://leetcode.com/problems/projection-area-of-3d-shapes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int xy = 0, yz = 0, zx = 0;
        for (int i = 0; i < n; i++)
        {
            int maxRow = 0, maxCol = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                    xy++;
                maxRow = max(maxRow, grid[i][j]);
                maxCol = max(maxCol, grid[j][i]);
            }
            yz += maxRow;
            zx += maxCol;
        }
        return xy + yz + zx;
    }
};
