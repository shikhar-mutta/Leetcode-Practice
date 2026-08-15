// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            int nextIdx = lower_bound(events.begin(), events.end(), vector<int>{events[i][1] + 1, -1, -1}) - events.begin();
            for (int j = 1; j <= k; j++) {
                int take = events[i][2] + dp[nextIdx][j-1];
                int skip = dp[i+1][j];
                dp[i][j] = max(take, skip);
            }
        }
        return dp[0][k];
    }
};
