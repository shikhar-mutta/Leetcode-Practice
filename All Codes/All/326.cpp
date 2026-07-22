// Link: https://leetcode.com/problems/power-of-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    //  Approach:
    //    1. The maximum power of three that can fit in a 32-bit signed integer is 3^19 = 1162261467. Therefore, any power of three must be a divisor of 1162261467. We can check if n is a power of three by verifying that n is greater than 0 and that 1162261467 is divisible by n. If both conditions are satisfied, we return true; otherwise, we return false.
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
};
