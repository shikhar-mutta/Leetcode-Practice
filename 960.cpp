// Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * m)  n=#columns, m=#rows  SC: O(n)
// Approach: this reduces to finding the longest subsequence of columns
// such that every row is non-decreasing across the kept columns (an
// LIS-style DP). dp[j] = length of the best such subsequence ending at
// column j; dp[j] = max(dp[i]+1) over i<j where column i <= column j in
// every row. Deletions needed = totalColumns - longest subsequence.
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        vector<int> dp(n, 1);
        int best = 1;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                bool valid = true;
                for (int r = 0; r < m; r++) {
                    if (strs[r][i] > strs[r][j]) { valid = false; break; }
                }
                if (valid) dp[j] = max(dp[j], dp[i] + 1);
            }
            best = max(best, dp[j]);
        }
        return n - best;
    }
};
