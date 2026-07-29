// Link: https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long b, long long e, long long m) {
        long long r = 1; b %= m;
        while (e > 0) {
            if (e & 1) r = r * b % m;
            b = b * b % m;
            e >>= 1;
        }
        return r;
    }
    long long modinv(long long v) { return power(v, MOD - 2, MOD); }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> a(nums.begin(), nums.end());

        int sqrtN = max(1, (int)sqrt((double)n));

        map<int, vector<array<int,3>>> smallGroups; // k -> list of (l, r, v)
        vector<array<int,4>> largeQueries;

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k <= sqrtN) {
                smallGroups[k].push_back({l, r, v});
            } else {
                largeQueries.push_back({l, r, k, v});
            }
        }

        // large-k: direct simulation
        for (auto& q : largeQueries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                a[idx] = (a[idx] * v) % MOD;
            }
        }

        // small-k: grouped difference technique
        vector<long long> diff(n + 1);
        for (auto& [k, qs] : smallGroups) {
            fill(diff.begin(), diff.end(), 1LL);
            for (auto& q : qs) {
                int l = q[0], r = q[1], v = q[2];
                int lastIdx = l + ((r - l) / k) * k;
                diff[l] = (diff[l] * v) % MOD;
                int undoPos = lastIdx + k;
                if (undoPos < n) diff[undoPos] = (diff[undoPos] * modinv(v)) % MOD;
            }
            for (int residue = 0; residue < k; residue++) {
                long long running = 1;
                for (int idx = residue; idx < n; idx += k) {
                    running = (running * diff[idx]) % MOD;
                    a[idx] = (a[idx] * running) % MOD;
                }
            }
        }

        long long result = 0;
        for (long long x : a) result ^= x;
        return (int)result;
    }
};
