// Link: https://leetcode.com/problems/minimum-array-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        const int INF = INT_MAX / 2;
        vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1, INF));
        dp[0][0] = 0;

        for (int x : nums) {
            // possible (usedOp1, usedOp2, cost) options
            vector<array<int,3>> options;
            options.push_back({0, 0, x});
            int v1 = (x + 1) / 2;
            options.push_back({1, 0, v1});
            if (x >= k) options.push_back({0, 1, x - k});

            // both: try op1 then op2
            int bestBoth = INT_MAX;
            {
                int a = (x + 1) / 2;
                if (a >= k) bestBoth = min(bestBoth, a - k);
            }
            {
                if (x >= k) {
                    int b = x - k;
                    bestBoth = min(bestBoth, (b + 1) / 2);
                }
            }
            if (bestBoth != INT_MAX) options.push_back({1, 1, bestBoth});

            vector<vector<int>> ndp(op1 + 1, vector<int>(op2 + 1, INF));
            for (int a = 0; a <= op1; a++) {
                for (int b = 0; b <= op2; b++) {
                    if (dp[a][b] >= INF) continue;
                    for (auto& [u1, u2, cost] : options) {
                        int na = a + u1, nb = b + u2;
                        if (na > op1 || nb > op2) continue;
                        ndp[na][nb] = min(ndp[na][nb], dp[a][b] + cost);
                    }
                }
            }
            dp = move(ndp);
        }

        int best = INF;
        for (int a = 0; a <= op1; a++)
            for (int b = 0; b <= op2; b++)
                best = min(best, dp[a][b]);
        return best;
    }
};
