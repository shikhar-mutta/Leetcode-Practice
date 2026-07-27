// Link: https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k) SC: O(n^2 * k)
// Approach: interval DP dp[i][j][budget] = longest palindromic subsequence
// achievable from s[i..j] with at most `budget` total cyclic-shift
// operations. Either skip s[i] or s[j], or pair them together paying the
// cyclic letter distance between them (min of forward/backward distance
// on the 26-letter ring) and recurse inward with the reduced budget.
class Solution {
    vector<vector<vector<int>>> memo;
    string s;
    int solve(int i, int j, int budget) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (memo[i][j][budget] != -1) return memo[i][j][budget];

        int best = max(solve(i+1, j, budget), solve(i, j-1, budget));
        int d = abs(s[i] - s[j]);
        int dist = min(d, 26 - d);
        if (budget >= dist) best = max(best, 2 + solve(i+1, j-1, budget - dist));

        return memo[i][j][budget] = best;
    }
public:
    int longestPalindromicSubsequence(string str, int k) {
        s = str;
        int n = s.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solve(0, n - 1, k);
    }
};
