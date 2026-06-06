// Link: https://leetcode.com/problems/special-array-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    bool isArraySpecial(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] % 2 == nums[i + 1] % 2)
                return false;
        }
        return true;
    }
};
