// Link: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2)
// Approach: BFS over states (r, c, orientation) where (r,c) is the
// snake's head cell and orientation is horizontal or vertical. From
// each state, try sliding right, sliding down, and rotating (clockwise
// from horizontal, counterclockwise from vertical), each requiring the
// relevant clearance cells to be empty. Goal: horizontal at the bottom
// right two cells.
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        auto clear = [&](int r, int c) { return r < n && c < n && grid[r][c] == 0; };

        // state key: r*n*2 + c*2 + orientation(0=horiz,1=vert)
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(2, false)));
        queue<tuple<int,int,int>> q;
        q.push({0, 0, 0});
        visited[0][0][0] = true;
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [r, c, o] = q.front(); q.pop();
                if (o == 0 && r == n - 1 && c == n - 2) return steps;

                vector<tuple<int,int,int>> next;
                if (o == 0) { // horizontal: occupies (r,c),(r,c+1)
                    if (clear(r, c + 2)) next.push_back({r, c + 1, 0});
                    if (clear(r + 1, c) && clear(r + 1, c + 1)) next.push_back({r + 1, c, 0});
                    if (clear(r + 1, c) && clear(r + 1, c + 1)) next.push_back({r, c, 1});
                } else { // vertical: occupies (r,c),(r+1,c)
                    if (clear(r + 2, c)) next.push_back({r + 1, c, 1});
                    if (clear(r, c + 1) && clear(r + 1, c + 1)) next.push_back({r, c + 1, 1});
                    if (clear(r, c + 1) && clear(r + 1, c + 1)) next.push_back({r, c, 0});
                }
                for (auto& [nr, nc, no] : next) {
                    if (nr < n && nc < n && !visited[nr][nc][no]) {
                        visited[nr][nc][no] = true;
                        q.push({nr, nc, no});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
