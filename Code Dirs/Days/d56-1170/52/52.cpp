// Link: https://leetcode.com/problems/n-queens-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n!) where n is the input number
    // SC: O(n) for the recursion stack and the boolean vectors
    // Approach:
    //    1. Use backtracking to explore all possible placements of queens on the board
    //    2. Use three boolean vectors to keep track of the columns and diagonals that are already occupied by queens
    //    3. For each row, iterate through all columns and check if placing a queen in that column is valid (i.e., the column and diagonals are not occupied)
    //    4. If valid, mark the column and diagonals as occupied and recursively call the backtracking function for the next row
    //    5. If all queens are placed (i.e., we reach the last row), increment the count of valid solutions
    //    6. Backtrack by unmarking the column and diagonals and continue exploring other columns in the current row
    //    7. Return the total count of valid solutions after exploring all possibilities
    int totalNQueens(int n)
    {
        vector<bool> cols(n, false), diag1(2 * n, false), diag2(2 * n, false);
        int count = 0;
        function<void(int)> backtrack = [&](int row)
        {
            if (row == n)
            {
                count++;
                return;
            }
            for (int c = 0; c < n; c++)
            {
                int d1 = row + c, d2 = row - c + n;
                if (cols[c] || diag1[d1] || diag2[d2])
                    continue;
                cols[c] = diag1[d1] = diag2[d2] = true;
                backtrack(row + 1);
                cols[c] = diag1[d1] = diag2[d2] = false;
            }
        };
        backtrack(0);
        return count;
    }
};
