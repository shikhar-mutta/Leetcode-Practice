// Link: https://leetcode.com/problems/count-the-number-of-infection-sequences/description/

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

    int numberOfSequence(int n, vector<int>& sick) {
        int m = sick.size();
        int totalFree = n - m;
        vector<long long> fact(totalFree + 1), inv_fact(totalFree + 1);
        fact[0] = 1;
        for (int i = 1; i <= totalFree; i++) fact[i] = fact[i-1] * i % MOD;
        inv_fact[totalFree] = power(fact[totalFree], MOD - 2);
        for (int i = totalFree; i > 0; i--) inv_fact[i-1] = inv_fact[i] * i % MOD;

        vector<int> gaps;
        gaps.push_back(sick[0]); // first gap, boundary
        for (int i = 0; i + 1 < m; i++) gaps.push_back(sick[i+1] - sick[i] - 1);
        gaps.push_back(n - 1 - sick[m-1]); // last gap, boundary

        long long ans = fact[totalFree];
        for (int g : gaps) ans = ans * inv_fact[g] % MOD;

        for (int i = 1; i + 1 < (int)gaps.size(); i++) { // internal gaps only
            if (gaps[i] > 0) ans = ans * power(2, gaps[i] - 1) % MOD;
        }
        return (int)ans;
    }
};
