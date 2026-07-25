// Link: https://leetcode.com/problems/cyclically-rotating-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(m*n)
//  Approach:
//    1. We can iterate through each layer of the grid and extract the elements in that layer into a 1D vector (ring).
//    2. We can then rotate the elements in the ring by k positions using the rotate function from the STL.
//    3. Finally, we can place the rotated elements back into their respective positions in the grid.
class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; ++layer)
        {
            int top = layer, bottom = m - 1 - layer;
            int left = layer, right = n - 1 - layer;

            vector<int> ring;
            for (int r = top; r <= bottom; ++r)
                ring.push_back(grid[r][left]);
            for (int c = left + 1; c <= right; ++c)
                ring.push_back(grid[bottom][c]);
            for (int r = bottom - 1; r >= top; --r)
                ring.push_back(grid[r][right]);
            for (int c = right - 1; c > left; --c)
                ring.push_back(grid[top][c]);

            int len = ring.size();
            int shift = k % len;
            rotate(ring.begin(), ring.begin() + (len - shift) % len,
                   ring.end());

            int idx = 0;
            for (int r = top; r <= bottom; ++r)
                grid[r][left] = ring[idx++];
            for (int c = left + 1; c <= right; ++c)
                grid[bottom][c] = ring[idx++];
            for (int r = bottom - 1; r >= top; --r)
                grid[r][right] = ring[idx++];
            for (int c = right - 1; c > left; --c)
                grid[top][c] = ring[idx++];
        }
        return grid;
    }
};
