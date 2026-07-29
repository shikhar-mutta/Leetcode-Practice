// Link: https://leetcode.com/problems/inverse-coin-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> coins;

        for (int a = 1; a <= n; a++) {
            long long target = numWays[a-1];
            if (dp[a] == target) {
                continue;
            } else if (dp[a] + 1 == target) {
                coins.push_back(a);
                for (int j = a; j <= n; j++) dp[j] += dp[j-a];
            } else {
                return {};
            }
        }

        return coins;
    }
};
