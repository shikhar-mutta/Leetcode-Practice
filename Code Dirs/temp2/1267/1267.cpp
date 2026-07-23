// Link: https://leetcode.com/problems/count-servers-that-communicate/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                {
                    ++row[i];
                    ++col[j];
                }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] && (row[i] > 1 || col[j] > 1))
                    ++res;
        return res;
    }
};