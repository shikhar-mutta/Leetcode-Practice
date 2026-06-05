// Link: https://leetcode.com/problems/neither-minimum-nor-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1). SC: O(1)
    int findNonMinOrMax(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return -1;
        // Sort the first three elements to find the minimum and maximum
        sort(nums.begin(), nums.begin() + 3);
        return nums[1];
    }
};
