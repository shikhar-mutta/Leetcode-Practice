// Link: https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string str;
    vector<vector<vector<int>>> memo;

    int solve(int i, int j, int budget) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (memo[i][j][budget] != -1) return memo[i][j][budget];
        int best = max(solve(i+1, j, budget), solve(i, j-1, budget));
        int diff = abs(str[i] - str[j]);
        int cost = min(diff, 26 - diff);
        if (cost <= budget) {
            int inner = (i+1 <= j-1) ? solve(i+1, j-1, budget - cost) : 0;
            best = max(best, 2 + inner);
        }
        return memo[i][j][budget] = best;
    }

    int longestPalindromicSubsequence(string s, int k) {
        str = s;
        int n = s.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return solve(0, n-1, k);
    }
};
