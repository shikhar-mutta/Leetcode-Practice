// Link: https://leetcode.com/problems/delete-greatest-value-in-each-row/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: sort Each row then delete right to left.
    // TC: O(m*n*log(n)) where m is num of rows, n is num of columns. SC: O(1)
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int ans = 0, cols = grid[0].size(), rows = grid.size();
        for (auto &row : grid)
            sort(row.begin(), row.end());
        for (int i = 0; i < cols; i++)
        {
            int mx = 0;
            for (int j = 0; j < rows; j++)
                mx = max(mx, grid[j][i]);
            ans += mx;
        }
        return ans;
    }
};
