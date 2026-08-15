// Link: https://leetcode.com/problems/the-maze/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: BFS from start; from each stopped position, roll in each of
// the 4 directions until hitting a wall, treat that final resting spot as
// the next BFS node
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == destination[0] && c == destination[1]) return true;

            for (auto& d : dirs) {
                int nr = r, nc = c;
                while (nr + d[0] >= 0 && nr + d[0] < m && nc + d[1] >= 0 && nc + d[1] < n && maze[nr + d[0]][nc + d[1]] == 0) {
                    nr += d[0]; nc += d[1];
                }
                if (!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
};
