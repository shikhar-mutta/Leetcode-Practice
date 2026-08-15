// Link: https://leetcode.com/problems/distinct-subsequences-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        vector<long long> last(26, -1);
        vector<long long> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= (int)s.size(); i++) {
            int c = s[i-1] - 'a';
            dp[i] = (dp[i-1] * 2) % MOD;
            if (last[c] != -1) dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            last[c] = i;
        }
        return (int)((dp[s.size()] - 1 + MOD) % MOD);
    }
};
