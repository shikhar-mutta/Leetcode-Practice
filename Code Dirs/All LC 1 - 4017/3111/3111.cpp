// Link: https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int cnt = 0;
        long long limit = LLONG_MIN;
        for (auto& p : points) {
            if (p[0] > limit) {
                cnt++;
                limit = p[0] + w;
            }
        }
        return cnt;
    }
};
