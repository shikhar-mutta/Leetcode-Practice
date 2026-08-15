// Link: https://leetcode.com/problems/longest-ideal-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int best = 0;
        for (char ch : s) {
            int c = ch - 'a';
            int lo = max(0, c - k), hi = min(25, c + k);
            int m = 0;
            for (int i = lo; i <= hi; i++) m = max(m, dp[i]);
            dp[c] = m + 1;
            best = max(best, dp[c]);
        }
        return best;
    }
};
