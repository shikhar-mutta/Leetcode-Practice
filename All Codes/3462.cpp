// Link: https://leetcode.com/problems/maximum-sum-with-at-most-k-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m + n * log(n) + k * log(k)) where n is the number of rows, m is the number of columns, and k is the number of elements to choose.
    // SC: O(n * m) where n is the number of rows and m is the number of columns.
    // Approach:
    // 1. For each row, sort the elements in descending order and choose the first 'limits[i]' elements.
    // 2. Store all the chosen elements in a single vector and sort it in descending order.
    // 3. Choose the first 'k' elements from the sorted vector and return their sum.
    // Note: We use nth_element to partially sort the elements, which is more efficient than fully sorting them.
    long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k)
    {
        const int n = grid.size(), m = grid[0].size();
        long long ans = 0;
        vector<int> choose1;

        for (int i = 0; i < n; i++)
        {
            auto it = grid[i].begin() + limits[i];
            nth_element(grid[i].begin(), it, grid[i].end(), greater<int>());
            choose1.insert(choose1.end(), grid[i].begin(), it);
        }

        if (k > choose1.size())
            k = choose1.size(); // Prevent out-of-bounds
        nth_element(choose1.begin(), choose1.begin() + k, choose1.end(), greater<int>());
        return accumulate(choose1.begin(), choose1.begin() + k, 0ll);
    }
};
