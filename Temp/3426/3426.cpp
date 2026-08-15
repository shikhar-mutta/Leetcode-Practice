// Link: https://leetcode.com/problems/manhattan-distances-of-all-arrangements-of-pieces/description/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX3426 = 1'000'00 + 5;
const int mod3426 = 1'000'000'000 + 7;
ll F3426[MX3426 + 5], INV_F3426[MX3426 + 5];

ll qpow3426(ll x, int n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * x) % mod3426;
        x = (x * x) % mod3426;
        n >>= 1;
    }
    return res;
}

auto init3426 = [] {
    F3426[0] = 1;
    for (int i = 1; i <= MX3426; ++i) {
        F3426[i] = (F3426[i - 1] * i) % mod3426;
    }
    INV_F3426[MX3426] = qpow3426(F3426[MX3426], mod3426 - 2);
    for (int i = MX3426; i; --i) {
        INV_F3426[i - 1] = (INV_F3426[i] * i) % mod3426;
    }
    return 0;
}();

ll comb3426(int m, int n) {
    return n < 0 || n > m ? 0 : F3426[m] * INV_F3426[n] % mod3426 * INV_F3426[m - n] % mod3426;
}

class Solution {
public:
    int distanceSum(int m, int n, int k) {
        return comb3426(m * n - 2, k - 2) * (1LL * m * m % mod3426 * comb3426(n + 1, 3) % mod3426 + 1LL * n * n % mod3426 * comb3426(m + 1, 3) % mod3426) % mod3426;
    }
};
