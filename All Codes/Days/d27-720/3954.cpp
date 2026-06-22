// Link: https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(k), SC: O(1)
    int sumOfGoodIntegers(int n, int k)
    {
        int sum = 0;
        // max(1, n - k) is used to ensure that the lower bound of the range is at least 1.
        for (int x = max(1, n - k); x <= n + k; ++x)
            if ((n & x) == 0)
                sum += x;
        return sum;
    }
};
