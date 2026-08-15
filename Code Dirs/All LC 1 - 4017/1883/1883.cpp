// Link: https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        const long long INF = 1e18;
        int n = dist.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> ndp(n + 1, INF);
            for (int j = 0; j <= i; j++) {
                if (dp[j] == INF) continue;
                long long t = dp[j] + dist[i];
                ndp[j + 1] = min(ndp[j + 1], t);
                long long rounded = ((t + speed - 1) / speed) * speed;
                ndp[j] = min(ndp[j], rounded);
            }
            dp = ndp;
        }
        long long limit = (long long)hoursBefore * speed;
        for (int j = 0; j <= n; j++) {
            if (dp[j] <= limit) return j;
        }
        return -1;
    }
};
