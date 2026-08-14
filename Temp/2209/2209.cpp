// Link: https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1, 0));
        for (int i = 1; i <= n; i++) {
            int tile = (floor[i - 1] == '1') ? 1 : 0;
            for (int j = 0; j <= numCarpets; j++) {
                dp[i][j] = dp[i - 1][j] + tile;
                if (j > 0) {
                    int prev = max(0, i - carpetLen);
                    dp[i][j] = min(dp[i][j], dp[prev][j - 1]);
                }
            }
        }
        return dp[n][numCarpets];
    }
};
