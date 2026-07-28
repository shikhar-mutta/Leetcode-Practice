// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = events[i][0];
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            int nxt = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();
            for (int j = 1; j <= k; j++) {
                int skip = dp[i+1][j];
                int take = events[i][2] + dp[nxt][j-1];
                dp[i][j] = max(skip, take);
            }
        }
        return dp[0][k];
    }
};
