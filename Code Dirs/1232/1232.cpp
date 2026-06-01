// Link: https://leetcode.com/problems/check-if-it-is-a-straight-line/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int n = coordinates.size();
        if (n <= 2)
        {
            return true; // Any two points are always in a straight line
        }

        // Calculate the slope using the first two points
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        int dx = x1 - x0;
        int dy = y1 - y0;

        for (int i = 2; i < n; i++)
        {
            int x = coordinates[i][0], y = coordinates[i][1];
            // Check if the slope between (x0, y0) and (x, y) is the same as the initial slope
            if (dx * (y - y0) != dy * (x - x0))
            {
                return false; // Not in a straight line
            }
        }

        return true; // All points are in a straight line
    }
};
