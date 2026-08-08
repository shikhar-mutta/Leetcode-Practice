// Link: https://leetcode.com/problems/map-of-highest-peak/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<int>> height(rows, vector<int>(cols, -1));
        queue<pair<int,int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (height[nr][nc] != -1) continue;
                height[nr][nc] = height[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return height;
    }
};
