// Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
        }
        return ans;
    }
};
