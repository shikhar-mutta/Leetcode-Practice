// Link: https://leetcode.com/problems/single-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};