// Link: https://leetcode.com/problems/flip-square-submatrix-vertically/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(k^2), SC: O(1)
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int n = grid.size();
        for (int i = x; i < x + k / 2; i++)
            for (int j = y; j < y + k; j++)
                swap(grid[i][j], grid[x + k - 1 - (i - x)][j]);

        return grid;
    }
};
