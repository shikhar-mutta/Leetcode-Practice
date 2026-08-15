// Link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nCkModP(long long n, long long k, int p) {
        if (k < 0 || k > n) return 0;
        long long result = 1;
        while (n > 0 || k > 0) {
            long long ni = n % p, ki = k % p;
            if (ki > ni) return 0;
            // small nCk mod p via direct computation (p small: 2 or 5)
            long long num = 1, den = 1;
            for (long long i = 0; i < ki; i++) {
                num = (num * (ni - i)) % p;
                den = (den * (i + 1)) % p;
            }
            // modular inverse of den mod p (p prime, den != 0)
            long long inv = 1, base = den % p, e = p - 2;
            while (e > 0) {
                if (e & 1) inv = (inv * base) % p;
                base = (base * base) % p;
                e >>= 1;
            }
            result = (result * num % p * inv) % p;
            n /= p;
            k /= p;
        }
        return (int)result;
    }

    int combModP2P5(int m, long long j) {
        int a = nCkModP(m, j, 2);
        int b = nCkModP(m, j, 5);
        for (int r = 0; r < 10; r++) {
            if (r % 2 == a && r % 5 == b) return r;
        }
        return 0;
    }

    bool hasSameDigits(string s) {
        int n = s.size();
        int m = n - 2;
        int d0 = 0, d1 = 0;
        for (int j = 0; j <= m; j++) {
            int c = combModP2P5(m, j);
            d0 = (d0 + c * (s[j] - '0')) % 10;
            d1 = (d1 + c * (s[j + 1] - '0')) % 10;
        }
        return d0 == d1;
    }
};
