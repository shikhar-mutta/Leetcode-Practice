// Link: https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) for addNum, O(n) for getIntervals
// SC: O(n) for storing the intervals
// Approach:
//  1. We use a map to store the intervals, where the key is the start of the interval and the value is the end of the interval.
//  2. When adding a new number, we check if it can be merged with the previous or next interval. If it can, we merge it, otherwise we create a new interval.
//  3. The getIntervals function simply returns the current intervals in the map as a vector of vectors.
class SummaryRanges
{
public:
    SummaryRanges() {}

    void addNum(int value)
    {
        if (intervals.empty())
        {
            intervals[value] = value;
            return;
        }

        auto it = intervals.upper_bound(value);
        if (it != intervals.begin())
        {
            auto prev = std::prev(it);
            if (prev->second >= value)
                return;
            if (prev->second == value - 1)
            {
                prev->second = value;
                if (it != intervals.end() && it->first == value + 1)
                {
                    prev->second = it->second;
                    intervals.erase(it);
                }
                return;
            }
        }
        if (it != intervals.end() && it->first == value + 1)
        {
            intervals[value] = it->second;
            intervals.erase(it);
            return;
        }
        intervals[value] = value;
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> res;
        for (auto &p : intervals)
            res.push_back({p.first, p.second});
        return res;
    }

private:
    map<int, int> intervals;
};
