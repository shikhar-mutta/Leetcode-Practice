// Link: https://leetcode.com/problems/find-the-middle-index-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size(), left = 0;
        for (int i = 0; i < n; i++)
        {
            sum -= nums[i];
            if (left == sum)
                return i;
            left += nums[i];
        }
        return -1;
    }
};
