// Link: https://leetcode.com/problems/separate-squares-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(precision)) SC: O(1)
//  Approach: the area of each square lying above a horizontal line y=Y is
//  side * clamp(y+side-Y, 0, side); summed over all squares this is
//  monotonically decreasing in Y, so binary search Y until the area above
//  equals half the total area.
class Solution
{
    double areaLower(vector<vector<int>> &squares, double mid)
    {
        double lower = 0.0;

        for (auto &sq : squares)
        {
            double y = sq[1];
            double side = sq[2];

            double h = min(side, max(0.0, mid - y));
            lower += h * side;
        }

        return lower;
    }

public:
    double separateSquares(vector<vector<int>> &squares)
    {
        double l = 1e9;
        double r = 0;
        double total = 0;

        for (auto &sq : squares)
        {
            double y = sq[1];
            double side = sq[2];

            total += side * side;
            l = min(l, y);
            r = max(r, y + side);
        }

        double eps = 1e-6;

        while (r - l > eps)
        {
            double mid = l + (r - l) / 2.0;

            if (areaLower(squares, mid) >= total / 2.0)
                r = mid;
            else
                l = mid;
        }

        return r;
    }
};