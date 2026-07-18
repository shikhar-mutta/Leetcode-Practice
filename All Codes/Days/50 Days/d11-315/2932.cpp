// Link: https://leetcode.com/problems/maximum-strong-pair-xor-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Sort + Two Pointers
    // TC: O(n log n) due to sorting, SC: O(1)
    int maximumStrongPairXor(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // sort
        int n = nums.size();
        int maxXor = 0;
        for (int i = 0, j; i < n - 1; ++i)
        {
            j = i + 1;
            while (j < n && abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) // inc till cond satisfies
            {
                int xorValue = nums[i] ^ nums[j];
                maxXor = max(maxXor, xorValue);
                ++j;
            }
        }
        return maxXor;
    }
};
