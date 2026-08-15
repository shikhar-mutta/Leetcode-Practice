// Link: https://leetcode.com/problems/limit-occurrences-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    vector<int> limitOccurrences(vector<int> &nums, int k)
    {
        int n = nums.size(), i = 0, count = 1, prev = nums[0];
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int j = 1; j < n; j++)
        {
            if (nums[j] == prev)
            {
                count++;
            }
            else
            {
                count = 1;
                prev = nums[j];
            }

            if (count <= k)
            {
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};
