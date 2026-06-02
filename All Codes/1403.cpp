// Link: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int remaining = accumulate(nums.begin(), nums.end(), 0);
        int selected = 0;
        vector<int> ans;

        // greedily pick largest elements until their sum exceeds the rest
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            selected += nums[i];
            remaining -= nums[i];
            ans.push_back(nums[i]);
            if (selected > remaining)
                return ans;
        }
        return ans;
    }
};
