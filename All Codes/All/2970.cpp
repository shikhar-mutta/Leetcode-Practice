// Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) in worst case, SC: O(1)
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();

        int l = 1; // Count the length of the longest increasing prefix
        for (int i = 0; i < n - 1; i++)
            if (nums[i] < nums[i + 1])
                l++;
            else
                break;

        int r = 1; // Count the length of the longest increasing suffix
        for (int i = n - 2; i >= 0; i--)
            if (nums[i + 1] > nums[i])
                r++;
            else
                break;

        if (l == n) // Array is strictly increasing, so all subarrays are incremovable
            return n * (n + 1) / 2;

        int ans = 0;
        for (int i = 0; i < l; i++)
        {
            for (int j = n - 1; j > n - 1 - r; j--)
            {
                if (nums[j] > nums[i])
                    ans++; // Can we form bridge by removing the subarray between i and j?
                else
                    break;
            }
        }
        return ans + l + r + 1;
    }
};