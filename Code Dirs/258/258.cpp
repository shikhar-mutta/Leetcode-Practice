// Link: https://leetcode.com/problems/add-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    //  Approach:
    //  1. The digital root of a number can be found using the formula: 1 + (num - 1) % 9
    //  2. If the number is 0, return 0.
    //  3. Otherwise, return the digital root
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        // The digital root of a number can be found using the formula: 1 + (num - 1) % 9
        return 1 + (num - 1) % 9;
    }
};
