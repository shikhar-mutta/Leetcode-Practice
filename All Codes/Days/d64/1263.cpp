// Link: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((m*n)^2)  SC: O((m*n)^2)
// Approach: BFS over states (box position, player position), counting
// pushes. From each state, try pushing the box in each of 4 directions:
// this requires the box's destination cell to be free, AND the player
// must be able to walk (without moving the box) from their current
// position to the cell opposite the push direction — checked via an
// inner BFS each time. Each successful push advances the state with
// player now standing where the box used to be.
class Solution {
    int m, n;
    bool canReach(vector<vector<char>>& grid, pair<int,int> box, pair<int,int> start, pair<int,int> target) {
        if (start == target) return true;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push(start);
        visited[start.first][start.second] = true;
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] == '#') continue;
                if (nx == box.first && ny == box.second) continue;
                if (visited[nx][ny]) continue;
                if (nx == target.first && ny == target.second) return true;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        return false;
    }
public:
    int minPushBox(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        pair<int,int> box, player, target;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') box = {i, j};
                else if (grid[i][j] == 'S') player = {i, j};
                else if (grid[i][j] == 'T') target = {i, j};
            }

        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        set<tuple<int,int,int,int>> visited;
        queue<tuple<int,int,int,int,int>> q; // boxR,boxC,playerR,playerC,pushes
        q.push({box.first, box.second, player.first, player.second, 0});
        visited.insert({box.first, box.second, player.first, player.second});

        while (!q.empty()) {
            auto [bx, by, px, py, pushes] = q.front(); q.pop();
            if (bx == target.first && by == target.second) return pushes;
            for (int d = 0; d < 4; d++) {
                int nbx = bx + dx[d], nby = by + dy[d];
                if (nbx < 0 || nbx >= m || nby < 0 || nby >= n || grid[nbx][nby] == '#') continue;
                int px_need = bx - dx[d], py_need = by - dy[d]; // player must be opposite side
                if (px_need < 0 || px_need >= m || py_need < 0 || py_need >= n || grid[px_need][py_need] == '#') continue;
                if (!canReach(grid, {bx, by}, {px, py}, {px_need, py_need})) continue;
                auto state = make_tuple(nbx, nby, bx, by);
                if (visited.count(state)) continue;
                visited.insert(state);
                q.push({nbx, nby, bx, by, pushes + 1});
            }
        }
        return -1;
    }
};
