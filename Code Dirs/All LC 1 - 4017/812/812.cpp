// Link: https://leetcode.com/problems/largest-triangle-area/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) SC: O(1)
// Approach: try every triple of points, compute triangle area via the shoelace formula, track max.
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double best = 0;
        int n = points.size();
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                for (int k = j+1; k < n; k++) {
                    double area = 0.5 * abs(
                        (points[j][0]-points[i][0])*(points[k][1]-points[i][1]) -
                        (points[k][0]-points[i][0])*(points[j][1]-points[i][1])
                    );
                    best = max(best, area);
                }
        return best;
    }
};
