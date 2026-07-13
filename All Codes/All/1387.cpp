// Link: https://leetcode.com/problems/sort-integers-by-the-power-value/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the number of integers in the range [lo, hi].
// SC: O(n) for storing the power values of integers in the range [lo, hi].
// Approach:
// 1. Precompute the power values for all integers in the range [2, 1000] using memoization.
// 2. Store the integers in a vector and sort them based on their power values using nth_element to find the k-th smallest power value.
// 3. Return the k-th smallest integer in the range [lo, hi] based on its power value.
int comp[1001] = {0, 0, 0};
class Solution
{
    int compute(int i)
    {
        return i < 2 ? 0 : 1 + (i % 2 ? compute(i * 3 + 1) : compute(i / 2));
    }

public:
    int getKth(int lo, int hi, int k)
    {
        if (comp[2] == 0)
            for (auto i = 2; i <= 1000; i++)
                comp[i] = compute(i);
        vector<int> sorted(hi - lo + 1);
        iota(begin(sorted), end(sorted), lo);
        nth_element(begin(sorted), begin(sorted) + k - 1, end(sorted), [](int i, int j)
                    { return comp[i] == comp[j] ? i < j : comp[i] < comp[j]; });
        return sorted[k - 1];
    }
};