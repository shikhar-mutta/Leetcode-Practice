// Link: https://leetcode.com/problems/the-maze-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*log(m*n))  SC: O(m*n)
// Approach: Dijkstra where each "edge" is a full roll in one direction
// until hitting a wall, edge weight = number of cells rolled through
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[start[0]][start[1]] = 0;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, start[0], start[1]});

        while (!pq.empty()) {
            auto [d, r, c] = pq.top(); pq.pop();
            if (d > dist[r][c]) continue;

            for (auto& dir : dirs) {
                int nr = r, nc = c, steps = 0;
                while (true) {
                    int tr = nr + dir[0], tc = nc + dir[1];
                    if (tr < 0 || tr >= m || tc < 0 || tc >= n || maze[tr][tc] == 1) break;
                    nr = tr; nc = tc; steps++;
                }
                if (steps == 0) continue;
                int nd = d + steps;
                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }

        int res = dist[destination[0]][destination[1]];
        return res == INT_MAX ? -1 : res;
    }
};
