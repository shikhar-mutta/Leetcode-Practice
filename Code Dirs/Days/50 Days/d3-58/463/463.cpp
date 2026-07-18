// Link: https://leetcode.com/problems/island-perimeter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int r = grid.size(), c = grid[0].size();
        // dx and dy arrays to represent the four possible directions (up, down, left, right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                // If the current cell is water (0), skip it
                if (!grid[i][j]) continue;
                // For each land cell (1), check its four neighbors
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dx[d], nj = j + dy[d];
                    // If the neighbor is out of bounds or is water, it contributes to the perimeter
                    if (ni < 0 || ni >= r || nj < 0 || nj >= c || !grid[ni][nj])
                        cnt++;
                }
            }
        }
        return cnt;
    }
};