// Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    int colorTheGrid(int m, int n) {
        vector<vector<int>> columns;
        vector<int> col(m);
        function<void(int)> gen = [&](int i) {
            if (i == m) {
                columns.push_back(col);
                return;
            }
            for (int c = 0; c < 3; c++) {
                if (i > 0 && col[i-1] == c) continue;
                col[i] = c;
                gen(i + 1);
            }
        };
        gen(0);

        int k = columns.size();
        vector<vector<int>> compatible(k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                bool ok = true;
                for (int r = 0; r < m; r++) {
                    if (columns[i][r] == columns[j][r]) { ok = false; break; }
                }
                if (ok) compatible[i].push_back(j);
            }
        }

        vector<long long> dp(k, 1);
        for (int col_idx = 1; col_idx < n; col_idx++) {
            vector<long long> ndp(k, 0);
            for (int i = 0; i < k; i++) {
                if (dp[i] == 0) continue;
                for (int j : compatible[i]) {
                    ndp[j] = (ndp[j] + dp[i]) % MOD;
                }
            }
            dp = ndp;
        }

        long long total = 0;
        for (long long v : dp) total = (total + v) % MOD;
        return (int)total;
    }
};
