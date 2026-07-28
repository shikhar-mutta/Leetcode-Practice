// Link: https://leetcode.com/problems/count-integers-in-intervals/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: amortized O(log n) per add (each merge removes an interval)  SC: O(n)
// Approach: maintain a set of disjoint intervals keyed by right endpoint.
// On add(l,r): repeatedly find overlapping/adjacent intervals, merge them
// into [l,r], subtracting their length from the running total, then insert
// the merged interval and add its length back.
class CountIntervals {
    set<pair<int,int>> intervals; // (right, left)
    long long total = 0;
public:
    CountIntervals() {}

    void add(int left, int right) {
        auto it = intervals.lower_bound({left, INT_MIN});
        while (it != intervals.end() && it->second <= right + 1) {
            int r = it->first, l = it->second;
            if (l > right + 1) break;
            left = min(left, l);
            right = max(right, r);
            total -= (r - l + 1);
            it = intervals.erase(it);
        }
        intervals.insert({right, left});
        total += (right - left + 1);
    }

    int count() {
        return (int)total;
    }
};
