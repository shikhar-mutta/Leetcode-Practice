// Link: https://leetcode.com/problems/largest-triangle-area/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        // n is small, so we can brute force all combinations of 3 points and calculate the area of the triangle formed by them using the formula:
        int n = points.size();
        // ans double to store the maximum area found
        double ans = 0;
        // Area of triangle formed by points a, b, c is given by:
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                {
                    // formula: area of triangle = abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1])) / 2.0
                    auto &a = points[i], &b = points[j], &c = points[k];
                    // area double to store the area of the triangle formed by points a, b, c
                    double area = abs(a[0] * (b[1] - c[1]) +
                                      b[0] * (c[1] - a[1]) +
                                      c[0] * (a[1] - b[1])) /
                                  2.0;
                    ans = max(ans, area);
                }
        return ans;
    }
};
