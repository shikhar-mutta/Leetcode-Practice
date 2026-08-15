// Link: https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    // Approach:
    //   1. We will iterate through the array and for each number, we will count the number of 1's in its binary representation and the number of bits required to represent it
    //   2. The number of 1's will be the number of increment operations
    //   3. The number of bits required to represent the maximum number will be the number of double operations
    //   4. The total number of operations will be the sum of the number of increment operations and the number of double operations
    //   5. We will return the total number of operations
    int minOperations(vector<int> &nums)
    {
        int ones = 0, maxBits = 0;
        for (int x : nums)
        {
            ones += __builtin_popcount(x);
            int bits = x ? 32 - __builtin_clz(x) : 0;
            maxBits = max(maxBits, bits);
        }
        return ones + (maxBits > 0 ? maxBits - 1 : 0);
    }
};
