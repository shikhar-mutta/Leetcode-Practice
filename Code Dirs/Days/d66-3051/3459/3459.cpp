// Link: https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m)  SC: O(n + m)
// Approach: We can use dynamic programming to find the length of the longest V-shaped diagonal segment in the grid. We can maintain four 2D arrays to store the lengths of the diagonal segments in each direction (top-left, top-right, bottom-right, bottom-left). We can then iterate through the grid and update these arrays based on the values of the current cell and its neighbors. Finally, we can iterate through the grid again to find the maximum length of a V-shaped diagonal segment by checking the lengths of the segments in each direction.
class Solution
{
    inline static int tl[500][500], tr[500][500], br[500][500], bl[500][500];

public:
    int lenOfVDiagonal(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] != 1)
                {
                    tl[i][j] =
                        i > 0 && j > 0 && grid[i - 1][j - 1] == 2 - grid[i][j]
                            ? 1 + tl[i - 1][j - 1]
                            : 1;
                    tr[i][j] = i > 0 && j < m - 1 &&
                                       grid[i - 1][j + 1] == 2 - grid[i][j]
                                   ? 1 + tr[i - 1][j + 1]
                                   : 1;
                }

        for (int i = n - 1; i >= 0; --i)
            for (int j = m - 1; j >= 0; --j)
                if (grid[i][j] != 1)
                {
                    br[i][j] = i < n - 1 && j < m - 1 &&
                                       grid[i + 1][j + 1] == 2 - grid[i][j]
                                   ? 1 + br[i + 1][j + 1]
                                   : 1;
                    bl[i][j] = i < n - 1 && j > 0 &&
                                       grid[i + 1][j - 1] == 2 - grid[i][j]
                                   ? 1 + bl[i + 1][j - 1]
                                   : 1;
                }

        int ans = 0;

        for (int k = 0; k < n + m - 1; ++k)
            for (int i = max(0, k - m + 1), j = min(m - 1, k), found1 = 0, len;
                 i < n && j >= 0; ++i, --j)
            {
                if (grid[i][j] == 1)
                {
                    len = 1;
                    found1 = 1;
                    ans = max(ans, 1);
                    continue;
                }
                if (!found1)
                    continue;
                if ((grid[i - 1][j + 1] == 1 && grid[i][j] == 2) ||
                    grid[i - 1][j + 1] == 2 - grid[i][j])
                {
                    ++len;
                    ans = max(ans, len + tl[i][j] - 1);
                }
                else
                {
                    found1 = 0;
                }
            }

        for (int k = 0; k < n + m - 1; ++k)
            for (int i = max(0, k - m + 1), j = max(0, m - 1 - k), found1 = 0,
                     len;
                 i < n && j < m; ++i, ++j)
            {
                if (grid[i][j] == 1)
                {
                    len = 1;
                    found1 = 1;
                    ans = max(ans, 1);
                    continue;
                }
                if (!found1)
                    continue;
                if ((grid[i - 1][j - 1] == 1 && grid[i][j] == 2) ||
                    grid[i - 1][j - 1] == 2 - grid[i][j])
                {
                    ++len;
                    ans = max(ans, len + bl[i][j] - 1);
                }
                else
                {
                    found1 = 0;
                }
            }

        for (int k = 0; k < n + m - 1; ++k)
            for (int i = min(n - 1, k), j = m - 1 - max(0, k - n + 1),
                     found1 = 0, len;
                 i >= 0 && j >= 0; --i, --j)
            {
                if (grid[i][j] == 1)
                {
                    len = 1;
                    found1 = 1;
                    ans = max(ans, 1);
                    continue;
                }
                if (!found1)
                    continue;
                if ((grid[i + 1][j + 1] == 1 && grid[i][j] == 2) ||
                    grid[i + 1][j + 1] == 2 - grid[i][j])
                {
                    ++len;
                    ans = max(ans, len + tr[i][j] - 1);
                }
                else
                {
                    found1 = 0;
                }
            }

        for (int k = 0; k < n + m - 1; ++k)
            for (int i = min(n - 1, k), j = max(0, k - n + 1), found1 = 0, len;
                 i >= 0 && j < m; --i, ++j)
            {
                if (grid[i][j] == 1)
                {
                    len = 1;
                    found1 = 1;
                    ans = max(ans, 1);
                    continue;
                }
                if (!found1)
                    continue;
                if ((grid[i + 1][j - 1] == 1 && grid[i][j] == 2) ||
                    grid[i + 1][j - 1] == 2 - grid[i][j])
                {
                    ++len;
                    ans = max(ans, len + br[i][j] - 1);
                }
                else
                {
                    found1 = 0;
                }
            }

        return ans;
    }
};