// Link: https://leetcode.com/problems/minimum-operations-to-equalize-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minOperations(vector<int> &nums)
    {
        int var = nums[0], n = nums.size();
        for (int i = 1; i < n; i++)
            if (nums[i] != var)
                return 1;
        return 0;
    }
};
