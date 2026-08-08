// Link: https://leetcode.com/problems/surface-area-of-3d-shapes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int h = grid[i][j];
                if (h == 0) continue;
                area += 2;
                int up = i > 0 ? grid[i-1][j] : 0;
                int down = i < n-1 ? grid[i+1][j] : 0;
                int left = j > 0 ? grid[i][j-1] : 0;
                int right = j < n-1 ? grid[i][j+1] : 0;
                area += max(0, h - up);
                area += max(0, h - down);
                area += max(0, h - left);
                area += max(0, h - right);
            }
        }
        return area;
    }
};
