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
            angles.push_back(atan2(dy, dx) * 180.0 / M_PI);
        }
        sort(angles.begin(), angles.end());
        int n = angles.size();
        for (int i = 0; i < n; i++) angles.push_back(angles[i] + 360.0);

        int best = 0, left = 0;
        for (int right = 0; right < (int)angles.size(); right++) {
            while (angles[right] - angles[left] > angle) left++;
            best = max(best, right - left + 1);
        }
        return best + same;
    }
};
