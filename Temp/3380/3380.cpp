// Link: https://leetcode.com/problems/maximum-area-rectangle-with-point-constraints-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        set<pair<int,int>> pointSet;
        for (auto& p : points) pointSet.insert({p[0], p[1]});

        int best = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) continue;
                int lo_x = min(x1, x2), hi_x = max(x1, x2);
                int lo_y = min(y1, y2), hi_y = max(y1, y2);
                if (!pointSet.count({lo_x, lo_y}) || !pointSet.count({lo_x, hi_y}) ||
                    !pointSet.count({hi_x, lo_y}) || !pointSet.count({hi_x, hi_y})) continue;

                bool hasInner = false;
                for (int k = 0; k < n && !hasInner; k++) {
                    int px = points[k][0], py = points[k][1];
                    if (px == lo_x && (py == lo_y || py == hi_y)) continue;
                    if (px == hi_x && (py == lo_y || py == hi_y)) continue;
                    if (px >= lo_x && px <= hi_x && py >= lo_y && py <= hi_y) hasInner = true;
                }
                if (!hasInner) {
                    int area = (hi_x - lo_x) * (hi_y - lo_y);
                    best = max(best, area);
                }
            }
        }
        return best;
    }
};
