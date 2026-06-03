// Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == target)
                ans.push_back(i); // Collect all indices of target
            else if (nums[i] > target)
                break; // Early stopping
        return ans;
    }
};
