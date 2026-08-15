// Link: https://leetcode.com/problems/convex-polygon/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: compute cross product of consecutive edge vectors at every
// vertex; convex iff all nonzero cross products share the same sign
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long long prevCross = 0;
        for (int i = 0; i < n; i++) {
            auto& a = points[i];
            auto& b = points[(i + 1) % n];
            auto& c = points[(i + 2) % n];
            long long dx1 = b[0] - a[0], dy1 = b[1] - a[1];
            long long dx2 = c[0] - b[0], dy2 = c[1] - b[1];
            long long cross = dx1 * dy2 - dy1 * dx2;
            if (cross != 0) {
                if (prevCross != 0 && (cross > 0) != (prevCross > 0)) return false;
                prevCross = cross;
            }
        }
        return true;
    }
};
