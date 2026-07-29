// Link: https://leetcode.com/problems/maximum-deletions-on-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N^2)
// Approach: lcp[i][j] = longest common prefix of s[i:] and s[j:] via DP from the back.
// dp[i] = max deletions starting at i = 1 + best dp[i+L] over lengths L where s[i:i+L]==s[i+L:i+2L].
class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector<vector<int>> lcp(n+1, vector<int>(n+1, 0));
        for (int i = n-1; i >= 0; i--)
            for (int j = n-1; j >= 0; j--)
                lcp[i][j] = (s[i] == s[j]) ? lcp[i+1][j+1] + 1 : 0;

        vector<int> dp(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            int best = 1;
            for (int L = 1; i + 2*L <= n; L++) {
                if (lcp[i][i+L] >= L) best = max(best, 1 + dp[i+L]);
            }
            dp[i] = best;
        }
        return dp[0];
    }
};
