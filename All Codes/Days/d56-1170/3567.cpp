// Link: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m * n * k^2 * log(k^2)), SC: O(k^2)
    // Approach:
    // 1. Iterate through the grid and for each k x k submatrix, store the values in a temporary array.
    // 2. Sort the temporary array and remove duplicates using std::unique.
    // 3. Calculate the minimum absolute difference between consecutive elements in the sorted array.
    // 4. Store the minimum absolute difference in the top-left cell of the submatrix.
    // 5. Resize the grid to only include the top-left cells of all k x k submatrices.
    // 6. Return the modified grid.
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        thread_local int vals[901] = {0};
        const int m = grid.size(), n = grid[0].size();
        for (int row = 0; row < m - k + 1; ++row)
        {
            for (int col = 0; col < n - k + 1; ++col)
            {
                int pos = 0;
                for (int i = 0; i < k; ++i)
                {
                    for (int j = 0; j < k; ++j)
                    {
                        vals[pos] = grid[row + i][col + j];
                        ++pos;
                    }
                }
                std::sort(vals, vals + pos);
                auto ptr = std::unique(vals, vals + pos);
                const int bound = ptr - vals;
                int min_val = 200000;
                for (int i = 1; i < bound; ++i)
                {
                    min_val = std::min(min_val, vals[i] - vals[i - 1]);
                }
                grid[row][col] = (bound <= 1) ? 0 : min_val;
            }
        }
        grid.resize(m - k + 1);
        for (auto &row : grid)
        {
            row.resize(n - k + 1);
        }
        return grid;
    }
};