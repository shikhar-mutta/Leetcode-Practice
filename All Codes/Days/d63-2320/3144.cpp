// Link: https://leetcode.com/problems/minimum-substring-partition-of-equal-character-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n)
// Approach: dp[i] = min partitions for prefix of length i. For each i, scan
// j backward from i-1, maintaining running char frequencies for s[j..i-1];
// that substring has "equal character frequency" iff maxFreq * distinctChars
// equals its length, in which case dp[i] = min(dp[i], dp[j]+1).
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int freq[26] = {0};
            int max_f = 0;
            int unique = 0;

            for (int j = i - 1; j >= 0; --j) {
                int c = s[j] - 'a';
                if (freq[c] == 0) {
                    unique++;
                }
                freq[c]++;
                if (freq[c] > max_f) {
                    max_f = freq[c];
                }

                if (max_f * unique == i - j) {
                    if (dp[j] + 1 < dp[i]) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        return dp[n];
    }
};
