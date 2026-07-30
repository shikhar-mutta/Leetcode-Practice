// Link: https://leetcode.com/problems/power-of-heroes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(1)
// Approach: sort ascending. Fixing nums[i] as the subset max, sum of mins over all subsets with
// that max = nums[i] + 2*run, where run tracks a rolling weighted sum of smaller elements
// (run_new = 2*run_old + nums[i]) — each earlier element either is excluded, included as
// non-min, or (implicitly accounted) as min once per position.
class Solution
{
public:
    int sumOfPower(vector<int> &nums)
    {
        const long long MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        long long ans = 0, run = 0;
        for (int x : nums)
        {
            long long sq = (long long)x * x % MOD;
            ans = (ans + sq * ((x + run) % MOD)) % MOD;
            run = (2 * run + x) % MOD;
        }
        return (int)ans;
    }
};
