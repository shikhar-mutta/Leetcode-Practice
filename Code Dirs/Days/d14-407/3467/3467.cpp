// Link: https://leetcode.com/problems/transform-array-by-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    vector<int> transformArray(vector<int> &nums)
    {
        int n = nums.size(), cntEven = 0, i = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            if (nums[i] % 2 == 0)
                cntEven++;
        while (i < n)
        {
            if (cntEven > 0)
            {
                ans[i] = 0;
                cntEven--;
            }
            else
                ans[i] = 1;
            i++;
        }
        return ans;
    }
};
