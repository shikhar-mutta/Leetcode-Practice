// Link: https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: pos's own choice never affects the visible count (2 free
// ways). Each of the (left = pos) and (right = n-1-pos) other people
// independently has exactly one direction that makes them visible and
// one that doesn't, so the count of assignments with exactly k visible
// among them is simply C(left+right, k). Multiply by 2 for pos's choice.
class Solution {
    static const int MOD = 1e9 + 7;
public:
    int countVisiblePeople(int n, int pos, int k) {
        int total = n - 1; // left + right = everyone except pos
        if (k > total) return 0;

        vector<long long> fact(total + 1);
        fact[0] = 1;
        for (int i = 1; i <= total; i++) fact[i] = fact[i-1] * i % MOD;

        auto power = [&](long long b, long long e) {
            long long r = 1; b %= MOD;
            while (e > 0) {
                if (e & 1) r = r * b % MOD;
                b = b * b % MOD;
                e >>= 1;
            }
            return r;
        };
        auto inv = [&](long long x) { return power(x, MOD - 2); };

        long long comb = fact[total] * inv(fact[k]) % MOD * inv(fact[total - k]) % MOD;
        return (int)(comb * 2 % MOD);
    }
};
