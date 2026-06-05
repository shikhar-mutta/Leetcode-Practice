// Link: https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Use bitset conversion & count, compare with k & add to sum if matches.
    // TC: O(n), SC: O(1)
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            if (bitset<32>(i).count() == k)
                sum += nums[i];
        return sum;
    }
};
