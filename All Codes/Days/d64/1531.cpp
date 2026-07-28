// Link: https://leetcode.com/problems/string-compression-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        auto lenOf = [](int cnt) {
            if (cnt <= 1) return cnt;
            if (cnt < 10) return 2;
            if (cnt < 100) return 3;
            return 4;
        };
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]); // delete s[i-1]
                int cnt = 0, del = 0;
                for (int p = i; p >= 1; p--) {
                    if (s[p-1] == s[i-1]) cnt++;
                    else del++;
                    if (del > j) break;
                    dp[i][j] = min(dp[i][j], dp[p-1][j-del] + lenOf(cnt));
                }
            }
        }
        return dp[n][k];
    }
};
