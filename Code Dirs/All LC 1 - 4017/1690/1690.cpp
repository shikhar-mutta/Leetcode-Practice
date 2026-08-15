// Link: https://leetcode.com/problems/stone-game-vii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int sum = prefix[j+1] - prefix[i];
                dp[i][j] = max(sum - stones[i] - dp[i+1][j], sum - stones[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
