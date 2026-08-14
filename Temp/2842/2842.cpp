// Link: https://leetcode.com/problems/count-k-subsequences-of-a-string-with-maximum-beauty/description/

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

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<long long> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        vector<long long> nz;
        for (int i = 0; i < 26; i++) if (freq[i] > 0) nz.push_back(freq[i]);
        if ((int)nz.size() < k) return 0;
        sort(nz.rbegin(), nz.rend());

        long long ans = 1;
        int selected = 0;
        for (int i = 0; i < k; i++) {
            ans = ans * (nz[i] % MOD) % MOD;
            selected++;
        }
        long long threshold = nz[k - 1];
        int tiedTotal = 0, tiedUsed = 0;
        for (long long v : nz) if (v == threshold) tiedTotal++;
        for (int i = 0; i < k; i++) if (nz[i] == threshold) tiedUsed++;

        // combination C(tiedTotal, tiedUsed) mod
        long long num = 1, den = 1;
        for (int i = 0; i < tiedUsed; i++) {
            num = num * ((tiedTotal - i) % MOD) % MOD;
            den = den * (i + 1) % MOD;
        }
        long long comb = num * power(den, MOD - 2) % MOD;

        return (int)(ans * comb % MOD);
    }
};
