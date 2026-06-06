// Link: https://leetcode.com/problems/split-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool isPossibleToSplit(vector<int> &nums)
    {
        int freq[101] = {};
        // If num appears more than 2 time, then can be split
        for (int x : nums)
            if (++freq[x] > 2)
                return false;
        return true;
    }
};
