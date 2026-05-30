// Link: https://leetcode.com/problems/valid-boomerang/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        // Extract the coordinates of the three points
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        // Check if the area of the triangle formed by the three points is zero, which means they are collinear
        return (x2 - x1) * (y3 - y1) != (x3 - x1) * (y2 - y1);
    }
};
