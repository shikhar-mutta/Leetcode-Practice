// Link: https://leetcode.com/problems/decode-ways-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: DP where dp[i] = ways to decode prefix of length i. For single-char ways, '*' contributes 9 (1-9), digit '0' contributes 0, others 1. For two-char ways, enumerate all valid combos for digit/digit, digit/*, */digit, */* pairs mapping to 1-26.
class Solution {
public:
    int numDecodings(string s) {
        const long long MOD = 1e9+7;
        int n = s.size();
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '*') ? 9 : (s[0] == '0' ? 0 : 1);
        for (int i = 2; i <= n; i++) {
            char c1 = s[i-2], c2 = s[i-1];
            long long oneDigit = 0;
            if (c2 == '*') oneDigit = 9;
            else if (c2 != '0') oneDigit = 1;
            long long twoDigit = 0;
            if (c1 == '*' && c2 == '*') twoDigit = 15; // 11-19,21-26
            else if (c1 == '*') {
                if (c2 <= '6') twoDigit = 2; // 1x,2x
                else twoDigit = 1; // 1x only
            } else if (c2 == '*') {
                if (c1 == '1') twoDigit = 9; // 11-19
                else if (c1 == '2') twoDigit = 6; // 21-26
                else twoDigit = 0;
            } else {
                int val = (c1-'0')*10 + (c2-'0');
                if (val >= 10 && val <= 26) twoDigit = 1;
            }
            dp[i] = (oneDigit * dp[i-1] + twoDigit * dp[i-2]) % MOD;
        }
        return (int)dp[n];
    }
};
