// Link: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
//  Approach:
//    1. We will count the number of trailing zeros in each row and store it in the zeros array.
//    2. We will iterate through the zeros array and for each row, we will check if the number of trailing zeros is greater than or equal to the required number of trailing zeros for that row.
//    3. If it is, we will continue to the next row. If it is not, we will find the next row that has enough trailing zeros and swap it with the current row. We will increment the result by the number of swaps made.
//    4. If we cannot find a row with enough trailing zeros, we will return -1
class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> zeros(n, 0);
        for (int i = 0; i < n; ++i)
        {
            int c = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; --j)
                ++c;
            zeros[i] = c;
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int need = n - 1 - i, j = i;
            while (j < n && zeros[j] < need)
                ++j;
            if (j == n)
                return -1;
            while (j > i)
            {
                swap(zeros[j], zeros[j - 1]);
                --j;
                ++res;
            }
        }
        return res;
    }
};