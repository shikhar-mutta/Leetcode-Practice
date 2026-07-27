// Link: https://leetcode.com/problems/angles-of-a-triangle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: check the strict triangle inequality; if valid, use the law
// of cosines to compute each angle opposite a side, convert to degrees,
// and sort non-decreasing.
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c || a + c <= b || b + c <= a) return {};

        auto angleOpposite = [](double x, double y, double z) {
            double cosA = (y*y + z*z - x*x) / (2*y*z);
            cosA = max(-1.0, min(1.0, cosA));
            return acos(cosA) * 180.0 / M_PI;
        };

        vector<double> ans = {
            angleOpposite(a, b, c),
            angleOpposite(b, a, c),
            angleOpposite(c, a, b)
        };
        sort(ans.begin(), ans.end());
        return ans;
    }
};
