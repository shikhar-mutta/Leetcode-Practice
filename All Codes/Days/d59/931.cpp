// Link: https://leetcode.com/problems/minimum-falling-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), where n is the number of rows in the matrix.
    // SC: O(1), as we are modifying the input matrix in place.
    // Approach:
    // 1. We will iterate through the matrix starting from the second row.
    // 2. For each cell in the current row, we will find the minimum value from the three possible cells in the previous row (the cell directly above, the cell to the left, and the cell to the right).
    // 3. We will add this minimum value to the current cell.
    // 4. After processing all rows, the minimum value in the last row will be the minimum falling path sum.
    // 5. We will return this minimum value.
    // 6. This approach ensures that we are considering all possible falling paths and accumulating the minimum sum as we progress through the matrix.
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int r = 1; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int best = matrix[r - 1][c];
                if (c > 0)
                    best = min(best, matrix[r - 1][c - 1]);
                if (c < n - 1)
                    best = min(best, matrix[r - 1][c + 1]);
                matrix[r][c] += best;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
