// Link: https://leetcode.com/problems/strange-printer-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: We can use a greedy approach to solve this problem. We can keep track of the minimum and maximum row and column indices for each color in the grid. Then, we can iterate through each color and check if we can print it by checking if all the cells in its bounding box are either 0 or the same color. If we can print it, we set all the cells in its bounding box to 0 and mark it as printed. We repeat this process until we cannot print any more colors. If there are still colors left to print, we return false. Otherwise, we return true.
class Solution
{
public:
    bool check(vector<vector<int>> &grid, int minrow, int maxrow, int mincol,
               int maxcol, int val)
    {
        for (int r = minrow; r <= maxrow; r++)
        {
            for (int c = mincol; c <= maxcol; c++)
            {
                if (grid[r][c] != 0 && grid[r][c] != val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isPrintable(vector<vector<int>> &grid)
    {
        vector<int> marow(61, INT_MIN);
        vector<int> mirow(61, INT_MAX);
        vector<int> macol(61, INT_MIN);
        vector<int> micol(61, INT_MAX);
        vector<bool> pres(61, 0);
        int trow = grid.size();
        int tcol = grid[0].size();
        for (int r = 0; r < trow; r++)
        {
            for (int c = 0; c < tcol; c++)
            {
                int num = grid[r][c];
                mirow[num] = min(r, mirow[num]);
                marow[num] = max(r, marow[num]);
                micol[num] = min(c, micol[num]);
                macol[num] = max(c, macol[num]);
                pres[num] = 1;
            }
        }
        int n = 60;
        while (1)
        {
            int i;
            for (i = 1; i <= n; i++)
            {
                if (pres[i])
                {
                    int minrow = mirow[i];
                    int maxrow = marow[i];
                    int mincol = micol[i];
                    int maxcol = macol[i];
                    if (check(grid, minrow, maxrow, mincol, maxcol, i))
                    {
                        for (int r = minrow; r <= maxrow; r++)
                        {
                            for (int c = mincol; c <= maxcol; c++)
                            {
                                grid[r][c] = 0;
                            }
                        }
                        pres[i] = 0;
                        break;
                    }
                }
            }
            if (i == n + 1)
            {
                for (int i = 1; i < 62; i++)
                {
                    if (pres[i])
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
};