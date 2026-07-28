// Link: https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum of digit counts) SC: O(1)
//  Approach: for each number, compute (max digit - min digit). Find the
//  maximum such range across all numbers, then sum every number
//  achieving that maximum range.
class Solution
{
public:
    int find(int n)
    {
        int maxm = 0, minm = INT_MAX;
        while (n != 0)
        {
            int k = n % 10;
            maxm = max(maxm, k);
            minm = min(minm, k);
            n /= 10;
        }
        return maxm - minm;
    }
    int maxDigitRange(vector<int> &nums)
    {
        int maxRange = -1;
        int ans = 0;

        for (int x : nums)
            maxRange = max(maxRange, find(x));

        for (int x : nums)
            if (find(x) == maxRange)
                ans += x;

        return ans;
    }
};