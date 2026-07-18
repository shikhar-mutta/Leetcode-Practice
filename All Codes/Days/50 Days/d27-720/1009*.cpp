// Link: https://leetcode.com/problems/complement-of-base-10-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;               // 0 has one bit; its complement is 1
        // Build a mask of 1s as wide as n, then flip every bit.
        int mask = (1 << (32 - __builtin_clz(n))) - 1;
        return n ^ mask;
    }
};
