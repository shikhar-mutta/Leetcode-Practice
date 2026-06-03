// Link: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        if (points.empty())
            return -1;
        // Initialize the minimum distance to a large value and the answer to -1
        int minDist = INT_MAX, ans = -1;
        for (int i = 0; i < points.size(); i++)
        {
            // Check if the point has the same x or y coordinate as the given point
            if (points[i][0] != x && points[i][1] != y)
                continue;
            int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
            // Update the nearest valid point if the distance is smaller than the current minimum distance
            if (dist < minDist)
            {
                minDist = dist;
                ans = i; // Update the index of the nearest valid point
            }
        }
        return ans;
    }
};
