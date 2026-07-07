// Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        // Rightmost index smaller than the max of everything before it,
        // and leftmost index greater than the min of everything after it.
        int end = -1, start = 0;
        int mx = nums[0], mn = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < mx)
                end = i;
            else
                mx = nums[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > mn)
                start = i;
            else
                mn = nums[i];
        }
        return end == -1 ? 0 : end - start + 1;
    }
};
