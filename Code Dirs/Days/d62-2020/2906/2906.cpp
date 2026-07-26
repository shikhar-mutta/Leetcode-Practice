// Link: https://leetcode.com/problems/construct-product-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)
// SC: O(m*n) for the answer matrix
// Approach: traverse the grid in row-major order and store the product of all
// previous cells modulo 12345. Then traverse backward and multiply each cell by
// the product of all later cells. This gives product of every cell except the
// current one without using division, so zero values are handled naturally.
class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        long long pro = 1;
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = pro;
                pro = (pro * grid[i][j]) % 12345;

                if (grid[i][j] == 0)
                    count++;
            }

            if (count > 1)
            {
                return vector<vector<int>>(m, vector<int>(n, 0));
            }
        }

        pro = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                ans[i][j] = (1LL * ans[i][j] * pro) % 12345;
                pro = (pro * grid[i][j]) % 12345;
            }
        }

        return ans;
    }
};
