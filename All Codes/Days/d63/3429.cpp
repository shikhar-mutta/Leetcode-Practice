// Link: https://leetcode.com/problems/paint-house-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: pair up house i with its mirror n-1-i (must differ in color).
// Process i from 0 upward, keeping dp[c1][c2] = min cost so far with
// house i colored c1 and its mirror colored c2 (c1 != c2), enforcing the
// usual adjacent-houses-differ rule on both sides each step. If n is odd
// there's one middle house left over; its color is forced to be whichever
// of the 3 colors isn't c1 or c2 (it's adjacent to both).
class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        const long long INF = LLONG_MAX / 2;
        int m = n / 2;

        if (m == 0) {
            long long best = INF;
            for (int c = 0; c < 3; c++) best = min(best, (long long)cost[0][c]);
            return best;
        }

        vector<vector<long long>> dp(3, vector<long long>(3, INF));
        for (int c1 = 0; c1 < 3; c1++)
            for (int c2 = 0; c2 < 3; c2++)
                if (c1 != c2) dp[c1][c2] = cost[0][c1] + cost[n-1][c2];

        for (int i = 1; i < m; i++) {
            vector<vector<long long>> ndp(3, vector<long long>(3, INF));
            for (int c1 = 0; c1 < 3; c1++) {
                for (int c2 = 0; c2 < 3; c2++) {
                    if (c1 == c2) continue;
                    long long best = INF;
                    for (int p1 = 0; p1 < 3; p1++) {
                        if (p1 == c1) continue;
                        for (int p2 = 0; p2 < 3; p2++) {
                            if (p2 == c2 || p1 == p2) continue;
                            best = min(best, dp[p1][p2]);
                        }
                    }
                    if (best < INF) ndp[c1][c2] = best + cost[i][c1] + cost[n-1-i][c2];
                }
            }
            dp = ndp;
        }

        long long ans = INF;
        if (n % 2 == 0) {
            for (int c1 = 0; c1 < 3; c1++)
                for (int c2 = 0; c2 < 3; c2++)
                    if (c1 != c2) ans = min(ans, dp[c1][c2]);
        } else {
            int mid = m;
            for (int c1 = 0; c1 < 3; c1++) {
                for (int c2 = 0; c2 < 3; c2++) {
                    if (c1 == c2 || dp[c1][c2] >= INF) continue;
                    int cmid = 3 - c1 - c2;
                    ans = min(ans, dp[c1][c2] + cost[mid][cmid]);
                }
            }
        }
        return ans;
    }
};
