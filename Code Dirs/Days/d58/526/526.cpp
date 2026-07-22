// Link: https://leetcode.com/problems/beautiful-arrangement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n)
// SC: O(2^n)
// Approach:
//  1. Use bitmasking to represent the numbers that have been used in the arrangement.
//  2. Use dynamic programming to store the number of arrangements for each bitmask.
//  3. Use recursion to generate all possible arrangements and count the valid ones.
//  4. The base case is when all numbers have been used, which means we have found a valid arrangement.
class Solution
{
public:
    int countArrangement(int n)
    {
        this->n = n;
        if (n <= 0)
        {
            return 0;
        }

        int mask = 0;
        dp.resize(1 << n, -1);
        return GetCnt(mask, n);
    }

private:
    std::vector<int> dp;
    int n;
    int GetCnt(int mask, int i)
    {
        if (i == 1)
        {
            return 1;
        }

        if (dp[mask] != -1)
        {
            return dp[mask];
        }

        int res = 0;
        for (auto j = n; j >= 1; j--)
        {
            if (
                ((mask & (1 << (j - 1))) == 0) &&
                ((0 == i % j) || (0 == j % i)))
            {
                int new_mask = mask | (1 << (j - 1));
                res += GetCnt(new_mask, i - 1);
            }
        }
        dp[mask] = res;
        return res;
    }
};