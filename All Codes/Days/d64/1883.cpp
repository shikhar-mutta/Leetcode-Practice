// Link: https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n)
// Approach: track time scaled by speed (integer arithmetic, avoids floating
// point). dp[j] = min scaled-time using j skips so far. Without a skip, round
// up to the next whole hour (ceil to multiple of speed) before adding the next
// road; with a skip, add distance directly without rounding.
class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        long long INF = LLONG_MAX / 2;
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> ndp(n + 1, INF);
            for (int j = 0; j <= i; j++) {
                if (dp[j] == INF) continue;
                // no skip: round up to multiple of speed, then add dist
                long long rounded = ((dp[j] + speed - 1) / speed) * speed;
                ndp[j] = min(ndp[j], rounded + dist[i]);
                // skip: no rounding
                ndp[j+1] = min(ndp[j+1], dp[j] + dist[i]);
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
