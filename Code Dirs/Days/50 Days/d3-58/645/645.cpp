// Link: https://leetcode.com/problems/set-mismatch/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size(), repeated, missing, idx;
        for (auto it : nums)
        {
            idx = abs(it) - 1;
            if (nums[idx] > 0)
                nums[idx] = -nums[idx];
            else
                repeated = idx + 1;
        }
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                missing = i + 1;

        return {repeated, missing};
    }
};
