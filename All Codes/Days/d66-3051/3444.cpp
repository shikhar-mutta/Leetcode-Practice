// Link: https://leetcode.com/problems/minimum-increments-for-target-multiples-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n * 2^m)  SC: O(2^m)
// Approach: For each number in nums, we can either use it to cover some subset of target or not. We can use bitmasking to represent the subsets of target that we have covered so far. We can use dynamic programming to keep track of the minimum number of increments needed to cover all subsets of target. For each number in nums, we can iterate through all the subsets of target that we have covered so far and try to cover new subsets of target using the current number. We can use the least common multiple (LCM) of the target numbers to determine how many increments are needed to make the current number a multiple of the LCM of the target numbers in the new subset.
class Solution
{
public:
    int minimumIncrements(vector<int> &nums, vector<int> &target)
    {
        static const auto INF = numeric_limits<int64_t>::max();

        const int n = size(nums);
        const int m = size(target);
        vector<int64_t> lcms(1 << m);
        for (int mask = 0; mask < (1 << m); ++mask)
        {
            int64_t l = 1;
            for (int i = 0; i < m; i++)
            {
                if (mask & (1 << i))
                {
                    l = lcm(l, target[i]);
                }
            }
            lcms[mask] = l;
        }
        vector<int64_t> dp(1 << m, INF);
        dp[0] = 0;
        for (const auto &x : nums)
        {
            for (int mask = (1 << m) - 1; mask >= 0; --mask)
            {
                if (dp[mask] == INF)
                {
                    continue;
                }
                const int new_mask = ((1 << m) - 1) - mask;
                for (int submask = new_mask; submask;
                     submask = (submask - 1) & new_mask)
                {
                    dp[mask | submask] =
                        min(dp[mask | submask],
                            dp[mask] + (x % lcms[submask]
                                            ? lcms[submask] - x % lcms[submask]
                                            : 0));
                }
            }
        }
        return dp[(1 << m) - 1];
    }
};
