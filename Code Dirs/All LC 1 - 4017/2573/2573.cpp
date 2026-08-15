// Link: https://leetcode.com/problems/find-the-string-with-lcp/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, 0);
        int ch = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != 0) continue;
            if (ch >= 26) return "";
            s[i] = 'a' + ch;
            ch++;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    if (s[j] != 0) return "";
                    s[j] = s[i];
                }
            }
        }

        // verify lcp[i][j] == 0 for mismatched chars that weren't set via propagation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] != s[j] && lcp[i][j] != 0) return "";
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = 0;
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }

        return s;
    }
};
