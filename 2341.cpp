// Link: https://leetcode.com/problems/maximum-number-of-pairs-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: frequency counting. TC: O(n), SC: O(1)
    vector<int> numberOfPairs(vector<int> &nums)
    {
        vector<int> freq(101, 0);
        for (int num : nums)
            freq[num]++;
        int pairs = 0, leftovers = 0;
        for (int count : freq)
        {
            pairs += count / 2;
            leftovers += count % 2;
        }
        return {pairs, leftovers};
    }
};
