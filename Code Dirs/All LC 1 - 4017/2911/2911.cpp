// Link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;
                int best = INT_MAX;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int c = 0;
                    for (int start = 0; start < d; start++) {
                        vector<int> pos;
                        for (int idx = l + start; idx <= r; idx += d) pos.push_back(idx);
                        int a = 0, b = (int)pos.size() - 1;
                        while (a < b) {
                            if (s[pos[a]] != s[pos[b]]) c++;
                            a++; b--;
                        }
                    }
                    best = min(best, c);
                }
                cost[l][r] = best;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int m = j * 2 - 2; m <= i - 2; m++) {
                    if (m < 0 || dp[m][j-1] == INT_MAX) continue;
                    dp[i][j] = min(dp[i][j], dp[m][j-1] + cost[m][i-1]);
                }
            }
        }
        return dp[n][k];
    }
};
