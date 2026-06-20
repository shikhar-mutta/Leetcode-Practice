// Link: https://leetcode.com/problems/power-of-two/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n). SC: O(1).
    bool isPowerOfTwo(int n)
    {
        if (n <= 0) // negative numbers and 0 are not powers of 2
            return false;
        while (n > 1 && n % 2 == 0) // divide by 2 until n becomes 1 or odd
            n = n / 2;
        return n == 1; // if n is 1, it is a power of 2; otherwise, it is not
    }
};