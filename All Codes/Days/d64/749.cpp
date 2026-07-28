// Link: https://leetcode.com/problems/contain-virus/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(rounds * m * n)  SC: O(m*n)
// Approach: each round, find all infected connected components and, for
// each, its set of adjacent uninfected frontier cells plus the wall
// count needed to fully enclose it (counting each infected-to-uninfected
// edge). The component with the largest frontier gets walled off
// (marked permanently blocked, walls added to answer); every other
// component spreads by infecting its frontier cells. Stop when no
// component has any frontier left.
class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size(), n = isInfected[0].size();
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        int totalWalls = 0;

        while (true) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            vector<vector<pair<int,int>>> regions;      // infected cells per region
            vector<set<pair<int,int>>> frontiers;        // uninfected frontier cells per region
            vector<int> wallsNeeded;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        vector<pair<int,int>> region;
                        set<pair<int,int>> frontier;
                        int walls = 0;
                        queue<pair<int,int>> q;
                        q.push({i, j});
                        visited[i][j] = true;
                        while (!q.empty()) {
                            auto [x, y] = q.front(); q.pop();
                            region.push_back({x, y});
                            for (int d = 0; d < 4; d++) {
                                int nx = x + dx[d], ny = y + dy[d];
                                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                                if (isInfected[nx][ny] == 1 && !visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                } else if (isInfected[nx][ny] == 0) {
                                    frontier.insert({nx, ny});
                                    walls++;
                                }
                            }
                        }
                        regions.push_back(region);
                        frontiers.push_back(frontier);
                        wallsNeeded.push_back(walls);
                    }
                }
            }

            if (regions.empty()) break;
            int best = -1;
            for (int r = 0; r < (int)regions.size(); r++) {
                if (best == -1 || frontiers[r].size() > frontiers[best].size()) best = r;
            }
            if (frontiers[best].empty()) break;

            totalWalls += wallsNeeded[best];
            for (auto& [x, y] : regions[best]) isInfected[x][y] = 2;

            for (int r = 0; r < (int)regions.size(); r++) {
                if (r == best) continue;
                for (auto& [x, y] : frontiers[r]) isInfected[x][y] = 1;
            }
        }
        return totalWalls;
    }
};
