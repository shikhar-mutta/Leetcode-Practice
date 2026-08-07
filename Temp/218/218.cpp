// Link: https://leetcode.com/problems/the-skyline-problem/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: sweep-line over building start/end events sorted by x (start events use -height to sort
// before end events at the same x, and to process taller buildings first); a multiset tracks active
// heights, emitting a key point whenever the current max height changes
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<tuple<int,int,int>> events; // x, -height (start) or height (end),
        for (auto& b : buildings) {
            events.push_back({b[0], -b[2], b[1]});
            events.push_back({b[1], b[2], 0});
        }
        sort(events.begin(), events.end());
        multiset<int> heights = {0};
        int prevMax = 0;
        vector<vector<int>> res;
        for (auto& [x, h, end] : events) {
            if (h < 0) heights.insert(-h);
            else heights.erase(heights.find(h));
            int curMax = *heights.rbegin();
            if (curMax != prevMax) {
                res.push_back({x, curMax});
                prevMax = curMax;
            }
        }
        return res;
    }
};
