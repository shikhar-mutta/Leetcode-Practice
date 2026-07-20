// Link: https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach:
//  1. Check if the array is sorted in increasing order or decreasing order.
//  2. If the array is sorted in increasing order, return the minimum of index of 0 and n - index of 0 + 2.
//  3. If the array is sorted in decreasing order, return the minimum of (index of 0 + 1) % n + 1 and n - index of 0.
//  4. If the array is not sorted in either increasing or decreasing order, return -1.
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        bool inc = true;
        int index0 = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[(i + 1) % n] != (nums[i] + 1) % n)
            {
                inc = false;
                break;
            }
            if (nums[i] == 0)
                index0 = i;
        }

        bool dec = true;
        int indexn = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[(i + 1) % n] != (nums[i] + n - 1) % n)
            {
                dec = false;
                break;
            }
            if (nums[i] == 0)
                indexn = i;
        }
        if (!inc && !dec)
            return -1;

        if (inc)
        {
            return min(index0, n - index0 + 2);
        }
        else
        {
            return min((indexn + 1) % n + 1, n - indexn);
        }
    }
};