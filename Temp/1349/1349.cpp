// Link: https://leetcode.com/problems/maximum-students-taking-exam/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<int> avail(m, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (seats[i][j] == '.') avail[i] |= (1 << j);

        int full = 1 << n;
        vector<vector<int>> dp(m, vector<int>(full, -1));

        auto validRow = [&](int mask) {
            return (mask & (mask << 1)) == 0;
        };

        for (int mask = 0; mask < full; mask++) {
            if ((mask & avail[0]) == mask && validRow(mask)) {
                dp[0][mask] = __builtin_popcount(mask);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int mask = 0; mask < full; mask++) {
                if ((mask & avail[i]) != mask || !validRow(mask)) continue;
                for (int prev = 0; prev < full; prev++) {
                    if (dp[i-1][prev] == -1) continue;
                    if ((mask & (prev << 1)) || (mask & (prev >> 1))) continue;
                    dp[i][mask] = max(dp[i][mask], dp[i-1][prev] + __builtin_popcount(mask));
                }
            }
        }

        int best = 0;
        for (int mask = 0; mask < full; mask++) best = max(best, dp[m-1][mask]);
        return best;
    }
};
