// Link: https://leetcode.com/problems/range-module/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log n) amortized per op  SC: O(n) tracked ranges
// Approach: maintain a map<int,int> of disjoint half-open [start,end)
// covered ranges. addRange merges overlapping/touching neighbors into
// one span. removeRange trims/splits any overlapping ranges. queryRange
// checks if a single covering range contains [left,right).
class RangeModule {
    map<int,int> ranges; // start -> end
public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = ranges.lower_bound(left);
        if (it != ranges.begin()) {
            auto prev_ = prev(it);
            if (prev_->second >= left) it = prev_;
        }
        while (it != ranges.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            it = ranges.erase(it);
        }
        ranges[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if (it == ranges.begin()) return false;
        it = prev(it);
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = ranges.lower_bound(left);
        if (it != ranges.begin()) {
            auto prev_ = prev(it);
            if (prev_->second > left) it = prev_;
        }
        vector<pair<int,int>> toAdd;
        while (it != ranges.end() && it->first < right) {
            int s = it->first, e = it->second;
            if (s < left) toAdd.push_back({s, left});
            if (e > right) toAdd.push_back({right, e});
            it = ranges.erase(it);
        }
        for (auto& [s, e] : toAdd) ranges[s] = e;
    }
};
