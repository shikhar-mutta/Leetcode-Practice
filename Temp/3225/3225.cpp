// Link: https://leetcode.com/problems/maximum-score-from-grid-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        // colPrefix[j][r] = sum_{i=0}^{r-1} grid[i][j]
        vector<vector<long long>> colPrefix(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
                colPrefix[j][i+1] = colPrefix[j][i] + grid[i][j];

        auto colSum = [&](int j, int lo, int hi) -> long long {
            if (hi <= lo) return 0;
            return colPrefix[j][hi] - colPrefix[j][lo];
        };

        const long long NEG = LLONG_MIN / 2;
        // dp[tPrev][tCur], initially column -1 sentinel (0) and column 0's threshold
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, NEG));
        for (int t0 = 0; t0 <= n; t0++) dp[0][t0] = 0;

        for (int j = 1; j <= n - 1; j++) {
            int col = j - 1; // finalize contribution for this column
            vector<vector<long long>> ndp(n + 1, vector<long long>(n + 1, NEG));
            for (int tPrev = 0; tPrev <= n; tPrev++) {
                for (int tCur = 0; tCur <= n; tCur++) {
                    if (dp[tPrev][tCur] <= NEG / 2) continue;
                    long long base = dp[tPrev][tCur];
                    for (int tNext = 0; tNext <= n; tNext++) {
                        int hi = max(tPrev, tNext);
                        long long val = base + colSum(col, tCur, hi);
                        if (val > ndp[tCur][tNext]) ndp[tCur][tNext] = val;
                    }
                }
            }
            dp = move(ndp);
        }

        long long best = 0;
        int lastCol = n - 1;
        for (int tPrev = 0; tPrev <= n; tPrev++) {
            for (int tCur = 0; tCur <= n; tCur++) {
                if (dp[tPrev][tCur] <= NEG / 2) continue;
                long long val = dp[tPrev][tCur] + colSum(lastCol, tCur, tPrev);
                best = max(best, val);
            }
        }
        return best;
    }
};
