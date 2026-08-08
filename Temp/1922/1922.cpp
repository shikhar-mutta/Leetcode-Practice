// Link: https://leetcode.com/problems/count-good-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long res = power(5, even) * power(4, odd) % MOD;
        return (int)res;
    }
};
