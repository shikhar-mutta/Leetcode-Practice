// Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(n)), SC: O(1)
    // Use binary representation of n to find the number of bits in n. 
    int smallestNumber(int n)
    {
        int cnt = 0;
        while (n)
            cnt++, n >>= 1;
        return (1 << cnt) - 1;
    }
};
