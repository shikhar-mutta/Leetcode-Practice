// Link: https://leetcode.com/problems/selling-pieces-of-wood/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(M*N*(M+N)), SC: O(M*N)
// Approach: dp[h][w] = best profit for h x w piece: either sell whole (price if given) or
// best over all horizontal/vertical cuts summing two sub-pieces.
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> price(m+1, vector<long long>(n+1, 0));
        for (auto& p : prices) price[p[0]][p[1]] = p[2];

        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for (int h = 1; h <= m; h++) {
            for (int w = 1; w <= n; w++) {
                long long best = price[h][w];
                for (int i = 1; i < h; i++) best = max(best, dp[i][w] + dp[h-i][w]);
                for (int j = 1; j < w; j++) best = max(best, dp[h][j] + dp[h][w-j]);
                dp[h][w] = best;
            }
        }
        return dp[m][n];
    }
};
