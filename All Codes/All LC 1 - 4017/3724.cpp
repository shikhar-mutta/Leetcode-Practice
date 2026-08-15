// Link: https://leetcode.com/problems/minimum-operations-to-transform-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: since append only adds to the end and never reorders, the
//  final array is exactly nums1's n elements (adjusted) followed by one
//  appended duplicate. Base cost = sum |nums1[j]-nums2[j]| for the first
//  n positions (fixed regardless of choice), plus 1 for the append. The
//  duplicated index i can be appended at any value along its own
//  adjustment path from nums1[i] to nums2[i] "for free" (that path's
//  cost is already counted in the base sum), so choosing the append
//  value as close as possible to nums2[n] costs extra only if nums2[n]
//  falls outside [min(nums1[i],nums2[i]), max(nums1[i],nums2[i])] — pick
//  the index i minimizing that extra distance.
class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2)
    {

        long long op = 0;
        int n = nums2.size();
        int last = nums2[n - 1];
        bool flag = false;

        int la = INT_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            op += (long long)abs(nums1[i] - nums2[i]);
            if ((last >= nums1[i] && last <= nums2[i]) || (last >= nums2[i] && last <= nums1[i]))
            {
                flag = true;
            }
        }

        if (flag)
            return ++op;

        for (int i = 0; i < n - 1; i++)
        {
            la = min({abs(nums1[i] - last), abs(nums2[i] - last), la});
        }

        return la + op + 1;
    }
};