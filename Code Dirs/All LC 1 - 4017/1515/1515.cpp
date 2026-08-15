// Link: https://leetcode.com/problems/best-position-for-a-service-centre/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dist(double x, double y, vector<vector<int>>& positions) {
        double sum = 0;
        for (auto& p : positions) {
            double dx = x - p[0], dy = y - p[1];
            sum += sqrt(dx*dx + dy*dy);
        }
        return sum;
    }

    double getMinDistSum(vector<vector<int>>& positions) {
        double x = 0, y = 0;
        for (auto& p : positions) { x += p[0]; y += p[1]; }
        x /= positions.size();
        y /= positions.size();

        double step = 1.0;
        double eps = 1e-8;
        while (step > eps) {
            bool improved = false;
            int dx8[] = {1,-1,0,0,1,1,-1,-1};
            int dy8[] = {0,0,1,-1,1,-1,1,-1};
            double best = dist(x, y, positions);
            double bx = x, by = y;
            for (int d = 0; d < 8; d++) {
                double nx = x + dx8[d]*step, ny = y + dy8[d]*step;
                double nd = dist(nx, ny, positions);
                if (nd < best) { best = nd; bx = nx; by = ny; improved = true; }
            }
            if (improved) { x = bx; y = by; }
            else step /= 2;
        }
        return dist(x, y, positions);
    }
};
