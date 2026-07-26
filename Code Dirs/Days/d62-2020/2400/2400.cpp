// Link: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k)
// SC: O(1)
// Approach: over k steps of +-1 each, if r steps go toward the target and
// (k-r) go away, net displacement = 2r-k, which must equal the required
// distance d = |endPos-startPos|; solving gives r = (k+d)/2. This is only
// achievable when d <= k and k-d is even (parity must match). Given valid
// r, the number of ways to choose WHICH r of the k steps go the "toward"
// direction is simply C(k, r), computed mod 1e9+7 via a running product
// and a modular inverse (Fermat's little theorem) for the division.
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        const long long MOD = 1000000007;
        int d = abs(endPos - startPos);
        if (d > k || (k - d) % 2 != 0)
            return 0;

        int r = (k + d) / 2; // number of right steps (toward target)
        return (int)nCr(k, r, MOD);
    }

private:
    long long nCr(int n, int r, long long MOD) {
        if (r < 0 || r > n)
            return 0;
        r = min(r, n - r);
        long long num = 1, den = 1;
        for (int i = 0; i < r; ++i) {
            num = num * ((n - i) % MOD) % MOD;
            den = den * ((i + 1) % MOD) % MOD;
        }
        return num * modpow(den, MOD - 2, MOD) % MOD;
    }
    long long modpow(long long b, long long e, long long m) {
        long long res = 1;
        b %= m;
        while (e) {
            if (e & 1)
                res = res * b % m;
            b = b * b % m;
            e >>= 1;
        }
        return res;
    }
};
