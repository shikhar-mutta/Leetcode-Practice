// Link: https://leetcode.com/problems/count-submatrices-with-all-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n*n), SC: O(m*n)
    // Approach:
    // 1. Calculate the height of 1's for each cell in the matrix.
    // 2. For each cell, iterate leftwards to count the number of submatrices
    //    that can be formed with the current cell as the bottom-right corner.
    // 3. The minimum height encountered during the leftward iteration determines the
    //    number of valid submatrices that can be formed.
    // 4. Accumulate the counts to get the total number of submatrices with all 1's.
    // 5. Return the total count.
    int numSubmat(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> height(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (mat[i][j] == 1)
                {
                    height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
                }
                else
                {
                    height[i][j] = 0;
                }
            }
        }

        int total = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int minH = INT_MAX;
                for (int k = j; k >= 0; k--)
                {
                    minH = min(minH, height[i][k]);
                    if (minH == 0)
                        break;
                    total += minH;
                }
            }
        }
        return total;
    }
};