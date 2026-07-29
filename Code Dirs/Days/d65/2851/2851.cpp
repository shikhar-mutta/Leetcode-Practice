// Link: https://leetcode.com/problems/string-transformation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + log K), SC: O(N)
// Approach: each operation adds a uniformly-random nonzero rotation-shift l in [1,n-1] mod n.
// By symmetry, define A(k)=ways total shift is 0 after k ops, B(k)=ways it's any fixed nonzero
// value; both satisfy a 2-state linear recurrence solvable via 2x2 matrix exponentiation.
// Separately, count how many rotation offsets of s equal t (via KMP on t within s+s), split
// into the c=0 case and c!=0 cases, and combine with A(k)/B(k).
class Solution {
public:
    const long long MOD = 1e9+7;

    vector<vector<long long>> matmul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        vector<vector<long long>> c(2, vector<long long>(2, 0));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int m = 0; m < 2; m++)
                    c[i][j] = (c[i][j] + a[i][m] * b[m][j]) % MOD;
        return c;
    }

    vector<vector<long long>> matpow(vector<vector<long long>> m, long long e) {
        vector<vector<long long>> r = {{1,0},{0,1}};
        while (e > 0) {
            if (e & 1) r = matmul(r, m);
            m = matmul(m, m);
            e >>= 1;
        }
        return r;
    }

    int numberOfWays(string s, string t, long long k) {
        int n = s.size();
        string ss = s + s;

        // KMP search for occurrences of t within ss[0..2n-2]
        vector<int> fail(t.size(), 0);
        for (int i = 1; i < (int)t.size(); i++) {
            int j = fail[i-1];
            while (j > 0 && t[i] != t[j]) j = fail[j-1];
            if (t[i] == t[j]) j++;
            fail[i] = j;
        }

        int matches0 = 0, matchesNonZero = 0;
        int j = 0;
        for (int i = 0; i < 2*n - 1; i++) {
            while (j > 0 && ss[i] != t[j]) j = fail[j-1];
            if (ss[i] == t[j]) j++;
            if (j == (int)t.size()) {
                int start = i - (int)t.size() + 1;
                if (start < n) {
                    if (start == 0) matches0++;
                    else matchesNonZero++;
                }
                j = fail[j-1];
            }
        }

        vector<vector<long long>> M = {{0, (long long)(n-1) % MOD}, {1, (long long)(n-2 < 0 ? 0 : n-2) % MOD}};
        auto Mk = matpow(M, k);
        long long A = Mk[0][0]; // A(k) since [A(0),B(0)]=[1,0], A(k)=Mk[0][0]*1+Mk[0][1]*0
        long long B = Mk[1][0];

        long long ans = (A * matches0 + B * matchesNonZero) % MOD;
        return (int)ans;
    }
};
