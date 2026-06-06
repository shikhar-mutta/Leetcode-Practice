// Link: https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    int duplicateNumbersXOR(vector<int> &nums)
    {
        vector<int> freq(51, 0);
        int n = nums.size(), xorSum = 0;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
            if (freq[nums[i]] == 2)
                xorSum ^= nums[i];
        }

        return xorSum;
    }
};
