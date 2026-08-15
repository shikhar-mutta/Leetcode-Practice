// Link: https://leetcode.com/problems/line-reflection/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: axis x = (minX + maxX) / 2; a valid reflection exists iff every
// point's mirror (sumX - x, y) is also present in the set
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        if (points.empty()) return true;
        int minX = INT_MAX, maxX = INT_MIN;
        set<pair<int,int>> pts;
        for (auto& p : points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            pts.insert({p[0], p[1]});
        }
        int sumX = minX + maxX;
        for (auto& [x, y] : pts) {
            if (!pts.count({sumX - x, y})) return false;
        }
        return true;
    }
};
