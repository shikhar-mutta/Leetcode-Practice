// Link: https://leetcode.com/problems/perfect-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: the rectangles tile a perfect rectangle iff (1) total area
// equals the bounding box area and (2) every corner point is shared by
// an even number of rectangles except the 4 bounding-box corners, which
// appear exactly once — tracked via a toggling set of corner points.
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long minX = LLONG_MAX, minY = LLONG_MAX, maxX = LLONG_MIN, maxY = LLONG_MIN;
        long long area = 0;
        set<pair<int,int>> corners;
        for (auto& r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            minX = min(minX, (long long)x1); minY = min(minY, (long long)y1);
            maxX = max(maxX, (long long)x2); maxY = max(maxY, (long long)y2);
            area += (long long)(x2 - x1) * (y2 - y1);
            pair<int,int> pts[4] = {{x1,y1},{x1,y2},{x2,y1},{x2,y2}};
            for (auto& p : pts) {
                if (corners.count(p)) corners.erase(p);
                else corners.insert(p);
            }
        }
        if (area != (maxX - minX) * (maxY - minY)) return false;
        if (corners.size() != 4) return false;
        set<pair<int,int>> expected = {{(int)minX,(int)minY},{(int)minX,(int)maxY},{(int)maxX,(int)minY},{(int)maxX,(int)maxY}};
        return corners == expected;
    }
};
