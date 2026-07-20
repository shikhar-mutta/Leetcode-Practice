// Link: https://leetcode.com/problems/spiral-matrix-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the number of elements in the input array
    // SC: O(1)
    // Approach:
    //   1. We will use four pointers to keep track of the boundaries of the matrix.
    //   2. We will fill the matrix in a spiral order by moving the pointers inward after each pass.
    //   3. We will continue this process until we have filled the entire matrix.
    //   4. We will return the filled matrix.
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int val = 1;
        while (top <= bottom && left <= right)
        {
            for (int c = left; c <= right; c++)
                res[top][c] = val++;
            top++;
            for (int r = top; r <= bottom; r++)
                res[r][right] = val++;
            right--;
            if (top <= bottom)
            {
                for (int c = right; c >= left; c--)
                    res[bottom][c] = val++;
                bottom--;
            }
            if (left <= right)
            {
                for (int r = bottom; r >= top; r--)
                    res[r][left] = val++;
                left++;
            }
        }
        return res;
    }
};
