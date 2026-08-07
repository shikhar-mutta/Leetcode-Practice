// Link: https://leetcode.com/problems/divide-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log^2(n))  SC: O(1)
// Approach: repeated doubling (bit-shift) subtraction using long long to sidestep overflow, sign handled separately
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long a = abs((long long)dividend), b = abs((long long)divisor);
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long res = 0;
        while (a >= b) {
            long long cur = b, multiple = 1;
            while (a >= (cur << 1)) { cur <<= 1; multiple <<= 1; }
            a -= cur;
            res += multiple;
        }
        return (int)(sign * res);
    }
};
