// Link: https://leetcode.com/problems/powx-n/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: binary exponentiation; long long for n to safely negate INT_MIN
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) { x = 1 / x; N = -N; }
        double res = 1.0;
        while (N > 0) {
            if (N & 1) res *= x;
            x *= x;
            N >>= 1;
        }
        return res;
    }
};
