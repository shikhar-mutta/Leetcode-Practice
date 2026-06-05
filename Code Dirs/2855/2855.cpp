// Link: https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minimumRightShifts(vector<int> &nums)
    {
        int n = nums.size(), dropIdx = -1;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] > nums[i + 1])
            {
                if (dropIdx != -1)
                    return -1;
                dropIdx = i;
            }
        if (dropIdx == -1)
            return 0;
        if (nums[n - 1] > nums[0])
            return -1;
        return n - dropIdx - 1;
    }
};
