// Link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) pick, O(n) construct  SC: O(n)
// Approach: weight each rectangle by its point count (area+perimeter-ish:
// (x2-x1+1)*(y2-y1+1)), build prefix sums, binary search a weighted random
// pick, then uniformly sample a point inside the chosen rectangle
class Solution {
    vector<vector<int>> rects;
    vector<long long> prefix;

public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        long long sum = 0;
        for (auto& r : rects) {
            sum += (long long)(r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            prefix.push_back(sum);
        }
    }

    vector<int> pick() {
        long long target = (long long)(((double)rand() / RAND_MAX) * prefix.back());
        int idx = upper_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
        auto& r = rects[idx];
        int x = r[0] + rand() % (r[2] - r[0] + 1);
        int y = r[1] + rand() % (r[3] - r[1] + 1);
        return {x, y};
    }
};
