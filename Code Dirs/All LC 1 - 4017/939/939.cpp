// Link: https://leetcode.com/problems/minimum-area-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long long> pointSet;
        for (auto& p : points) pointSet.insert((long long)p[0] * 100001 + p[1]);

        int best = INT_MAX;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) continue;
                if (pointSet.count((long long)x1 * 100001 + y2) && pointSet.count((long long)x2 * 100001 + y1)) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    best = min(best, area);
                }
            }
        }
        return best == INT_MAX ? 0 : best;
    }
};
