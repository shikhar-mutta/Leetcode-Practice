// Link: https://leetcode.com/problems/count-servers-that-communicate/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m * n) where m is the number of rows and n is the number of columns in the grid
    // SC: O(m + n) for the row and column count arrays
    //   Approach:
    //    1. Create two arrays, row and col, to count the number of servers in each row and column respectively.
    //    2. Iterate through the grid to populate the row and col arrays with the count of servers (cells with value 1).
    //    3. Iterate through the grid again, and for each server (cell with value 1), check if it can communicate with any other server by checking if the count in its corresponding row or column is greater than 1.
    //    4. If it can communicate, increment the result counter.
    //    5. Return the result counter which represents the number of servers that can communicate with at least one other server.
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