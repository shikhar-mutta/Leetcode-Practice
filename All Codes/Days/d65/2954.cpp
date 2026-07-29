// Link: https://leetcode.com/problems/count-the-number-of-infection-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: split the healthy children into gaps between consecutive sick positions (plus the
// two boundary gaps). A boundary gap (open on one side only) has exactly 1 valid internal
// infection order (must proceed strictly from the sick end). An internal gap of length g (open
// on both ends) has 2^(g-1) valid internal orders (each interior position becomes reachable from
// either direction, giving a free binary choice per step but the last step is forced). The
// global answer interleaves all gaps' events via a multinomial coefficient, times each gap's own
// internal order count.
class Solution {
public:
    const long long MOD = 1e9+7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    int numberOfSequence(int n, vector<int>& sick) {
        int m = sick.size();
        vector<long long> fact(n+1), invFact(n+1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[n] = power(fact[n], MOD-2);
        for (int i = n; i > 0; i--) invFact[i-1] = invFact[i] * i % MOD;

        vector<int> gaps;
        gaps.push_back(sick[0]); // before first sick
        for (int i = 1; i < m; i++) gaps.push_back(sick[i] - sick[i-1] - 1);
        gaps.push_back(n - 1 - sick[m-1]); // after last sick

        long long H = 0;
        long long ans = 1;
        for (int i = 0; i < (int)gaps.size(); i++) {
            int g = gaps[i];
            H += g;
            ans = ans * invFact[g] % MOD;
            bool boundary = (i == 0 || i == (int)gaps.size()-1);
            if (!boundary && g > 0) ans = ans * power(2, g-1) % MOD;
        }
        ans = ans * fact[H] % MOD;
        return (int)ans;
    }
};
