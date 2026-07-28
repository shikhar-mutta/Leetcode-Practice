// Link: https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * numCarpets)  SC: O(n * numCarpets)
// Approach: dp[i][j] = min visible white tiles among floor[0..i-1] using
// at most j carpets. Transition: either leave floor[i-1] uncovered
// (dp[i-1][j] + isWhite(i-1)), or place a carpet ending at i-1
// (dp[max(0,i-carpetLen)][j-1]).
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1, 0));
        for (int i = 1; i <= n; i++) {
            int w = floor[i-1] - '0';
            for (int j = 0; j <= numCarpets; j++) {
                dp[i][j] = dp[i-1][j] + w;
                if (j > 0) {
                    int prevIdx = max(0, i - carpetLen);
                    dp[i][j] = min(dp[i][j], dp[prevIdx][j-1]);
                }
            }
        }
        return dp[n][numCarpets];
    }
};
