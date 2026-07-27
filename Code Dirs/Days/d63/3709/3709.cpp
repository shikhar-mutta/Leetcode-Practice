// Link: https://leetcode.com/problems/design-exam-scores-tracker/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per record, O(log n) per query SC: O(n)
// Approach: since record() is always called with strictly increasing
// time, just append (time, running cumulative sum) pairs to a vector.
// A range-sum query then becomes two binary searches on time to find
// the cumulative sum boundaries, subtracted.
class ExamTracker {
    vector<int> times;
    vector<long long> cum;
public:
    ExamTracker() {}

    void record(int time, int score) {
        long long prev = cum.empty() ? 0 : cum.back();
        times.push_back(time);
        cum.push_back(prev + score);
    }

    long long totalScore(int startTime, int endTime) {
        int hi = upper_bound(times.begin(), times.end(), endTime) - times.begin();
        int lo = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        long long sumUpToEnd = (hi > 0) ? cum[hi - 1] : 0;
        long long sumBeforeStart = (lo > 0) ? cum[lo - 1] : 0;
        return sumUpToEnd - sumBeforeStart;
    }
};
