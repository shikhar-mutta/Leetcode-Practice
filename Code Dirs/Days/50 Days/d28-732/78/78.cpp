// Link: https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * 2^n). SC: O(n * 2^n).
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        int pow = 1 << n;
        for (int i = 0; i < pow; i++)
        {
            vector<int> subset;
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    subset.push_back(nums[j]);
            res.push_back(subset);
        }
        return res;
    }
};
