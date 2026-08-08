// Link: https://leetcode.com/problems/number-of-music-playlists/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= goal; j++) {
                dp[i][j] = dp[i-1][j-1] * (n - i + 1) % MOD;
                if (i > k) dp[i][j] = (dp[i][j] + dp[i][j-1] * (i - k)) % MOD;
            }
        }
        return (int)dp[n][goal];
    }
};
