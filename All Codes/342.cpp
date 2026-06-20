// Link: https://leetcode.com/problems/power-of-four/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log4(n)), SC: O(1)
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        while (n > 1)
        {
            if (n % 4 != 0)
                return false;
            n >>= 2; // divide by 4 using right shift
        }
        return true;
    }
};
