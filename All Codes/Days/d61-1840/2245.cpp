// Link: https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)
// SC: O(n*m)
// Approach: trailing zeros of a product come from min(total count of
// factor 2, total count of factor 5) across the path. Every valid
// "cornered path" (an L-shape: straight then one turn) decomposes into a
// vertical segment plus a horizontal segment sharing a corner cell, so
// precompute prefix sums of factor-2 and factor-5 counts along each row
// (dp[i][j] = running row-prefix at (i,j)) and, for every corner cell,
// consider all 4 L-shape orientations (vertical run combined with the
// horizontal run to its left or right) by combining a vertical prefix
// (built incrementally while sweeping each column top-down and
// bottom-up) with the corner's row-prefix on either side.
class Solution {
public:
    void cnt25(int& cnt2, int& cnt5, int v) {
        while (v % 2 == 0) {
            cnt2++;
            v /= 2;
        }
        while (v % 5 == 0) {
            cnt5++;
            v /= 5;
        }
    }

    int maxTrailingZeros(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int dp[n][m][2];
        memset(dp, 0, sizeof(dp));
        int answ = 0;
        bool printed = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt25(dp[i][j][0], dp[i][j][1], grid[i][j]);
                if (j) {
                    dp[i][j][0] += dp[i][j - 1][0];
                    dp[i][j][1] += dp[i][j - 1][1];
                }
                answ = max(answ, min(dp[i][j][0], dp[i][j][1]));
                // printf("(%d,%d) ", dp[i][j][0], dp[i][j][1]);
            }
            // puts("");
        }

        for (int j = 0; j < m; ++j) {
            int vcnt2 = 0, vcnt5 = 0;
            for (int i = 0; i < n; ++i) {
                vcnt2 += dp[i][j][0];
                vcnt5 += dp[i][j][1];

                int hlcnt2 = 0, hlcnt5 = 0;
                if (j) {
                    hlcnt2 = dp[i][j - 1][0];
                    hlcnt5 = dp[i][j - 1][1];
                    vcnt2 -= hlcnt2;
                    vcnt5 -= hlcnt5;
                }
                answ = max(answ, min(vcnt2 + hlcnt2, vcnt5 + hlcnt5));

                int hrcnt2 = dp[i][m - 1][0] - dp[i][j][0],
                    hrcnt5 = dp[i][m - 1][1] - dp[i][j][1];
                answ = max(answ, min(vcnt2 + hrcnt2, vcnt5 + hrcnt5));
            }
        }

        for (int j = 0; j < m; ++j) {
            int vcnt2 = 0, vcnt5 = 0;
            for (int i = n - 1; i >= 0; --i) {
                vcnt2 += dp[i][j][0];
                vcnt5 += dp[i][j][1];

                int hlcnt2 = 0, hlcnt5 = 0;
                if (j) {
                    hlcnt2 = dp[i][j - 1][0];
                    hlcnt5 = dp[i][j - 1][1];
                    vcnt2 -= hlcnt2;
                    vcnt5 -= hlcnt5;
                }
                answ = max(answ, min(vcnt2 + hlcnt2, vcnt5 + hlcnt5));

                int hrcnt2 = dp[i][m - 1][0] - dp[i][j][0],
                    hrcnt5 = dp[i][m - 1][1] - dp[i][j][1];
                answ = max(answ, min(vcnt2 + hrcnt2, vcnt5 + hrcnt5));
            }
        }

        return answ;
    }
};
