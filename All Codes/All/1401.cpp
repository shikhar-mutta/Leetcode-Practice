// Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    //  Approach:
    //   1. The idea is to find the closest point on the rectangle to the center of the circle. This is done by clamping the x and y coordinates of the circle's center to the bounds of the rectangle.
    //   2. Once we have the closest point (cx, cy), we calculate the distance from this point to the center of the circle (xCenter, yCenter).
    //   3. If this distance is less than or equal to the radius of the circle, then the circle and rectangle overlap. Otherwise, they do not.
    //   4. The distance is calculated using the formula: distance^2 = (xCenter - cx)^2 + (yCenter - cy)^2. We compare this to radius^2 to avoid computing the square root, which is unnecessary for comparison.
    //   5. The function returns true if the circle and rectangle overlap, and false otherwise.
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2)
    {
        int cx = max(x1, min(xCenter, x2));
        int cy = max(y1, min(yCenter, y2));
        long long dx = xCenter - cx, dy = yCenter - cy;
        return dx * dx + dy * dy <= (long long)radius * radius;
    }
};