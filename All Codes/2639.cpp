// Link: https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m * log(maxElement)), SC: O(m)
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> ans(m, 0);
        auto getWidth = [](int num)
        {
            if (num == 0)
                return 1;
            int width = 0;
            if (num < 0)
            {
                width++;
                num = -num;
            }
            while (num > 0)
            {
                width++;
                num /= 10;
            }
            return width;
        };

        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
            {
                int width = getWidth(grid[i][j]);
                ans[j] = max(ans[j], width);
            }

        return ans;
    }
};
