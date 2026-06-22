// Link: https://leetcode.com/problems/number-complement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n), SC: O(1)
    int findComplement(int num)
    {
        unsigned mask = 1;
        while (mask < (unsigned)num)
            mask = (mask << 1) | 1;
        return num ^ mask;
    }
};
