// Link: https://leetcode.com/problems/zigzag-grid-traversal-with-skip/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n), SC: O(m*n)
    vector<int> zigzagTraversal(vector<vector<int>> &grid)
    {
        vector<int> result;
        int rows = grid.size(), cols = grid[0].size();
        int dir = 1;
        for (int i = 0; i < rows; i++)
        {
            if (dir == 1)
            {
                for (int j = 0; j < cols; j++)
                    if ((i + j) % 2 == 0)
                        result.push_back(grid[i][j]);
            }
            else
            {
                for (int j = cols - 1; j >= 0; j--)
                    if ((i + j) % 2 == 0)
                        result.push_back(grid[i][j]);
            }
            dir *= -1;
        }
        return result;
    }
};
