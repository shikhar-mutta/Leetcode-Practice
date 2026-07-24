// Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach:
//    1. We will keep track of the number of even and odd prefix sums we have seen so far.
//    2. For each element in the array, we will update the parity of the prefix sum and update the count of even and odd prefix sums accordingly.
//    3. If the current prefix sum is odd, we can form subarrays with odd sum by pairing it with all the even prefix sums we have seen so far. If the current prefix sum is even, we can form subarrays with odd sum by pairing it with all the odd prefix sums we have seen so far.
//    4. We will return the total count of subarrays with odd sum modulo 10^9 + 7.
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        const int MOD = 1000000007;
        long long res = 0;
        int even = 1, odd = 0, parity = 0; // empty prefix is even
        for (int x : arr)
        {
            parity ^= (x & 1);
            if (parity)
            {
                res += even;
                ++odd;
            }
            else
            {
                res += odd;
                ++even;
            }
            res %= MOD;
        }
        return res;
    }
};
