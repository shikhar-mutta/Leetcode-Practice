// Link: https://leetcode.com/problems/maximum-number-of-visible-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int same = 0;
        vector<double> angles;
        for (auto& p : points) {
            int dx = p[0] - location[0], dy = p[1] - location[1];
            if (dx == 0 && dy == 0) { same++; continue; }
            angles.push_back(atan2(dy, dx) * 180.0 / acos(-1.0));
        }
        sort(angles.begin(), angles.end());
        int n = angles.size();
        for (int i = 0; i < n; i++) angles.push_back(angles[i] + 360.0);
        int best = 0, l = 0;
        for (int r = 0; r < (int)angles.size(); r++) {
            while (angles[r] - angles[l] > angle) l++;
            best = max(best, r - l + 1);
        }
        return min(best, n) + same;
    }
};
