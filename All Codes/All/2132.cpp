// Link: https://leetcode.com/problems/stamping-the-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(m*n)
//  Approach: The problem can be solved by using a prefix sum array to keep track of the number of empty cells in the grid. We can then iterate through the grid and check if we can place a stamp at each cell. If we can place a stamp, we update the prefix sum array accordingly. Finally, we check if all empty cells can be covered by the stamps.
class Solution
{
public:
    bool possibleToStamp(vector<vector<int>> &grid, int sh, int sw)
    {
        int m = grid.size();
        int n = grid[0].size();
        int pf[m + 1][n + 1];
        memset(pf, 0, sizeof(pf));
        int diff[m + 1][n + 1];
        memset(diff, 0, sizeof(diff));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                pf[i + 1][j + 1] =
                    pf[i][j + 1] + pf[i + 1][j] - pf[i][j] + (grid[i][j] == 0);
            }
        }
        int sum = sh * sw;
        for (int i = sh; i <= m; ++i)
        {
            for (int j = sw; j <= n; ++j)
            {
                int total = pf[i][j] - pf[i][j - sw] - pf[i - sh][j] +
                            pf[i - sh][j - sw];
                // cout << i << " " << j << " " << total << endl;
                if (sum == total)
                {
                    ++diff[i][j];
                    --diff[i][j - sw];
                    --diff[i - sh][j];
                    ++diff[i - sh][j - sw];
                }
            }
        }
        for (int i = m; i > 0; --i)
        {
            for (int j = n; j > 0; --j)
            {
                if (i + 1 <= m)
                    diff[i][j] += diff[i + 1][j];
                if (j + 1 <= n)
                    diff[i][j] += diff[i][j + 1];
                if (i + 1 <= m && j + 1 <= n)
                    diff[i][j] -= diff[i + 1][j + 1];
                // cout << i << " " << j << " " << diff[i][j] << " " <<  grid[i
                // - 1][j - 1] <<endl;
                if (diff[i][j] <= 0 && grid[i - 1][j - 1] == 0)
                    return false;
            }
        }
        return true;
    }
};
