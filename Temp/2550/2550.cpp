// Link: https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int monkeyMove(int n) {
        const long long MOD = 1e9 + 7;
        long long result = 1;
        long long base = 2;
        long long e = n;
        while (e > 0) {
            if (e & 1) result = result * base % MOD;
            base = base * base % MOD;
            e >>= 1;
        }
        result = (result - 2 + MOD) % MOD;
        return (int)result;
    }
};
