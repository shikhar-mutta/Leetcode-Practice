// Link: https://leetcode.com/problems/design-exam-scores-tracker/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per record, O(log n) per query SC: O(n)
//  Approach: since record() is always called with strictly increasing
//  time, just append (time, running cumulative sum) pairs to a vector.
//  A range-sum query then becomes two binary searches on time to find
//  the cumulative sum boundaries, subtracted.
class ExamTracker
{
public:
    vector<pair<int, int>> exams;
    vector<long long> prefix, clock;
    ExamTracker()
    {
        prefix.push_back(0);
        clock.push_back(0);
    }

    void record(int time, int score)
    {
        exams.push_back({time, score});
        clock.push_back(time);
        if (prefix.empty())
        {
            prefix.push_back(score);
        }
        else
        {
            prefix.push_back(prefix.back() + score);
        }
    }

    // long long bs(int tar){
    //     auto it = lower_bound(clock.begin(), clock.end(), tar);
    //     if(it==clock.end()){
    //         return 0;
    //     }
    // }
    long long retrieve(int st, int et)
    {
        long long ans = 0;

        auto it = lower_bound(clock.begin(), clock.end(), st - 1);
        if (*it >= st)
        {
            it--;
        }
        auto ir = lower_bound(clock.begin(), clock.end(), et);
        if (*ir > et)
        {
            ir--;
        }

        return prefix[ir - clock.begin()] - prefix[it - clock.begin()];
    }
    long long totalScore(int st, int et)
    {
        return retrieve(st, et);
    }
};