// Link: https://leetcode.com/problems/minimum-substring-partition-of-equal-character-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0, maxF = 0;
            for (int j = i - 1; j >= 0; j--) {
                int c = s[j] - 'a';
                if (freq[c] == 0) distinct++;
                freq[c]++;
                maxF = max(maxF, freq[c]);
                int len = i - j;
                if (maxF * distinct == len && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};
