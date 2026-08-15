// Link: https://leetcode.com/problems/encode-string-with-shortest-length/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)  SC: O(n^2)
// Approach: interval DP - dp[i][j] = shortest encoding of s[i..j]; try
// every split point to combine two shorter encodings, and check if the
// whole substring is itself a repeated pattern to encode as k[...]
class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                string sub = s.substr(i, len);
                dp[i][j] = sub;

                for (int k = i; k < j; k++) {
                    if (dp[i][k].size() + dp[k+1][j].size() < dp[i][j].size()) {
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                    }
                }

                // check if sub can be built by repeating a substring
                string doubled = sub + sub;
                int pos = doubled.find(sub, 1);
                if (pos < len) {
                    string pattern = sub.substr(0, pos);
                    string candidate = to_string(len / pos) + "[" + dp[i][i + pos - 1] + "]";
                    if (candidate.size() < dp[i][j].size()) dp[i][j] = candidate;
                }
            }
        }
        return n ? dp[0][n-1] : "";
    }
};
