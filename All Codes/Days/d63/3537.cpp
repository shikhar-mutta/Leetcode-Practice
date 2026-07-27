// Link: https://leetcode.com/problems/fill-a-special-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC:   O(n^2) SC: O(n^2)
// Approach: The grid is filled in a recursive manner. The grid is divided into four quadrants, and the values are filled in each quadrant based on the values in the previous quadrant. The top-right quadrant is filled with the values from the top-left quadrant, the bottom-right quadrant is filled with the values from the top-left quadrant plus a certain offset, and the bottom-left quadrant is filled with the values from the top-left quadrant plus a different offset. This process continues until the entire grid is filled.
class Solution
{
public:
    vector<vector<int>> specialGrid(int n)
    {
        int m = 1 << n;
        vector<vector<int>> ans(m, vector<int>(m));
        int i = 0;
        int j = m - 1;
        int c = 1;
        ans[i][j] = 0;
        while (c * 2 <= m)
        {
            int ib = 0;
            int ie = ib + c;
            int jb = m - c;
            int je = m;
            int diff_br = c * c;
            int diff_bl = c * c * 2;
            int diff_tl = c * c * 3;
            for (int it = ib; it < ie; ++it)
            {
                for (int jt = jb; jt < je; ++jt)
                {
                    ans[it + c][jt] = diff_br + ans[it][jt];
                    ans[it + c][jt - c] = diff_bl + ans[it][jt];
                    ans[it][jt - c] = diff_tl + ans[it][jt];
                }
            }
            c *= 2;
        }
        return ans;
    }
};