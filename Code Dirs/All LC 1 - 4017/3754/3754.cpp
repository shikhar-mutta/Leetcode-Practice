// Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(log n)
// Approach: scan digits of n, skip zeros, build the concatenated value of
// nonzero digits and their sum, then multiply.
class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        string s = to_string(n);
        long long concat = 0, sum = 0;
        for (char c : s)
        {
            int d = c - '0';
            if (d == 0)
                continue;
            concat = concat * 10 + d;
            sum += d;
        }
        return concat * sum;
    }
};
