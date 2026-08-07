// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
// Approach: sort by end, greedily shoot at the end of each new
// non-overlapping balloon
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int arrows = 0;
        long long lastShot = LLONG_MIN;
        for (auto& p : points) {
            if (p[0] > lastShot) {
                arrows++;
                lastShot = p[1];
            }
        }
        return arrows;
    }
};
