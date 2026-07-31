// Link: https://leetcode.com/problems/find-maximum-area-of-a-triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int n = coords.size();
        int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
        unordered_map<int, pair<int,int>> colMinMaxY; // x -> (minY,maxY)
        unordered_map<int, pair<int,int>> rowMinMaxX; // y -> (minX,maxX)

        for (auto& c : coords) {
            int x = c[0], y = c[1];
            minX = min(minX, x); maxX = max(maxX, x);
            minY = min(minY, y); maxY = max(maxY, y);

            if (colMinMaxY.count(x)) {
                colMinMaxY[x].first = min(colMinMaxY[x].first, y);
                colMinMaxY[x].second = max(colMinMaxY[x].second, y);
            } else colMinMaxY[x] = {y, y};

            if (rowMinMaxX.count(y)) {
                rowMinMaxX[y].first = min(rowMinMaxX[y].first, x);
                rowMinMaxX[y].second = max(rowMinMaxX[y].second, x);
            } else rowMinMaxX[y] = {x, x};
        }

        long long best = -1;

        for (auto& [x, mm] : colMinMaxY) {
            long long base = mm.second - mm.first;
            if (base <= 0) continue;
            long long height = max((long long)x - minX, (long long)maxX - x);
            if (height <= 0) continue;
            best = max(best, base * height);
        }
        for (auto& [y, mm] : rowMinMaxX) {
            long long base = mm.second - mm.first;
            if (base <= 0) continue;
            long long height = max((long long)y - minY, (long long)maxY - y);
            if (height <= 0) continue;
            best = max(best, base * height);
        }

        return best;
    }
};
