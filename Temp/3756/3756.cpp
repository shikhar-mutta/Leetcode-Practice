// Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long qpow(long long b, long long e, long long mod) {
        long long r = 1; b %= mod;
        while (e > 0) {
            if (e & 1) r = r * b % mod;
            b = b * b % mod;
            e >>= 1;
        }
        return r;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        vector<int> digit(n);
        for (int i = 0; i < n; i++) digit[i] = s[i] - '0';

        vector<long long> prefixDigitSum(n + 1, 0);
        vector<int> cntNZ(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixDigitSum[i + 1] = prefixDigitSum[i] + digit[i];
            cntNZ[i + 1] = cntNZ[i] + (digit[i] != 0 ? 1 : 0);
        }

        int maxCnt = cntNZ[n];
        vector<long long> pow10(maxCnt + 1), invPow10(maxCnt + 1);
        pow10[0] = 1;
        for (int i = 1; i <= maxCnt; i++) pow10[i] = pow10[i - 1] * 10 % MOD;
        long long inv10 = qpow(10, MOD - 2, MOD);
        invPow10[0] = 1;
        for (int i = 1; i <= maxCnt; i++) invPow10[i] = invPow10[i - 1] * inv10 % MOD;

        vector<long long> S(n + 1, 0);
        for (int i = 0; i < n; i++) {
            long long term = 0;
            if (digit[i] != 0) {
                term = (long long)digit[i] * invPow10[cntNZ[i + 1]] % MOD;
            }
            S[i + 1] = (S[i] + term) % MOD;
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long xsum = (S[r + 1] - S[l] + MOD) % MOD;
            long long x = xsum * pow10[cntNZ[r + 1]] % MOD;
            long long sumDigits = (prefixDigitSum[r + 1] - prefixDigitSum[l]) % MOD;
            long long res = x * sumDigits % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};
