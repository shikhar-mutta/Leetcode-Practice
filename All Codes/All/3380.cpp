// Link: https://leetcode.com/problems/maximum-area-rectangle-with-point-constraints-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * m) where n is the number of points and m is the number of points inside the rectangle
    // SC: O(n) for the set to store the points
    // Approach:
    //  1. We can iterate through all pairs of points and consider them as the opposite corners of a rectangle.
    //  2. We can then check if the other two corners of the rectangle are also present in the set of points.
    //  3. If they are, we can then check if there are any other points inside the rectangle.
    //  4. If there are no other points inside the rectangle, we can calculate the area of the rectangle and update the maximum area found so far.
    //  5. Finally, we return the maximum area found.
    int maxRectangleArea(vector<vector<int>> &points)
    {
        set<pair<int, int>> seen;
        for (auto &point : points)
        {
            seen.insert({point[0], point[1]});
        }

        int ans = -1;
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 == x2 || y1 == y2)
                    continue;

                int left = min(x1, x2);
                int right = max(x1, x2);
                int bottom = min(y1, y2);
                int top = max(y1, y2);

                if (!seen.count({left, bottom}) || !seen.count({left, top}) ||
                    !seen.count({right, bottom}) || !seen.count({right, top}))
                    continue;

                int pointsInside = 0;
                for (auto &point : points)
                {
                    if (left <= point[0] && point[0] <= right &&
                        bottom <= point[1] && point[1] <= top)
                    {
                        pointsInside++;
                    }
                }

                if (pointsInside == 4)
                    ans = max(ans, (right - left) * (top - bottom));
            }
        }

        return ans;
    }
};
