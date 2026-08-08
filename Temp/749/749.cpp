// Link: https://leetcode.com/problems/contain-virus/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(rounds * m*n) SC: O(m*n)
// Approach: each round, find all infected regions via DFS, computing each region's threatened (uninfected neighbor) cells and wall count (total boundary edges to uninfected cells). Build a wall around the region with the most threatened cells (marking it permanently quarantined, immune to further spread), and infect all threatened cells of every other region. Stop when no region threatens any new cell.
class Solution {
    int m, n;
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited,
             vector<pair<int,int>>& cells, set<pair<int,int>>& threatened, int& wallsNeeded) {
        if (r<0||r>=m||c<0||c>=n||visited[r][c]) return;
        if (grid[r][c] == 0) return;
        visited[r][c] = true;
        cells.push_back({r,c});
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        for (int d = 0; d < 4; d++) {
            int nr = r+dr[d], nc = c+dc[d];
            if (nr<0||nr>=m||nc<0||nc>=n) continue;
            if (grid[nr][nc] == 0) { threatened.insert({nr,nc}); wallsNeeded++; }
            else if (grid[nr][nc] == 1) dfs(grid, nr, nc, visited, cells, threatened, wallsNeeded);
        }
    }
public:
    int containVirus(vector<vector<int>>& isInfected) {
        m = isInfected.size(); n = isInfected[0].size();
        int totalWalls = 0;
        while (true) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            vector<vector<pair<int,int>>> regions;
            vector<set<pair<int,int>>> threats;
            vector<int> wallCounts;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        vector<pair<int,int>> cells;
                        set<pair<int,int>> threatened;
                        int walls = 0;
                        dfs(isInfected, i, j, visited, cells, threatened, walls);
                        regions.push_back(cells);
                        threats.push_back(threatened);
                        wallCounts.push_back(walls);
                    }
                }
            }
            if (regions.empty()) break;
            int worst = 0;
            for (int i = 1; i < (int)regions.size(); i++)
                if (threats[i].size() > threats[worst].size()) worst = i;
            if (threats[worst].empty()) break;
            totalWalls += wallCounts[worst];
            for (auto& [r, c] : regions[worst]) isInfected[r][c] = 2;
            for (int i = 0; i < (int)regions.size(); i++) {
                if (i == worst) continue;
                for (auto& [r, c] : threats[i]) isInfected[r][c] = 1;
            }
        }
        return totalWalls;
    }
};
