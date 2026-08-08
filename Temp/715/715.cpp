// Link: https://leetcode.com/problems/range-module/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) amortized per op SC: O(n)
// Approach: maintain a map of non-overlapping intervals keyed by start. addRange merges overlapping/adjacent intervals; removeRange splits intervals that partially overlap; queryRange checks the interval whose start <= left covers [left,right).
class RangeModule {
    map<int,int> ranges; // start -> end
public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if (it != ranges.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= left) { left = min(left, prev->first); right = max(right, prev->second); it = ranges.erase(prev); }
        }
        while (it != ranges.end() && it->first <= right) {
            right = max(right, it->second);
            it = ranges.erase(it);
        }
        ranges[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if (it == ranges.begin()) return false;
        --it;
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if (it != ranges.begin()) {
            auto prev = std::prev(it);
            if (prev->second > left) {
                int oldEnd = prev->second;
                if (prev->first < left) prev->second = left;
                else ranges.erase(prev);
                if (oldEnd > right) ranges[right] = oldEnd;
            }
        }
        it = ranges.lower_bound(left);
        while (it != ranges.end() && it->first < right) {
            int oldEnd = it->second;
            it = ranges.erase(it);
            if (oldEnd > right) { ranges[right] = oldEnd; break; }
        }
    }
};
