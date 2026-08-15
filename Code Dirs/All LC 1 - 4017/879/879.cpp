// Link: https://leetcode.com/problems/profitable-schemes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        int m = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        for (int members = 0; members <= n; members++) dp[members][0] = 1;

        for (int i = 0; i < m; i++) {
            int g = group[i], p = profit[i];
            for (int members = n; members >= g; members--) {
                for (int prof = minProfit; prof >= 0; prof--) {
                    int newProf = max(0, prof - p);
                    dp[members][prof] = (dp[members][prof] + dp[members - g][newProf]) % MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};
