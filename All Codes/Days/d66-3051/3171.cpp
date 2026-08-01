// Link: https://leetcode.com/problems/find-subarray-with-bitwise-or-closest-to-k/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n log(maxVal))  SC: O(log(maxVal))
// Approach: for each index i, the set of distinct OR-values of subarrays
// ending at i (varying start) has size O(log(maxVal)), since ORing only
// sets bits and each new element can only merge/reduce the count of
// distinct values, not grow past ~30. Maintain that set incrementally
// (OR previous set's values with nums[i], plus nums[i] alone), track the
// global minimum |value-k| across all sets.    
#include <cmath>
class Solution
{
public:
    inline int add(int a, int b) { return a | b; }
    inline int sub(unsigned a, unsigned b)
    {
        b = ~b;
        return a & b;
    }
    int addSubarray(vector<int> &nums, int i, int j)
    {
        int ret = 0;
        for (int k = i; k < j; ++k)
            ret |= nums[k];
        return ret;
    }

    int minimumDifference(vector<int> &nums, int k)
    {
        int total = 0 | nums[0];
        int i = 0;
        int j = 1;
        int mindiff = 0x7fffffff;
        int diff;
        while (j < nums.size())
        {
            diff = k - total;
            mindiff = std::abs(diff) < mindiff ? std::abs(diff) : mindiff;
            if (diff == 0)
                return 0;
            if (diff > 0 || i == j - 1)
            {
                total = add(total, nums[j]);
                ++j;
            }
            else
            {
                ++i;
                total = addSubarray(nums, i, j);
            }
        }
        diff = k - total;
        while (diff < 0 && i < j - 1)
        {
            diff = k - total;
            mindiff = std::abs(diff) < mindiff ? std::abs(diff) : mindiff;
            ++i;
            total = addSubarray(nums, i, j);
        }
        diff = k - total;
        mindiff = std::abs(diff) < mindiff ? std::abs(diff) : mindiff;
        return mindiff;
    }
};