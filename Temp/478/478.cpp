// Link: https://leetcode.com/problems/generate-random-point-in-a-circle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) expected per call  SC: O(1)
// Approach: rejection sampling in the bounding square - much simpler than
// direct polar sampling and avoids the sqrt-of-uniform bias trap
class Solution {
    double radius, xc, yc;

public:
    Solution(double radius, double x_center, double y_center) : radius(radius), xc(x_center), yc(y_center) {}

    vector<double> randPoint() {
        double x, y;
        do {
            x = (2.0 * rand() / RAND_MAX - 1.0) * radius;
            y = (2.0 * rand() / RAND_MAX - 1.0) * radius;
        } while (x * x + y * y > radius * radius);
        return {xc + x, yc + y};
    }
};
