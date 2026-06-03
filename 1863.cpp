// Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Bitmask enumeration — O(n * 2^n)
class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        // Iterate over all subsets using bitmasking
        for (int mask = 1; mask < (1 << n); mask++)
        {
            int xo = 0;
            // Calculate XOR for the current subset
            for (int i = 0; i < n; i++)
            {
                // If the i-th bit is set in the mask, include nums[i] in the XOR calculation
                if (mask & (1 << i))
                    xo ^= nums[i];
            }
            sum += xo;
        }
        return sum;
    }
};

// Approach 2: Math — O(n)
// Each bit present in any element appears in exactly 2^(n-1) subsets,
// so answer = (OR of all elements) * 2^(n-1)
class Solution2
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int orAll = 0;
        // Compute the OR of all elements in the array
        for (int x : nums)
            orAll |= x;
        // Each bit in orAll contributes to the XOR sum of 2^(n-1) subsets, since it will be included in exactly half of the subsets.
        return orAll * (1 << (nums.size() - 1));
    }
};
