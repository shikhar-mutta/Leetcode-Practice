// Link: https://leetcode.com/problems/distinct-echo-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2) worst case for the dedup set
// Approach: precompute a rolling hash of `text` for O(1) substring hash
// comparison. For every half-length L and start index i, check whether
// text[i..i+L) equals text[i+L..i+2L) via hash equality (verified with
// a direct compare to avoid collisions), and if so add that substring
// to a set to track distinct echo substrings.
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        const unsigned long long BASE = 131, MOD = 1000000000000000003ULL;
        vector<unsigned long long> h(n + 1, 0), power(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = (__uint128_t(h[i]) * BASE + text[i]) % MOD;
            power[i + 1] = (__uint128_t(power[i]) * BASE) % MOD;
        }
        auto getHash = [&](int l, int r) { // [l, r)
            unsigned long long sub = (__uint128_t(h[l]) * power[r - l]) % MOD;
            unsigned long long res = (h[r] + MOD - sub) % MOD;
            return res;
        };

        unordered_set<string> found;
        for (int L = 1; 2 * L <= n; L++) {
            for (int i = 0; i + 2 * L <= n; i++) {
                if (getHash(i, i + L) == getHash(i + L, i + 2 * L)) {
                    if (text.compare(i, L, text, i + L, L) == 0) {
                        found.insert(text.substr(i, L));
                    }
                }
            }
        }
        return found.size();
    }
};
