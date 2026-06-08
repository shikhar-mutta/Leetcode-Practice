// Link: https://leetcode.com/problems/smallest-stable-index-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    int firstStableIndex(vector<int> &nums, int k)
    {

        int n = nums.size();

        vector<int> leftmax(n);
        vector<int> rightmin(n);

        leftmax[0] = nums[0];          // prefix max array
        rightmin[n - 1] = nums[n - 1]; // suffix min array

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > leftmax[i - 1])
                leftmax[i] = nums[i];
            else
                leftmax[i] = leftmax[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < rightmin[i + 1])
                rightmin[i] = nums[i];
            else
                rightmin[i] = rightmin[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (leftmax[i] - rightmin[i] <= k)
                return i;
        }

        return -1;
    }
};
