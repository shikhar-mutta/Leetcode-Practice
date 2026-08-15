// Link: https://leetcode.com/problems/min-cost-to-connect-all-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        int total = 0;

        for (int iter = 0; iter < n; iter++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && (u == -1 || minDist[i] < minDist[u])) u = i;
            }
            inMST[u] = true;
            total += minDist[u];
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int d = abs(points[u][0]-points[v][0]) + abs(points[u][1]-points[v][1]);
                    minDist[v] = min(minDist[v], d);
                }
            }
        }
        return total;
    }
};
