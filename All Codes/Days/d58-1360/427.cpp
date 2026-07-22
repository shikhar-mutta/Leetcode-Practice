// Link: https://leetcode.com/problems/construct-quad-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the length of the grid
// SC: O(log n) for the recursion stack
// Approach:
//   1. We can use a recursive approach to construct the quad tree.
//   2. We can check if the current grid is uniform (all 0s or all 1s). If it is, we create a leaf node with the value of the grid.
//   3. If the grid is not uniform, we divide the grid into four quadrants and recursively construct the quad tree for each quadrant.
//   4. Finally, we create a non-leaf node with the four child nodes and return it.
class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        return buildTree(grid, 0, 0, grid.size());
    }

private:
    Node *buildTree(vector<vector<int>> &grid, int r, int c, int len)
    {
        if (isUniform(grid, r, c, len))
        {
            return new Node(grid[r][c] == 1, true);
        }

        int half = len / 2;
        Node *topLeft = buildTree(grid, r, c, half);
        Node *topRight = buildTree(grid, r, c + half, half);
        Node *bottomLeft = buildTree(grid, r + half, c, half);
        Node *bottomRight = buildTree(grid, r + half, c + half, half);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    bool isUniform(vector<vector<int>> &grid, int r, int c, int len)
    {
        int target = grid[r][c];
        for (int i = r; i < r + len; ++i)
        {
            for (int j = c; j < c + len; ++j)
            {
                if (grid[i][j] != target)
                {
                    return false;
                }
            }
        }
        return true;
    }
};