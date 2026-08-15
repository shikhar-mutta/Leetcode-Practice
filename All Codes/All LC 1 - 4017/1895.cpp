// Link: https://leetcode.com/problems/largest-magic-square/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * min(m, n)) where m is the number of rows and n is the number of columns
// SC: O(m * n) where m is the number of rows and n is the number of columns
//  Approach: Prefix Sum
//    1. Create a prefix sum array for rows, columns, diagonals and anti-diagonals.
//    2. Iterate through all possible sizes of magic squares from min(m, n) to 2.
//    3. For each size, iterate through all possible top-left corners of the magic square and check if the sum of all rows, columns, diagonals and anti-diagonals are equal.
//    4. If a magic square is found, return the size of the magic square.
class Solution
{
public:
    int m, n;

    int largestMagicSquare(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> rowPref(m, vector<int>(n + 1, 0));
        vector<vector<int>> colPref(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> antiDiag(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowPref[i][j + 1] = rowPref[i][j] + grid[i][j];
                colPref[i + 1][j] = colPref[i][j] + grid[i][j];
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                antiDiag[i + 1][j] = antiDiag[i][j + 1] + grid[i][j];
            }
        }
        for (int k = min(m, n); k >= 2; k--)
        {
            if (isMagic(k, rowPref, colPref, diag, antiDiag))
                return k;
        }
        return 1;
    }

private:
    bool isMagic(int k, vector<vector<int>> &rowPref,
                 vector<vector<int>> &colPref, vector<vector<int>> &diag,
                 vector<vector<int>> &antiDiag)
    {
        for (int i = 0; i <= m - k; i++)
        {
            for (int j = 0; j <= n - k; j++)
            {
                int target = diag[i + k][j + k] - diag[i][j];
                int anti = antiDiag[i + k][j] - antiDiag[i][j + k];
                if (target != anti)
                    continue;
                bool ok = true;
                for (int t = 0; t < k && ok; t++)
                {
                    if (rowPref[i + t][j + k] - rowPref[i + t][j] != target)
                        ok = false;
                    if (colPref[i + k][j + t] - colPref[i][j + t] != target)
                        ok = false;
                }
                if (ok)
                    return true;
            }
        }
        return false;
    }
};