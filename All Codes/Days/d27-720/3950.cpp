// Link: https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool consecutiveSetBits(int n) {
        // Each adjacent "11" pair shows up as a set bit in n & (n >> 1).
        return __builtin_popcount(n & (n >> 1)) == 1;
    }
};
