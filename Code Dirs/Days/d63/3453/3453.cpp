// Link: https://leetcode.com/problems/separate-squares-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(precision)) SC: O(1)
// Approach: the area of each square lying above a horizontal line y=Y is
// side * clamp(y+side-Y, 0, side); summed over all squares this is
// monotonically decreasing in Y, so binary search Y until the area above
// equals half the total area.
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double lo = 1e9, hi = -1e9;
        for (auto& sq : squares) {
            double side = sq[2];
            totalArea += side * side;
            lo = min(lo, (double)sq[1]);
            hi = max(hi, (double)sq[1] + side);
        }

        auto areaAbove = [&](double Y) {
            double total = 0;
            for (auto& sq : squares) {
                double y = sq[1], side = sq[2];
                double clipped = min(side, max(0.0, y + side - Y));
                total += side * clipped;
            }
            return total;
        };

        double target = totalArea / 2.0;
        for (int iter = 0; iter < 100; iter++) {
            double mid = (lo + hi) / 2.0;
            if (areaAbove(mid) > target) lo = mid;
            else hi = mid;
        }
        return (lo + hi) / 2.0;
    }
};
