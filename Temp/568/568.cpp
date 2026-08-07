// Link: https://leetcode.com/problems/maximum-vacation-days/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k)  SC: O(n)
// Approach: DP over weeks; dp[city] = max vacation days achievable while
// currently in that city after processing week w; transition to any
// reachable city (flight or stay) each week
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        vector<int> dp(n, INT_MIN);
        dp[0] = days[0][0];
        for (int city = 1; city < n; city++) {
            if (flights[0][city]) dp[city] = days[city][0];
        }

        for (int week = 1; week < k; week++) {
            vector<int> ndp(n, INT_MIN);
            for (int cur = 0; cur < n; cur++) {
                if (dp[cur] == INT_MIN) continue;
                // stay in cur
                ndp[cur] = max(ndp[cur], dp[cur] + days[cur][week]);
                // fly to dest
                for (int dest = 0; dest < n; dest++) {
                    if (flights[cur][dest]) {
                        ndp[dest] = max(ndp[dest], dp[cur] + days[dest][week]);
                    }
                }
            }
            dp = ndp;
        }

        int best = 0;
        for (int c : dp) best = max(best, c);
        return best;
    }
};
