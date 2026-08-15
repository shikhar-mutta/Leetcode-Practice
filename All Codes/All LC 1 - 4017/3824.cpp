// Link: https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(maxVal)) SC: O(1)
//  Approach: nonPositive(nums,k) = sum of ceil(nums[i]/k). As k grows this
//  sum shrinks while k^2 grows, so feasibility is monotonic — binary
//  search for the smallest k where the sum fits within k^2.
class Solution
{
    bool feasible(vector<int> &nums, long long k)
    {
        long long ops = 0;
        for (int x : nums)
        {
            ops += (x + k - 1) / k;
            if (ops > k * k)
                return false;
        }
        return ops <= k * k;
    }

public:
    int minimumK(vector<int> &nums)
    {
        long long lo = 1, hi = 200000;
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(nums, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
