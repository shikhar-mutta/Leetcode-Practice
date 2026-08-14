// Link: https://leetcode.com/problems/count-number-of-ways-to-place-houses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        const long long MOD = 1e9 + 7;
        long long a = 1, b = 2; // f(0), f(1)
        for (int i = 2; i <= n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
        }
        long long f = (n == 0) ? a : b;
        return (int)((f * f) % MOD);
    }
};
