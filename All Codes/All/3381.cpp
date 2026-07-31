// Link: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(k)
// Approach: prefix sums grouped by index mod k. For a subarray [i+1, j]
// with length a multiple of k, i and j have the same residue mod k, so
// its sum is prefix[j] - prefix[i]. Track the minimum prefix seen so far
// per residue class and maximize prefix[j] - minPrefix[j%k] as j advances.
class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        vector<long long> mp(k, LLONG_MAX);
        long long prefix = 0;
        long long ans = LLONG_MIN;
        mp[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix += (long long)nums[i];

            long long remainder = (i + 1) % k;
            if (mp[remainder] != LLONG_MAX)
            {
                ans = max(ans, prefix - mp[remainder]);
            }

            mp[remainder] = min(prefix, mp[remainder]);
        }
        return ans;
    }
};