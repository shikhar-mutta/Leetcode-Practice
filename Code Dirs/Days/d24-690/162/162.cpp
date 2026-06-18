// Link: https://leetcode.com/problems/find-peak-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n), SC: O(1)
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) // fUse Slop to find maxima
                left = mid + 1;            // ascending slope → peak is to the right
            else
                right = mid; // descending slope → peak is here or to the left
        }
        return left;
    }
};
