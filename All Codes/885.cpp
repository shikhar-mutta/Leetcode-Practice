// Link: https://leetcode.com/problems/spiral-matrix-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) SC: O(m*n)
    // SC: O(m*n) because we are storing all the coordinates in the result vector.
    // Approach:
    //  1. We start from the given starting point (y, x) and move in a spiral pattern.
    //  2. We keep track of the current direction (dx, dy) and the number of steps to take in that direction (num).
    //  3. We also keep track of how many times we have changed direction (flog) and how many steps we have taken in the current direction (k).
    //  4. We continue moving in the spiral pattern until we have visited all the cells in the matrix.
    //  5. We check if the current position (y, x) is within the bounds of the matrix (0 <= y < m and 0 <= x < n) before adding it to the result vector.
    //  6. We return the result vector containing the coordinates of the cells in the order they were visited.
    vector<vector<int>> spiralMatrixIII(int m, int n, int y, int x)
    {
        int dx = 1, dy = 0;
        int flog = 0;
        int num = 1;
        vector<vector<int>> res;
        int max1 = max(y, m - y) * 2;
        int min1 = max(x, n - x) * 2;
        int k = 0;
        while (res.size() < m * n)
        {
            if (y < m && 0 <= y && x < n && 0 <= x)
                res.push_back({y, x});
            k++;
            y += dy;
            x += dx;
            if (k == num)
            {
                k = 0;
                flog++;
                if (flog == 2)
                {

                    flog = 0;
                    num++;
                }
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
        }
        return res;
    }
};