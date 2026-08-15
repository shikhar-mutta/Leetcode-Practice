// Link: https://leetcode.com/problems/restore-the-array/description/

#include <bits/stdc++.h>
using namespace std;

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
                string sub = s.substr(j, len);
                if (sub.size() > 10) continue;
                long long num = stoll(sub);
                if (num > k) continue;
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
        return (int)dp[n];
    }
};
