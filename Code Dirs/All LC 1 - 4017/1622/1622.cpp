// Link: https://leetcode.com/problems/fancy-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Fancy {
public:
    static const long long MOD = 1e9 + 7;
    vector<long long> seq;
    long long mul = 1, add = 0;

    Fancy() {}

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    long long inv(long long a) { return power(a, MOD - 2); }

    void append(int val) {
        long long v = ((val - add) % MOD + MOD) % MOD;
        v = v * inv(mul) % MOD;
        seq.push_back(v);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= (int)seq.size()) return -1;
        return (int)((seq[idx] * mul + add) % MOD);
    }
};
