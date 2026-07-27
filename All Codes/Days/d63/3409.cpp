// Link: https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * maxVal) SC: O(maxVal^2)
// Approach: value-indexed DP. dp[v][d] = longest subsequence ending in
// value v whose last adjacent difference is exactly d; suf[v][d] is the
// suffix max of dp[v][*] over diffs >= d (since the next diff must be
// <= the previous one). For each new element x, try extending from
// suf[x-d][d] and suf[x+d][d] for every candidate diff d, then merge the
// results back into dp[x]/suf[x].
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        const int MX = 301;
        vector<vector<int>> dp(MX, vector<int>(MX, 0));
        vector<vector<int>> suf(MX, vector<int>(MX + 1, 0));

        int ans = 1;
        for (int x : nums) {
            vector<int> newBest(MX, 1);
            for (int d = 0; d < MX; d++) {
                if (x - d >= 0) newBest[d] = max(newBest[d], suf[x-d][d] + 1);
                if (x + d < MX) newBest[d] = max(newBest[d], suf[x+d][d] + 1);
                ans = max(ans, newBest[d]);
            }
            for (int d = 0; d < MX; d++) dp[x][d] = max(dp[x][d], newBest[d]);
            for (int d = MX - 1; d >= 0; d--) suf[x][d] = max(dp[x][d], suf[x][d+1]);
        }
        return ans;
    }
};
