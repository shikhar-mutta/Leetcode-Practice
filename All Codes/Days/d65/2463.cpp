// Link: https://leetcode.com/problems/minimum-total-distance-traveled/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(M*N^2), SC: O(N)
// Approach: sort robots and factories by position (optimal assignment never crosses). dp[i] = min
// cost to assign the first i (sorted) robots using factories processed so far; for each factory,
// try assigning its last k robots (k up to its limit) contiguously ending at position i.
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();
        const long long INF = LLONG_MAX / 2;
        vector<long long> dp(n+1, INF);
        dp[0] = 0;

        for (auto& f : factory) {
            long long pos = f[0];
            int limit = f[1];
            vector<long long> ndp = dp;
            for (int i = 1; i <= n; i++) {
                long long cost = 0;
                for (int k = 1; k <= min(limit, i); k++) {
                    cost += abs(robot[i-k] - pos);
                    if (dp[i-k] < INF) ndp[i] = min(ndp[i], dp[i-k] + cost);
                }
            }
            dp = ndp;
        }
        return dp[n];
    }
};
