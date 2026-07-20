// Link: https://leetcode.com/problems/rectangle-area/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1) SC: O(1)
    //  Approach:
    //  1. We can calculate the area of each rectangle using the formula: area = (x2 - x1) * (y2 - y1).
    //  2. We can then calculate the area of the overlapping region using the formula: overlap = max(0, min(x2, x4) - max(x1, x3)) * max(0, min(y2, y4) - max(y1, y3)).
    //  3. Finally, we can return the total area of the two rectangles minus the area of the overlapping region.
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        long long area1 = (long long)(ax2 - ax1) * (ay2 - ay1);
        long long area2 = (long long)(bx2 - bx1) * (by2 - by1);
        long long overlapW = max(0LL, (long long)min(ax2, bx2) - max(ax1, bx1));
        long long overlapH = max(0LL, (long long)min(ay2, by2) - max(ay1, by1));
        long long overlap = overlapW * overlapH;
        return (int)(area1 + area2 - overlap);
    }
};
