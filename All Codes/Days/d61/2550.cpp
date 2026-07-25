// Link: https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) (fast exponentiation)
// SC: O(1)
// Approach: each of the n monkeys independently picks one of 2 directions,
// giving 2^n total direction assignments; exactly 2 of those (all-clockwise,
// all-counterclockwise) avoid every collision, so the answer is 2^n - 2 mod
// 1e9+7, computed via modular exponentiation.
class Solution {
public:
    int monkeyMove(int n) {
        const long long MOD = 1000000007;
        long long total = modpow(2, n, MOD);
        return (int)((total - 2 + MOD) % MOD);
    }

private:
    long long modpow(long long b, long long e, long long m) {
        long long r = 1;
        b %= m;
        while (e) {
            if (e & 1)
                r = r * b % m;
            b = b * b % m;
            e >>= 1;
        }
        return r;
    }
};
