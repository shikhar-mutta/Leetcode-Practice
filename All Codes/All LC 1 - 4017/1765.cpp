// Link: https://leetcode.com/problems/map-of-highest-peak/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(1)
// Approach: Dynamic Programming
//   1. We can iterate through the grid from top-left to bottom-right and update the height of each cell based on the minimum height of its neighbors.
//   2. We can then iterate through the grid from bottom-right to top-left and update the height of each cell based on the minimum height of its neighbors.
//   3. Finally, we can return the updated grid.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fornr(i, n) for (int i = n - 1; i >= 0; --i)

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size();
        forn(i, m) forn(j, n)
        {
            int &x = g[i][j];
            x = x ? 0 : 0x3f3f3f3f;
            if (i) [[likely]]
                x = min(g[i - 1][j] + 1, x);
            if (j) [[likely]]
                x = min(g[i][j - 1] + 1, x);
        }
        fornr(i, m) fornr(j, n)
        {
            int &x = g[i][j];
            if (i < m - 1) [[likely]]
                x = min(g[i + 1][j] + 1, x);
            if (j < n - 1) [[likely]]
                x = min(g[i][j + 1] + 1, x);
        }
        return g;
    }
};