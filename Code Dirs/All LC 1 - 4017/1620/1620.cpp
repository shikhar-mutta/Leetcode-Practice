// Link: https://leetcode.com/problems/coordinate-with-maximum-network-quality/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxX = 0, maxY = 0;
        for (auto& t : towers) { maxX = max(maxX, t[0]); maxY = max(maxY, t[1]); }
        int bestQ = -1, bx = 0, by = 0;
        for (int x = 0; x <= maxX; x++) {
            for (int y = 0; y <= maxY; y++) {
                int q = 0;
                for (auto& t : towers) {
                    int dx = t[0] - x, dy = t[1] - y;
                    int d2 = dx * dx + dy * dy;
                    if (d2 <= radius * radius) {
                        q += (int)floor(t[2] / (1.0 + sqrt((double)d2)));
                    }
                }
                if (q > bestQ) { bestQ = q; bx = x; by = y; }
            }
        }
        return {bx, by};
    }
};
