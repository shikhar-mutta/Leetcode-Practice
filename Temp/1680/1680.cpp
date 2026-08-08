// Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1e9 + 7;
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            int bits = 32 - __builtin_clz(i);
            res = ((res << bits) % MOD + i) % MOD;
        }
        return (int)res;
    }
};
