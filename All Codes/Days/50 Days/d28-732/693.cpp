// Link: https://leetcode.com/problems/binary-number-with-alternating-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    bool hasAlternatingBits(int n)
    {
        // check 2 consecutive bits are not same
        long x = (long)n ^ (n >> 1);
        // check last set bit is 0, means all bits are 1
        return (x & (x + 1)) == 0;
    }
};
