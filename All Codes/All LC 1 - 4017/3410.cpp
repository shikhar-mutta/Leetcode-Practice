// Link: https://leetcode.com/problems/maximize-subarray-sum-after-removing-all-occurrences-of-one-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: maintain the running sum of the subarray, and the minimum prefix sum seen so far. For each element, if it's negative, we also maintain the minimum prefix sum for subarrays that have removed that specific negative element. The answer is the maximum of the current sum minus the minimum prefix sum, which gives the maximum subarray sum ending at the current position. We also update the minimum prefix sums accordingly to account for the removal of negative elements.
class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums)
    {
        long long ans = LLONG_MIN;
        long long s = 0;
        long long non_del_min_s = 0;
        long long all_min = 0;
        unordered_map<int, long long> del_min_s;

        for (int x : nums)
        {
            s += x;
            ans = max(ans, s - all_min);
            if (x < 0)
            {
                if (del_min_s.find(x) == del_min_s.end())
                {
                    del_min_s[x] = non_del_min_s + x;
                }
                else
                {
                    del_min_s[x] = min(del_min_s[x], non_del_min_s) + x;
                }
                all_min = min(all_min, del_min_s[x]);
                non_del_min_s = min(non_del_min_s, s);
            }
        }
        return ans;
    }
};