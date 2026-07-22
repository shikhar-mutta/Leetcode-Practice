// Link: https://leetcode.com/problems/bulb-switcher/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1)
    // SC: O(1)
    // Approach:
    //  1. The bulbs that remain on are the ones that are toggled an odd number of times. A bulb is toggled for every divisor it has. Most numbers have an even number of divisors, except for perfect squares, which have an odd number of divisors. Therefore, the number of bulbs that remain on after n rounds is equal to the number of perfect squares less than or equal to n. The number of perfect squares less than or equal to n is equal to  the largest integer k such that k^2 <= n, which is equal to the integer part of the square root of n. Therefore, the answer is simply the integer part of the square root of n.
    int bulbSwitch(int n)
    {
        return (int)sqrt((double)n);
    }
};
