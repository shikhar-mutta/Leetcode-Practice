// Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int mx = 1, n = nums.size(), cnt = 1;
        if (n == 0)
            return 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                mx = max(mx, ++cnt);
            else
                cnt = 1;
        }
        return mx;
    }
};
