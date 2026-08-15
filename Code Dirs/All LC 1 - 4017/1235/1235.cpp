// Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return endTime[a] < endTime[b]; });
        vector<int> ends(n);
        for (int i = 0; i < n; i++) ends[i] = endTime[idx[i]];
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int s = startTime[idx[i-1]], p = profit[idx[i-1]];
            int j = upper_bound(ends.begin(), ends.begin()+(i-1), s) - ends.begin();
            dp[i] = max(dp[i-1], dp[j] + p);
        }
        return dp[n];
    }
};
