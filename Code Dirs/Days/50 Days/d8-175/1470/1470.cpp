// Link: https://leetcode.com/problems/shuffle-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]); // i+n is the index of the second half of the array
        }
        return ans;
    }
};
