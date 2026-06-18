// Link: https://leetcode.com/problems/power-of-two/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n), SC: O(1)
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        while (n > 1 && n % 2 == 0)
            n = n / 2;
        return n == 1;
    }
};
