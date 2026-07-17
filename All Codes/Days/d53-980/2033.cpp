// Link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m + (mx - mn) / x) where n is the number of rows, m is the number of columns, mx is the maximum value in the grid, and mn is the minimum value in the grid.
    // SC: O(mx - mn) where mx is the maximum value in the grid, and mn is the minimum value in the grid.
    // Approach:
    // 1. Count the frequency of each value in the grid and find the minimum and maximum values.
    // 2. Check if all values can be made equal by checking if the difference between each value and the minimum value is divisible by x. If not, return -1.
    // 3. Find the median value by accumulating the frequencies until reaching the middle of the total number of elements.
    // 4. Calculate the total number of operations needed to make all values equal to the median value by summing the absolute differences divided by x, multiplied by the frequency of each value.
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int n = grid.size(), m = grid[0].size();
        int N = n * m;
        int freq[10001] = {0};
        int mn = grid[0][0], mx = mn;

        for (const auto &row : grid)
        {
            for (int val : row)
            {
                if ((val - grid[0][0]) % x != 0)
                    return -1;
                freq[val]++;
                mn = min(mn, val);
                mx = max(mx, val);
            }
        }

        int target = (N + 1) / 2;
        int acc = 0, median = mn;

        for (int i = mn; i <= mx; i += x)
        {
            acc += freq[i];
            if (acc >= target)
            {
                median = i;
                break;
            }
        }

        int ops = 0;
        for (int i = mn; i <= mx; i += x)
            ops += abs(i - median) / x * freq[i];

        return ops;
    }
};