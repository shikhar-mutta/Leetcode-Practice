// Link: https://leetcode.com/problems/distinct-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)  SC: O(m)
// Approach: DP over t's length; dp[j] = ways to form t[0..j) using s so far, update right-to-left per char of s
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) dp[j+1] += dp[j];
            }
        }
        return (int)dp[m];
    }
};
