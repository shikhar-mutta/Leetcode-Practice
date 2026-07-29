// Link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^3), SC: O(N^2)
// Approach: precompute cost[i][j] = min edits to make s[i..j] a semi-palindrome, trying every
// divisor d < length of that segment (splitting into d residue-class subsequences, each of
// which must itself be a palindrome — count mismatches per subsequence). Then a standard
// partition DP: dp[i][p] = min cost to split s[0:i] into p semi-palindromes.
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                if (len == 1) { cost[i][j] = 0; continue; }
                int best = INT_MAX;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int groupSize = len / d;
                    int mismatches = 0;
                    for (int r = 0; r < d; r++) {
                        int l = 0, h = groupSize - 1;
                        while (l < h) {
                            char cl = s[i + r + l*d], ch = s[i + r + h*d];
                            if (cl != ch) mismatches++;
                            l++; h--;
                        }
                    }
                    best = min(best, mismatches);
                }
                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int p = 1; p <= k; p++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j][p-1] == INT_MAX) continue;
                    int segCost = cost[j][i-1];
                    if (segCost == INT_MAX) continue;
                    dp[i][p] = min(dp[i][p], dp[j][p-1] + segCost);
                }
            }
        }
        return dp[n][k];
    }
};
