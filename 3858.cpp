// Link: https://leetcode.com/problems/minimum-bitwise-or-from-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOR(vector<vector<int>> &grid)
    {
        int minimum = INT_MAX;
        int n = grid.size(), m = grid[0].size();
        vector<unordered_set<int>> seen(n);
        auto dfs = [&](auto &&dfs, int currRow, int bitwiseOr) -> void
        {
            if (bitwiseOr >= minimum) // OR only grows; can't beat best
            {
                return;
            }
            if (currRow < 0)
            {
                minimum = bitwiseOr;
                return;
            }
            if (seen[currRow].count(bitwiseOr))
            {
                return;
            }
            seen[currRow].insert(bitwiseOr);
            for (int k = 0; k < m; k++)
            {
                dfs(dfs, currRow - 1, bitwiseOr | grid[currRow][k]);
            }
        };
        dfs(dfs, n - 1, 0);
        return minimum;
    }
};
