// Link: https://leetcode.com/problems/mirror-distance-of-an-integer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: reverse the digits of n (trailing zeros naturally drop as
// leading zeros of the reversed value) and return the absolute
// difference from the original.
class Solution
{
public:
    int mirrorDistance(int n)
    {
        int x = n, rev = 0;
        while (x > 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return abs(n - rev);
    }
};
