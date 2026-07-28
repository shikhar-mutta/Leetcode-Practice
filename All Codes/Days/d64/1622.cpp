// Link: https://leetcode.com/problems/fancy-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Fancy {
    const long long MOD = 1e9 + 7;
    long long mult = 1, add = 0;
    vector<long long> vals, multSnap, addSnap;

    long long power(long long b, long long e, long long m) {
        long long r = 1; b %= m;
        while (e) {
            if (e & 1) r = r * b % m;
            b = b * b % m;
            e >>= 1;
        }
        return r;
    }
    long long inv(long long x) { return power(x, MOD - 2, MOD); }
public:
    Fancy() {}

    void append(int val) {
        vals.push_back(val);
        multSnap.push_back(mult);
        addSnap.push_back(add);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mult = mult * m % MOD;
        add = add * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= (int)vals.size()) return -1;
        long long ratio = mult * inv(multSnap[idx]) % MOD;
        long long res = (vals[idx] * ratio % MOD + add - addSnap[idx] * ratio % MOD + MOD) % MOD;
        return (int)res;
    }
};
