// Link: https://leetcode.com/problems/largest-plus-sign/description/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e2;

static int g[N][N], u[N][N], d[N][N], l[N][N], r[N][N];

// TC: O(n^2), SC: O(n^2)
// Approach:
//  1. The function initializes a grid of size n x n with all cells set to 1, representing the presence of a plus sign.
//  2. It then marks the cells corresponding to the positions of mines (given in the vector m) as 0, indicating that a plus sign cannot be formed at those positions.
//  3. The function calculates the number of consecutive 1s in the upward, downward, leftward, and rightward directions for each cell in the grid, storing these counts in the respective matrices u, d, l, and r.
//  4. Finally, it iterates through the grid to find the maximum order of a plus sign that can be formed, which is determined by the minimum of the counts in the four directions for each cell. The maximum order found is returned as the result.
//  5. The function returns 0 if the entire grid is filled with mines, as no plus sign can be formed in that case.
class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &m)
    {
        if (m.size() == n * n)
            return 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                g[i][j] = 1;
        }
        for (auto &v : m)
            g[v[0]][v[1]] = 0;
        for (int i = 0; i < n; i++)
            u[0][i] = g[0][i];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                u[i][j] = g[i][j] ? u[i - 1][j] + 1 : 0;
        }
        for (int i = 0; i < n; i++)
            d[n - 1][i] = g[n - 1][i];
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
                d[i][j] = g[i][j] ? d[i + 1][j] + 1 : 0;
        }
        for (int i = 0; i < n; i++)
        {
            l[i][0] = g[i][0];
            for (int j = 1; j < n; j++)
                l[i][j] = g[i][j] ? l[i][j - 1] + 1 : 0;
        }
        for (int i = 0; i < n; i++)
        {
            r[i][n - 1] = g[i][n - 1];
            for (int j = n - 2; j >= 0; j--)
                r[i][j] = g[i][j] ? r[i][j + 1] + 1 : 0;
        }
        int mx = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (g[i][j])
                {
                    int mn = min(u[i - 1][j], min(d[i + 1][j], min(l[i][j - 1], r[i][j + 1])));
                    mx = max(mx, mn);
                }
            }
        }
        return mx + 1;
    }
};