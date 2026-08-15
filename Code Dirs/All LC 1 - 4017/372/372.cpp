// Link: https://leetcode.com/problems/super-pow/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(len(b))  SC: O(1)
// Approach: process digits of b left to right; result = (result^10 * a^digit) mod 1337
class Solution {
    const int MOD = 1337;

    int modPow(int base, int exp) {
        int result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int digit : b) {
            result = modPow(result, 10) * modPow(a, digit) % MOD;
        }
        return result;
    }
};
