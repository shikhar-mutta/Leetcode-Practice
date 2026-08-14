// Link: https://leetcode.com/problems/maximum-earnings-from-taxi/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int,int>>> byEnd(n + 1);
        for (auto& r : rides) byEnd[r[1]].push_back({r[0], r[1] - r[0] + r[2]});
        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (auto& [start, earn] : byEnd[i]) {
                dp[i] = max(dp[i], dp[start] + earn);
            }
        }
        return dp[n];
    }
};
