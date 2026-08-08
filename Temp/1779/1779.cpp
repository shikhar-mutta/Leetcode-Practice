// Link: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int best = -1, bestDist = INT_MAX;
        for (int i = 0; i < (int)points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (dist < bestDist) { bestDist = dist; best = i; }
            }
        }
        return best;
    }
};
