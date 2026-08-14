// Link: https://leetcode.com/problems/count-lattice-points-inside-a-circle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> points;
        for (auto& c : circles) {
            int cx = c[0], cy = c[1], r = c[2];
            for (int x = cx - r; x <= cx + r; x++) {
                for (int y = cy - r; y <= cy + r; y++) {
                    if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r) {
                        points.insert({x, y});
                    }
                }
            }
        }
        return points.size();
    }
};
