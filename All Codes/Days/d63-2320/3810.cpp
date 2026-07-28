// Link: https://leetcode.com/problems/minimum-operations-to-reach-target-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: for each position where nums[i] != target[i], if nums[i] hasn't been
//  processed yet, increment the operation count and mark it as processed.
class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &target)
    {
        int n = nums.size();
        vector<bool> st(100001);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != target[i] && !(st[nums[i]]))
            {
                st[nums[i]] = true;
                ans++;
            }
        }
        return ans;
    }
};