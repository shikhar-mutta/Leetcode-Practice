// Link: https://leetcode.com/problems/minimum-area-rectangle-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        map<pair<double,double>, vector<pair<int,int>>> groups;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double cx = (points[i][0] + points[j][0]) / 2.0;
                double cy = (points[i][1] + points[j][1]) / 2.0;
                double dist2 = (double)(points[i][0]-points[j][0])*(points[i][0]-points[j][0]) +
                               (double)(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                groups[{cx, cy}].push_back({i, j});
                (void)dist2;
            }
        }

        double best = -1;
        for (auto& [center, pairs] : groups) {
            int m = pairs.size();
            for (int a = 0; a < m; a++) {
                for (int b = a + 1; b < m; b++) {
                    auto [i1, j1] = pairs[a];
                    auto [i2, j2] = pairs[b];
                    double d1sq = distSq(points[i1], points[j1]);
                    double d2sq = distSq(points[i2], points[j2]);
                    if (abs(d1sq - d2sq) > 1e-6) continue;
                    // i1, i2, j1, j2 form rectangle with diagonals i1-j1 and i2-j2
                    double side1 = distSq(points[i1], points[i2]);
                    double side2 = distSq(points[i1], points[j2]);
                    double area;
                    if (abs(side1 + side2 - d1sq) < 1e-6) {
                        area = sqrt(side1) * sqrt(side2);
                    } else continue;
                    if (best < 0 || area < best) best = area;
                }
            }
        }
        return best < 0 ? 0 : best;
    }

private:
    double distSq(vector<int>& a, vector<int>& b) {
        double dx = a[0] - b[0], dy = a[1] - b[1];
        return dx*dx + dy*dy;
    }
};
