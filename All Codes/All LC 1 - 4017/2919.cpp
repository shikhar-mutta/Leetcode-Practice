// Link: https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) – single pass through nums
// SC: O(1) – only 3 DP variables (dp1, dp2, dp3)
// Approach: DP – an array is "beautiful" if every contiguous subarray of
// length >= 3 has max element >= k. So at least one of every 3 consecutive
// elements must be >= k. dp1/dp2/dp3 track the min cost when the element
// 3/2/1 positions back was the chosen "satisfying" element. For each a,
// cost to make a the satisfying element is max(k-a, 0); transition picks
// the cheapest of the three prior states. Answer is min of final dp1/dp2/dp3.
class Solution
{
public:
    long long minIncrementOperations(vector<int> &nums, int k)
    {
        long long dp1 = 0, dp2 = 0, dp3 = 0, dp;
        for (const int &a : nums)
        {
            dp = min(dp1, min(dp2, dp3)) + max(k - a, 0);
            dp1 = dp2;
            dp2 = dp3;
            dp3 = dp;
        }
        return min(dp1, min(dp2, dp3));
    }
};