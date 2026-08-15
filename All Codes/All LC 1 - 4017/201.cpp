// Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(logN) SC: O(1)
    // Approach:
    // 1. We can use the property of bitwise AND operation that if we keep right shifting both left and right until they are equal, we can find the common prefix of the two numbers.
    // 2. The number of shifts we performed will give us the number of bits that are different between left and right. We can then left shift the common prefix back to its original position to get the final result.
    // 3. This works because the bits that are different between left and right will always result in 0 when ANDed together, so we only need to keep the common prefix.
    int rangeBitwiseAnd(int left, int right)
    {
        int shift = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};
