// Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Fill the 2D array row by row. TC: O(m*n), SC: O(m*n)
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int x = original.size();
        vector<vector<int>> ans(m, vector<int>(n));
        if (x != m * n)
            return {}; // if not possible to convert, return empty 2D array
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = original[i * n + j]; // fill row by row
        return ans;
    }

    // Approach 2: Fill the 2D array using a single loop. TC: O(m*n), SC: O(m*n)
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int x = original.size();
        vector<vector<int>> ans(m, vector<int>(n));
        if (x != m * n)
            return {}; // if not possible to convert, return empty 2D array
        for (int i = 0; i < x; i++)
            ans[i / n][i % n] = original[i]; // fill using a single loop
        return ans;
    }
};
