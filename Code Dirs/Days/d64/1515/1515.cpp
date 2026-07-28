// Link: https://leetcode.com/problems/best-position-for-a-service-centre/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double x = 0, y = 0;
        int n = positions.size();
        for (auto& p : positions) { x += p[0]; y += p[1]; }
        x /= n; y /= n;
        double step = 1.0;
        auto cost = [&](double cx, double cy) {
            double s = 0;
            for (auto& p : positions) s += hypot(cx - p[0], cy - p[1]);
            return s;
        };
        double cur = cost(x, y);
        int dx8[8] = {1,-1,0,0,1,1,-1,-1};
        int dy8[8] = {0,0,1,-1,1,-1,1,-1};
        while (step > 1e-7) {
            bool improved = false;
            for (int d = 0; d < 8; d++) {
                double nx = x + dx8[d] * step, ny = y + dy8[d] * step;
                double nc = cost(nx, ny);
                if (nc < cur) { cur = nc; x = nx; y = ny; improved = true; }
            }
            if (!improved) step /= 2;
        }
        return cur;
    }
};
