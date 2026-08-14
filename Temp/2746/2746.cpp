// Link: https://leetcode.com/problems/decremental-string-concatenation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        // dp[f][b] = min length with current front char f, back char b
        vector<vector<int>> dp(26, vector<int>(26, INT_MAX));
        char f0 = words[0][0], b0 = words[0].back();
        dp[f0-'a'][b0-'a'] = words[0].size();

        for (int i = 1; i < n; i++) {
            char wf = words[i][0], wb = words[i].back();
            int wlen = words[i].size();
            vector<vector<int>> ndp(26, vector<int>(26, INT_MAX));

            for (int f = 0; f < 26; f++) {
                for (int b = 0; b < 26; b++) {
                    if (dp[f][b] == INT_MAX) continue;
                    int curLen = dp[f][b];

                    // append word to the back: new back = wb, merge if b == wf
                    int newLen1 = curLen + wlen - (b == (wf-'a') ? 1 : 0);
                    if (newLen1 < ndp[f][wb-'a']) ndp[f][wb-'a'] = newLen1;

                    // prepend word to the front: new front = wf, merge if wb == f
                    int newLen2 = curLen + wlen - ((wb-'a') == f ? 1 : 0);
                    if (newLen2 < ndp[wf-'a'][b]) ndp[wf-'a'][b] = newLen2;
                }
            }
            dp = ndp;
        }

        int best = INT_MAX;
        for (int f = 0; f < 26; f++)
            for (int b = 0; b < 26; b++)
                best = min(best, dp[f][b]);
        return best;
    }
};
