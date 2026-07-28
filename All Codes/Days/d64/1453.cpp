// Link: https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = darts[j][0] - darts[i][0];
                double dy = darts[j][1] - darts[i][1];
                double d = sqrt(dx * dx + dy * dy);
                if (d > 2.0 * r) continue;
                double mx = (darts[i][0] + darts[j][0]) / 2.0;
                double my = (darts[i][1] + darts[j][1]) / 2.0;
                double h = sqrt(max(0.0, (double)r * r - (d / 2) * (d / 2)));
                double ux = -dy / d, uy = dx / d;
                for (int sign = -1; sign <= 1; sign += 2) {
                    double cx = mx + sign * h * ux;
                    double cy = my + sign * h * uy;
                    int cnt = 0;
                    for (int k = 0; k < n; k++) {
                        double ddx = darts[k][0] - cx, ddy = darts[k][1] - cy;
                        if (ddx * ddx + ddy * ddy <= (double)r * r + 1e-6) cnt++;
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
