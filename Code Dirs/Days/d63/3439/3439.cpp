// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: build the array of n+1 free gaps around/between meetings.
// Moving k meetings out of a block of (k+1) consecutive gaps merges those
// gaps into one contiguous free span (the moved meetings can always be
// repacked elsewhere in the remaining slack), so the answer is just the
// max sliding-window sum of any (k+1) consecutive gaps.
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
