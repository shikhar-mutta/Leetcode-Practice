// Link: https://leetcode.com/problems/partition-array-into-two-equal-product-subsets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n) SC: O(n)
//  Approach: a split into two subsets both with product == target is only
//  possible if the total product equals target^2 (checked upfront). Given
//  that, n is small, so backtrack over include/exclude for each element,
//  tracking the running product of the "included" subset (pruning once it
//  exceeds target) until some non-empty proper subset hits target exactly
//  — its complement then automatically also equals target.
class Solution
{
public:
    bool solve(int idx, vector<int> &nums,
               long long p1, long long p2,
               int cnt1, int cnt2,
               long long target)
    {
        if (p1 > target || p2 > target)
            return false;

        if (target % p1 != 0 || target % p2 != 0)
            return false;

        if (idx == nums.size())
        {
            return (cnt1 > 0 && cnt2 > 0 &&
                    p1 == target && p2 == target);
        }

        // Put current element in subset 1
        if (solve(idx + 1, nums,
                  p1 * nums[idx], p2,
                  cnt1 + 1, cnt2,
                  target))
            return true;

        // Put current element in subset 2
        if (solve(idx + 1, nums,
                  p1, p2 * nums[idx],
                  cnt1, cnt2 + 1,
                  target))
            return true;

        return false;
    }

    bool checkEqualPartitions(vector<int> &nums, long long target)
    {

        return solve(0, nums, 1LL, 1LL, 0, 0, target);
    }
};