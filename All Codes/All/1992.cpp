// Link: https://leetcode.com/problems/find-all-groups-of-farmland/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m), SC: O(1)
// Approach:
// 1. Iterate through the grid and for each cell with value 1, assign it a unique identifier based on its position.
// 2. If the cell has a left neighbor with value 1, assign it the same identifier as the left neighbor.
// 3. If the cell has an upper neighbor with value 1, assign it the same identifier as the upper neighbor.
// 4. If the cell is the bottom-right corner of a farmland group (i.e., it has no right or bottom neighbor with value 1), record the coordinates of the top-left and bottom-right corners of the farmland group in the result vector.
//  5. Return the result vector containing the coordinates of all farmland groups.
class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &g)
    {
        int h = g.size(), w = g[0].size();
        vector<vector<int>> r;
        r.reserve((w * h) / 2);
        for (int y = 0; y != h; ++y)
        {
            for (int x = 0; x != w; ++x)
            {
                int i = 1 + w * y + x;
                if (!g[y][x])
                    continue;
                if (x && g[y][x - 1])
                {
                    i = g[y][x - 1];
                }
                if (y && g[y - 1][x])
                {
                    i = g[y - 1][x];
                }
                g[y][x] = i;

                if ((x + 1 == w || !g[y][x + 1]) &&
                    (y + 1 == h || !g[y + 1][x]))
                {
                    --i;
                    int py = i / w;
                    int px = i % w;
                    r.push_back({py, px, y, x});
                }
            }
        }

        return r;
    }
};