// Link: https://leetcode.com/problems/sum-of-k-digit-numbers-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log k)  SC: O(1)
// Approach: l and r are allowed DIGIT values (not number bounds); count and
// sum every k-digit string (leading zeros allowed) using digits from [l,r]
// at each of the k independent positions. Each position contributes
// independently: total = (sum of digits l..r) * numDigits^(k-1) *
// repunit(k), where numDigits=r-l+1 and repunit(k)=111...1 (k ones) =
// (10^k-1)/9, computed via modular exponentiation and the modular inverse
// of 9 mod 1e9+7.
class Solution {
    static const long long MOD = 1000000007;
    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    }
public:
    int sumOfNumbers(int l, int r, int k) {
        long long numDigits = r - l + 1;
        long long sumDigits = (long long)(l + r) * numDigits / 2 % MOD;
        long long invNine = modpow(9, MOD - 2, MOD);
        long long repunit = (modpow(10, k, MOD) - 1 + MOD) % MOD * invNine % MOD;
        long long total = sumDigits * modpow(numDigits, k - 1, MOD) % MOD * repunit % MOD;
        return (int)total;
    }
};
