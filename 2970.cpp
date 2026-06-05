// Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();

        // pre[i] = true if nums[0..i] is strictly increasing
        // suf[i] = true if nums[i..n-1] is strictly increasing
        vector<bool> pre(n, true), suf(n, true);
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] && nums[i] > nums[i - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] && nums[i] < nums[i + 1];

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                bool prefixOk = (i == 0) || pre[i - 1];
                bool suffixOk = (j == n - 1) || suf[j + 1];
                bool joinOk   = (i == 0) || (j == n - 1) || nums[i - 1] < nums[j + 1];
                if (prefixOk && suffixOk && joinOk) count++;
            }
        }
        return count;
    }
};
