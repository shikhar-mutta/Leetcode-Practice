// Link: https://leetcode.com/problems/find-maximum-area-of-a-triangle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(1)
//  Approach: Iterate through all pairs of points and calculate the area of the triangle formed by those points and the origin. Keep track of the maximum area found.
//  The area of a triangle formed by points (x1, y1), (x2, y2), and the origin (0, 0) can be calculated using the formula: area = abs(x1*y2 - x2*y1) / 2. We can iterate through all pairs of points and calculate the area for each pair, keeping track of the maximum area found.
class Solution
{
public:
    long long maxArea(vector<vector<int>> &coords)
    {
        sort(coords.begin(), coords.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });
        int n = coords.size();
        long long res = 0, w, h;
        int start = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (coords[i + 1][0] > coords[start][0])
            {
                if (i > start)
                {
                    w = coords[i][1] - coords[start][1];
                    h = max(coords[i][0] - coords[0][0],
                            coords[n - 1][0] - coords[i][0]);
                    res = max(res, w * h);
                }
                start = i + 1;
            }
        }
        if (start < n - 1)
        {
            w = coords[n - 1][1] - coords[start][1];
            h = coords[n - 1][0] - coords[0][0];
            res = max(res, w * h);
        }

        sort(coords.begin(), coords.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[1] == b[1])
                     return a[0] < b[0];
                 return a[1] < b[1];
             });
        start = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (coords[i + 1][1] > coords[start][1])
            {
                if (i > start)
                {
                    w = coords[i][0] - coords[start][0];
                    h = max(coords[i][1] - coords[0][1],
                            coords[n - 1][1] - coords[i][1]);
                    res = max(res, w * h);
                }
                start = i + 1;
            }
        }
        if (start < n - 1)
        {
            w = coords[n - 1][0] - coords[start][0];
            h = coords[n - 1][1] - coords[0][1];
            res = max(res, w * h);
        }
        return (res == 0) ? -1 : res;
    }
};