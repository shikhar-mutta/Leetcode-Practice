// Link: https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) addNum, O(n) getIntervals  SC: O(n)
// Approach: ordered map start->end; find neighbor interval that can merge
// with the new value on either side, extend or insert a new singleton
class SummaryRanges {
    map<int, int> intervals; // start -> end

public:
    SummaryRanges() {}

    void addNum(int value) {
        auto it = intervals.upper_bound(value);
        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= value) return; // already covered
            if (prev->second == value - 1) {
                prev->second++;
                if (it != intervals.end() && it->first == value + 1) {
                    prev->second = it->second;
                    intervals.erase(it);
                }
                return;
            }
        }
        if (it != intervals.end() && it->first == value + 1) {
            intervals[value] = it->second;
            intervals.erase(it);
            return;
        }
        intervals[value] = value;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& [s, e] : intervals) res.push_back({s, e});
        return res;
    }
};
