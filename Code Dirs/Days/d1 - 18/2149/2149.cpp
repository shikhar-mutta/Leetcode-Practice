// Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int pos = 0, neg = 1, i = 0, n = nums.size();
        vector<int> ans(n);
        while (i < n)
        {
            if (nums[i] < 0)
            {
                ans[neg] = nums[i];
                neg += 2;
            }
            else
            {
                ans[pos] = nums[i];
                pos += 2;
            }
            i++;
        }
        return ans;
    }
};