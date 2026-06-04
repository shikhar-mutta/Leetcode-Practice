// Link: https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Brute Force.
    // TC: O(N^2). SC: O(N^2)
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        // ans (maxLocal) of size (n - 2) x (n - 2)
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        // iterate over the grid and find the largest value of the 3 x 3 matrix
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                // to store the largest value of the 3 x 3 matrix
                int localMax = 0;
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        localMax = max(localMax, grid[k][l]);
                    }
                }
                // store the largest value in the ans matrix at the position (i, j)
                ans[i][j] = localMax;
            }
        }
        return ans;
    }
};
