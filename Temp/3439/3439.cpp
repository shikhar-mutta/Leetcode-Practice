// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1);
        gaps[0] = startTime[0];
        for (int i = 1; i < n; i++) gaps[i] = startTime[i] - endTime[i-1];
        gaps[n] = eventTime - endTime[n-1];

        int windowSize = k + 1;
        long long cur = 0;
        for (int i = 0; i < windowSize; i++) cur += gaps[i];
        long long best = cur;
        for (int i = windowSize; i <= n; i++) {
            cur += gaps[i] - gaps[i - windowSize];
            best = max(best, cur);
        }
        return (int)best;
    }
};
