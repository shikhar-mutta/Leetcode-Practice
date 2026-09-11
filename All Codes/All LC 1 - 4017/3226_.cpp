// Link: https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChanges(int n, int k)
    {
        // If n doesn't have all the bits that k has, it's impossible to make them equal.
        if ((n & k) != k)
            return -1;
        // XOR gives different bits, and popcount counts them.
        return __builtin_popcount(n ^ k);
    }
};
