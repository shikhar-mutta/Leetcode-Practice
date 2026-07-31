// Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(logn) SC: O(1)
// Approach: We can use the property of XOR operation to find the minimum number of operations required to make the integer zero. We can keep XORing the number with itself right shifted by 1 until the number becomes zero. The number of times we perform this operation will be the minimum number of operations required to make the integer zero.
class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int res = 0;
        while (n)
        {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};
