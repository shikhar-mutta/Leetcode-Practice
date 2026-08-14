// Link: https://leetcode.com/problems/string-transformation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    vector<int> kmpFail(const string& p) {
        int m = p.size();
        vector<int> f(m, 0);
        for (int i = 1; i < m; i++) {
            int j = f[i-1];
            while (j > 0 && p[i] != p[j]) j = f[j-1];
            if (p[i] == p[j]) j++;
            f[i] = j;
        }
        return f;
    }

    int numberOfWays(string s, string t, long long k) {
        int n = s.size();
        string text = s + s;
        vector<int> f = kmpFail(t);
        int cntT = 0;
        int j = 0;
        for (int i = 0; i < 2 * n; i++) {
            while (j > 0 && text[i] != t[j]) j = f[j-1];
            if (text[i] == t[j]) j++;
            if (j == n) {
                int start = i - n + 1;
                if (start < n) cntT++;
                j = f[j-1];
            }
        }

        long long invN = power(n, MOD - 2);
        long long pw = power(n - 1, k);
        long long negOne = (k % 2 == 0) ? 1 : MOD - 1;
        long long diffCount = ((pw - negOne) % MOD + MOD) % MOD * invN % MOD;
        long long sameCount = ((pw + (long long)(n - 1) * negOne) % MOD + MOD) % MOD * invN % MOD;

        long long ans;
        if (s == t) {
            ans = (sameCount + (long long)(cntT - 1) * diffCount) % MOD;
        } else {
            ans = (long long)cntT * diffCount % MOD;
        }
        return (int)((ans % MOD + MOD) % MOD);
    }
};
