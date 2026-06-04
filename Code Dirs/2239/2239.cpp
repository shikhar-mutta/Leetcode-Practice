// Link: https://leetcode.com/problems/find-closest-number-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int MinDist = INT_MAX, val = INT_MIN;
        for (auto it : nums)
        {
            if (abs(it) < MinDist)
            { // update the minimum distance and the value
                MinDist = abs(it);
                val = it;
            }
            else if (abs(it) == MinDist && it > val) // tie breaker: choose the positive one
                val = it;
        }
        return val;
    }
};
