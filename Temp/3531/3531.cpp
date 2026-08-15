// Link: https://leetcode.com/problems/count-covered-buildings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> rowMinMax; // x -> (minY, maxY) for fixed row (x)
        unordered_map<int, pair<int,int>> colMinMax; // y -> (minX, maxX) for fixed col (y)

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if (!rowMinMax.count(x)) rowMinMax[x] = {y, y};
            else {
                rowMinMax[x].first = min(rowMinMax[x].first, y);
                rowMinMax[x].second = max(rowMinMax[x].second, y);
            }
            if (!colMinMax.count(y)) colMinMax[y] = {x, x};
            else {
                colMinMax[y].first = min(colMinMax[y].first, x);
                colMinMax[y].second = max(colMinMax[y].second, x);
            }
        }

        int count = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            auto& [minY, maxY] = rowMinMax[x];
            auto& [minX, maxX] = colMinMax[y];
            if (y > minY && y < maxY && x > minX && x < maxX) count++;
        }
        return count;
    }
};
