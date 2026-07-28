// Link: https://leetcode.com/problems/number-of-music-playlists/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * goal)  SC: O(n * goal)
// Approach: dp[i][j] = number of playlists of length i using exactly j
// distinct songs. Transition: either play a brand-new song (n-(j-1)
// choices from dp[i-1][j-1]), or replay an already-used song that isn't
// among the last k played (j-k choices, valid only if j>k), from
// dp[i-1][j].
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                long long val = dp[i - 1][j - 1] * (n - (j - 1)) % MOD;
                if (j > k) val = (val + dp[i - 1][j] * (j - k)) % MOD;
                dp[i][j] = val;
            }
        }
        return (int)dp[goal][n];
    }
};
