// Link: https://leetcode.com/problems/maximum-rows-covered-by-columns/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * m), where n is the number of columns and m is the number of rows in the input matrix.
// SC: O(m), where m is the number of rows in the input matrix.
//  Approach:
//   1. We initialize two variables m and n to store the number of rows and  columns in the input matrix, respectively.
//   2. We create a vector rowMask of size m, initialized to 0, which will be used to store the bitmask representation of each row in the matrix. Each bit in the bitmask corresponds to a column in the matrix, and a bit is set to 1 if the corresponding column in that row has a 1.
//   3. We iterate through each row i and each column j in the input matrix. If the value at matrix[i][j] is 1, we set the j-th bit in rowMask[i] to 1 using the bitwise OR operation (rowMask[i] |= (1 << j)).
//   4. We initialize a variable best to 0, which will be used to keep track of the maximum number of rows that can be covered by selecting numSelect columns.
//   5. We iterate through all possible selections of columns using a bitmask sel, which ranges from 0 to (1 << n) - 1. For each selection, we check if the number of selected columns (the number of set bits in sel) is equal to numSelect using the __builtin_popcount function. If not, we skip to the next selection.
//   6. For each valid selection of columns, we initialize a variable covered to 0, which will be used to count the number of rows that can be covered by the selected columns. We iterate through each row i and check if the bitmask representation of that row (rowMask[i]) is a subset of the selected columns (sel) using the bitwise AND operation (rowMask[i] & sel) == rowMask[i]. If it is, we increment the covered variable.
//   7. We update the best variable to be the maximum of its current value and the covered variable, which represents the maximum number of rows that can be covered by the selected columns so far.
//   8. After iterating through all possible selections of columns, we return the value of best, which represents the maximum number of rows that can be covered by selecting numSelect columns from the input matrix.
class Solution
{
public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowMask(m, 0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j])
                    rowMask[i] |= (1 << j);

        int best = 0;
        for (int sel = 0; sel < (1 << n); ++sel)
        {
            if (__builtin_popcount(sel) != numSelect)
                continue;
            int covered = 0;
            for (int i = 0; i < m; ++i)
                if ((rowMask[i] & sel) == rowMask[i])
                    ++covered;
            best = max(best, covered);
        }
        return best;
    }
};
