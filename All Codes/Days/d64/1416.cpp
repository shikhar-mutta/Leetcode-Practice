// Link: https://leetcode.com/problems/restore-the-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * log10(k))  SC: O(n)
// Approach: dp[i] = number of ways to split s[0..i) into valid array
// elements. For each end position i, look back up to 10 digits (since
// k <= 10^9 bounds segment length) for a start j where s[j..i) has no
// leading zero and its numeric value <= k, adding dp[j], all mod 1e9+7.
class Solution {
public:
    int numberOfArrays(string s, int k) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int len = 1; len <= 10 && len <= i; len++) {
                int j = i - len;
                if (s[j] == '0') continue;
                long long val = 0;
                bool tooBig = false;
                for (int t = j; t < i; t++) {
                    val = val * 10 + (s[t] - '0');
                    if (val > k) { tooBig = true; break; }
                }
                if (tooBig || val > k) continue;
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
        return (int)dp[n];
    }
};
