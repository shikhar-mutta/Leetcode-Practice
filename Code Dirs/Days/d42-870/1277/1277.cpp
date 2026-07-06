// Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*M)  SC: O(1)
// Approach: Tabulation
class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    int mini = INT_MAX;
                    if (i >= 1 && j >= 1)
                    {
                        mini = min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1]));
                    }
                    if (mini == INT_MAX)
                    {
                        mini = 0;
                    }
                    matrix[i][j] = 1 + mini;
                    count += matrix[i][j];
                }
            }
        }
        return count;
    }
};
