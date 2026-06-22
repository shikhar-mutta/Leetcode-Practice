// Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int isPrime[20] = {0};
        for (int p : {2, 3, 5, 7, 11, 13, 17, 19})
            isPrime[p] = 1;

        int count = 0;
        for (int n = left; n <= right; ++n)
            if (isPrime[__builtin_popcount(n)])
                ++count;
        return count;
    }
};
