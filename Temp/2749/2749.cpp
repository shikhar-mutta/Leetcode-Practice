// Link: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; k++) {
            long long target = (long long)num1 - k * (long long)num2;
            if (target < k) continue;
            int bits = __builtin_popcountll(target);
            if (bits <= k) return (int)k;
        }
        return -1;
    }
};
