// Link: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        // track minimum prefix sum — that's the bottleneck for the start value
        int prefSum = 0, minPrefix = INT_MAX;
        for (int x : nums)
        {
            prefSum += x;
            minPrefix = min(minPrefix, prefSum);
        }
        // startValue + minPrefix >= 1  =>  startValue >= 1 - minPrefix
        return max(1, 1 - minPrefix);
    }
};
