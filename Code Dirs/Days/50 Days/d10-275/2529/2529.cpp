// Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maximumCount(vector<int> &nums)
    {
        int posCount = 0, negCount = 0;
        for (int num : nums)
        {
            if (num > 0)
                posCount++;
            else if (num < 0)
                negCount++;
        }
        return max(posCount, negCount);
    }
};
