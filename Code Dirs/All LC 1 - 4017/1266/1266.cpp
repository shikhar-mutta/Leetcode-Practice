// Link: https://leetcode.com/problems/minimum-time-visiting-all-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total = 0;
        for (int i = 1; i < (int)points.size(); i++) {
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);
            total += max(dx, dy);
        }
        return total;
    }
};
