// Link: https://leetcode.com/problems/new-21-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts - 1) return 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double wSum = 1.0, ans = 0.0;
        for (int x = 1; x <= n; x++) {
            dp[x] = wSum / maxPts;
            if (x < k) wSum += dp[x];
            else ans += dp[x];
            if (x - maxPts >= 0 && x - maxPts < k) wSum -= dp[x - maxPts];
        }
        return ans;
    }
};
