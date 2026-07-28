// Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: sort jobs by end time. dp[i] = max profit using a subset of
// the first i jobs (sorted). dp[i] = max(dp[i-1] (skip job i), profit[i]
// + dp[j]) where j is the number of jobs (via binary search on end
// times) that finish at or before job i's start time.
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return endTime[a] < endTime[b]; });

        vector<int> sortedEnd(n);
        for (int i = 0; i < n; i++) sortedEnd[i] = endTime[idx[i]];

        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int job = idx[i - 1];
            int s = startTime[job], p = profit[job];
            int lo = 0, hi = i - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (sortedEnd[mid - 1] <= s) lo = mid;
                else hi = mid - 1;
            }
            dp[i] = max(dp[i - 1], dp[lo] + p);
        }
        return (int)dp[n];
    }
};
