// Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ans = -1, minNum = nums[0], n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= minNum)
            {
                minNum = nums[i];
                continue;
            }
            else if (ans < nums[i] - minNum)
                ans = nums[i] - minNum;
        }
        return ans;
    }
};
