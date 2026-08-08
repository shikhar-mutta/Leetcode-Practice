// Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        long long dx = xCenter - closestX, dy = yCenter - closestY;
        return dx * dx + dy * dy <= (long long)radius * radius;
    }
};
