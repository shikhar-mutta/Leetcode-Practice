// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N^2)
// Approach: precompute isPalin[l][r]. dp[i] = max disjoint valid (len>=k) palindromes in s[0:i].
// Greedy: for each start l, only need to test the two shortest possible valid lengths (k, k+1) —
// taking the shortest valid palindrome ending as early as possible is always optimal.
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) isPalin[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (s[l] != s[r]) continue;
                isPalin[l][r] = (len == 2) || isPalin[l+1][r-1];
            }
        }

        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            for (int len = k; len <= k+1; len++) {
                int l = i - len;
                if (l < 0) continue;
                if (isPalin[l][i-1]) {
                    dp[i] = max(dp[i], dp[l] + 1);
                    break;
                }
            }
        }
        return dp[n];
    }
};
