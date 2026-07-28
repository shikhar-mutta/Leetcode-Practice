// Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(3^m * 3^m + n * validColumns^2)  SC: O(3^m)
// Approach: enumerate all valid columns (base-3 digit strings of length m
// with no two vertically adjacent equal), precompute compatible column pairs
// (no row-wise equal between adjacent columns), then DP across n columns.
class Solution {
public:
    int colorTheGrid(int m, int n) {
        const long long MOD = 1e9 + 7;
        vector<vector<int>> cols;
        vector<int> cur(m);
        function<void(int)> gen = [&](int idx) {
            if (idx == m) { cols.push_back(cur); return; }
            for (int c = 0; c < 3; c++) {
                if (idx > 0 && cur[idx-1] == c) continue;
                cur[idx] = c;
                gen(idx + 1);
            }
        };
        gen(0);
        int k = cols.size();
        vector<vector<int>> compat(k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                bool ok = true;
                for (int r = 0; r < m && ok; r++) if (cols[i][r] == cols[j][r]) ok = false;
                if (ok) compat[i].push_back(j);
            }
        }
        vector<long long> dp(k, 1);
        for (int step = 1; step < n; step++) {
            vector<long long> ndp(k, 0);
            for (int i = 0; i < k; i++) {
                if (dp[i] == 0) continue;
                for (int j : compat[i]) ndp[j] = (ndp[j] + dp[i]) % MOD;
            }
            dp = ndp;
        }
        long long ans = 0;
        for (long long v : dp) ans = (ans + v) % MOD;
        return (int)ans;
    }
};
