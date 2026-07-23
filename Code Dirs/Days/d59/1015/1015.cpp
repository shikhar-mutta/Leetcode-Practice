// Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(k) where k is the input number.
    // SC: O(1) as we are using constant space.
    // Approach:
    //  1. We will check if k is divisible by 2 or 5, if yes then we will return -1 as there is no such number.
    //  2. We will iterate from 1 to k and for each length, we will calculate the remainder of the number formed by length number of 1's when divided by k.
    //  3. If the remainder is 0, we will return the length as the answer.
    //  4. If we reach the end of the loop and the remainder is not 0, we will return -1 as there is no such number.
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        long long remainder = 0;
        for (int length = 1; length <= k; length++)
        {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0)
                return length;
        }
        return -1;
    }
};
