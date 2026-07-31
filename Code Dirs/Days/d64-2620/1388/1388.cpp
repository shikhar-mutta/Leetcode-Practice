// Link: https://leetcode.com/problems/pizza-with-3n-slices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: DP
// We can solve this problem using dynamic programming. The idea is to use a 2D DP array where dp[i][j] represents the maximum sum of slices we can get by considering the first i slices and selecting j slices. Since we cannot select adjacent slices, we have two cases for each slice: either we include it in our selection or we don't. If we include it, we cannot include the previous slice, so we add the value of the current slice to the maximum sum we can get by considering the first i-2 slices and selecting j-1 slices. If we don't include it, we simply take the maximum sum we can get by considering the first i-1 slices and selecting j slices. Finally, since the pizza is circular, we need to consider two cases: one where we include the first slice and exclude the last slice, and another where we exclude the first slice and include the last slice. We return the maximum of these two cases.
class Solution
{
public:
    int maxSizeSlices(std::vector<int> &slices)
    {
        int m = slices.size();
        int n = m / 3;
        auto solveLinear = [&](int start, int end)
        {
            std::vector<int> a(n + 1, 0);
            std::vector<int> b(n + 1, 0);
            for (int i = start; i <= end; ++i)
            {
                int max_slices = std::min(n, (i - start + 2) / 2);
                for (int j = max_slices; j >= 1; --j)
                {
                    b[j] = std::max(a[j], b[j - 1] + slices[i]);
                }
                std::swap(a, b);
            }
            return a[n];
        };
        return std::max(solveLinear(0, m - 2), solveLinear(1, m - 1));
    }
};