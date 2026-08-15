// Link: https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)  SC: O(n^2)
// Approach: interval DP - dp[l][r] = min cost to guarantee win in range
// [l,r], trying every pivot guess x and taking the worst-case branch
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                int best = INT_MAX;
                for (int x = l; x <= r; x++) {
                    int left = x > l ? dp[l][x - 1] : 0;
                    int right = x < r ? dp[x + 1][r] : 0;
                    int cost = x + max(left, right);
                    best = min(best, cost);
                }
                dp[l][r] = best;
            }
        }
        return dp[1][n];
    }
};
