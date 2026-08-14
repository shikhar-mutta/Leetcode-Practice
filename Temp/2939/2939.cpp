// Link: https://leetcode.com/problems/maximum-xor-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        for (int i = n - 1; i >= 0; i--) {
            int abit = (a >> i) & 1;
            int bbit = (b >> i) & 1;
            if (abit == bbit) {
                a |= (1LL << i);
                b |= (1LL << i);
            } else {
                int desired = (a <= b) ? 1 : 0;
                int x = abit ^ desired;
                if (x) { a ^= (1LL << i); b ^= (1LL << i); }
            }
        }
        const long long MOD = 1e9 + 7;
        __int128 prod = (__int128)(a % MOD) * (b % MOD);
        return (int)(long long)(prod % MOD);
    }
};
