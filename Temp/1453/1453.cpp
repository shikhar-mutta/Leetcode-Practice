// Link: https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        int best = 1;
        double eps = 1e-6;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = darts[j][0] - darts[i][0];
                double dy = darts[j][1] - darts[i][1];
                double d = sqrt(dx*dx + dy*dy);
                if (d > 2.0 * r) continue;

                double midX = (darts[i][0] + darts[j][0]) / 2.0;
                double midY = (darts[i][1] + darts[j][1]) / 2.0;
                double h = sqrt(max(0.0, (double)r*r - (d/2.0)*(d/2.0)));

                double ux = -dy / d, uy = dx / d;

                for (int sign : {1, -1}) {
                    double cx = midX + sign * h * ux;
                    double cy = midY + sign * h * uy;
                    int count = 0;
                    for (auto& p : darts) {
                        double ddx = p[0] - cx, ddy = p[1] - cy;
                        if (ddx*ddx + ddy*ddy <= (double)r*r + eps) count++;
                    }
                    best = max(best, count);
                }
            }
        }
        return best;
    }
};
