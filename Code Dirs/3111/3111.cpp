// Link: https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of points.
    // SC: O(n) where n is the number of points.
    // Approach:
    //  1. Create a vector xs to store the x-coordinates of the points.
    //  2. Sort the xs vector in ascending order.
    //  3. Initialize a count variable to 0 and a covered variable to -1.
    //  4. Iterate through the xs vector and for each x-coordinate, check if it is greater than the covered variable. If it is, increment the count variable and update the covered variable to be the current x-coordinate plus the width w. This means that we have covered all points with x-coordinates less than or equal to the current x-coordinate plus w.
    //  5. Return the count variable as the minimum number of rectangles needed to cover all points.
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
    {
        vector<int> xs(points.size());
        for (int i = 0; i < (int)points.size(); i++)
            xs[i] = points[i][0];
        sort(xs.begin(), xs.end());

        int count = 0;
        long long covered = -1;
        for (int x : xs)
        {
            if (x > covered)
            {
                count++;
                covered = (long long)x + w;
            }
        }
        return count;
    }
};
