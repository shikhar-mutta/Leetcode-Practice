// Link: https://leetcode.com/problems/find-a-good-subset-of-the-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n + m^2) where m is the number of rows and n is the number of columns, SC: O(m) where m is the number of rows
//  Approach: We can use a bitmasking approach to find a good subset of the binary matrix. We will iterate through each row of the matrix and create a bitmask for each row, where each bit in the mask represents whether the corresponding column has a 1 or not. We will store the first row index for each unique bitmask in a map. If we encounter a row with a bitmask of all zeros, we can immediately return that row index as a good subset. After processing all rows, we will check all pairs of unique bitmasks to see if any two masks have no overlapping 1s (i.e., their bitwise AND is zero). If we find such a pair, we return the indices of those two rows. If no good subset is found, we return an empty vector.
class Solution
{
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Map to store the first row index for each unique bitmask
        unordered_map<int, int> maskToIndex;

        for (int i = 0; i < m; ++i)
        {
            int mask = 0;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    mask |= (1 << j);
                }
            }

            // Check if current row is all zeros
            if (mask == 0)
                return {i};

            maskToIndex[mask] = i;
        }

        // Check all pairs of masks
        for (auto const &[mask1, i1] : maskToIndex)
        {
            for (auto const &[mask2, i2] : maskToIndex)
            {
                if ((mask1 & mask2) == 0)
                {
                    // Return indices in ascending order
                    if (i1 < i2)
                        return {i1, i2};
                    else
                        return {i2, i1};
                }
            }
        }

        return {};
    }
};