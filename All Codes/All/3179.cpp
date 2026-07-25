// Link: https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) (n multiplications/inversions to build the binomial coefficient)
// SC: O(1)
// Approach: after k seconds, the prefix-sum recurrence applied n times to an
// all-ones array of length n is a known stars-and-bars identity: the final
// value at index n-1 equals C(n+k-1, n-1). Compute that binomial coefficient
// mod 1e9+7 via a running numerator/denominator product and a modular
// inverse (Fermat's little theorem) for the division.
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const long long MOD = 1000000007;
        // answer = C(n + k - 1, n - 1)
        int N = n + k - 1, R = n - 1;
        long long num = 1, den = 1;
        for (int i = 0; i < R; ++i) {
            num = num * ((N - i) % MOD) % MOD;
            den = den * ((i + 1) % MOD) % MOD;
        }
        return (int)(num * modpow(den, MOD - 2, MOD) % MOD);
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
