// Link: https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: within-array swaps are free, so only the multiset of values
//  in each array matters, not order. For the arrays to end up identical,
//  each value's combined total count across both arrays must split evenly
//  (else -1). A cross-swap moves one unit of some value from array1 to
//  array2 while simultaneously moving one unit of another value from
//  array2 to array1, so it fixes one surplus-in-1 value and one
//  deficit-in-1 value at once. The minimum ops therefore equals the total
//  surplus (sum of positive count1[v] - target[v]).

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
class Solution
{
    static constexpr int lim = 80000;
    inline static bool is[lim + 1];
    inline static int freq_diff[lim + 1];
    inline static int uniques[lim];

public:
    int minCost(vector<int> &nums1, vector<int> &nums2)
    {
        int uniques_cnt = 0;
        for (int num : nums1)
        {
            ++freq_diff[num];
            if (!is[num])
            {
                is[num] = true;
                uniques[uniques_cnt++] = num;
            }
        }
        for (int num : nums2)
        {
            --freq_diff[num];
            if (!is[num])
            {
                is[num] = true;
                uniques[uniques_cnt++] = num;
            }
        }
        int ans = 0;
        int i;
        for (i = 0; i < uniques_cnt; ++i)
        {
            int num = uniques[i];
            if (freq_diff[num] % 2)
                break;
            ans += abs(freq_diff[num]);
            is[num] = freq_diff[num] = 0;
        }
        if (i == uniques_cnt)
            return ans / 4;
        for (; i < uniques_cnt; ++i)
        {
            int num = uniques[i];
            is[num] = freq_diff[num] = 0;
        }
        return -1;
    }
};