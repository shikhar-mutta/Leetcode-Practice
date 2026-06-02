// Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            // find column index of row minimum
            int minCol = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] < matrix[i][minCol])
                    minCol = j;

            // check if row-min is also the column maximum
            int val = matrix[i][minCol];
            bool isColMax = true;
            for (int k = 0; k < rows; k++)
                if (matrix[k][minCol] > val) { isColMax = false; break; }

            if (isColMax)
                ans.push_back(val);
        }

        return ans;
    }
};
