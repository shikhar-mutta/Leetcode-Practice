// Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: any grid works as long as exactly one path exists. Keep the
// entire top row free and only the last column free below it — this
// forces every path to travel the full row then drop straight down,
// giving exactly one valid path.
class Solution
{
public:
    vector<string> createGrid(int m, int n)
    {
        vector<string> grid(m, string(n, '#'));
        for (int j = 0; j < n; j++)
            grid[0][j] = '.';
        for (int i = 0; i < m; i++)
            grid[i][n - 1] = '.';
        return grid;
    }
};
