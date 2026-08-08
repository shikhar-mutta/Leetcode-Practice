// Link: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        // state: r,c = tail position (top-left cell of snake), horiz = 1 if horizontal
        set<tuple<int,int,int>> visited;
        queue<tuple<int,int,int,int>> q;
        q.push({0, 0, 1, 0});
        visited.insert({0, 0, 1});

        auto free = [&](int r, int c) {
            return r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0;
        };

        while (!q.empty()) {
            auto [r, c, horiz, d] = q.front(); q.pop();
            if (horiz && r == n-1 && c == n-2) return d;

            vector<tuple<int,int,int>> next;
            if (horiz) {
                if (free(r, c+2)) next.push_back({r, c+1, 1});
                if (free(r+1, c) && free(r+1, c+1)) next.push_back({r+1, c, 1});
                if (free(r+1, c) && free(r+1, c+1)) next.push_back({r, c, 0});
            } else {
                if (free(r+2, c)) next.push_back({r+1, c, 0});
                if (free(r, c+1) && free(r+1, c+1)) next.push_back({r, c+1, 0});
                if (free(r, c+1) && free(r+1, c+1)) next.push_back({r, c, 1});
            }
            for (auto& [nr, nc, nh] : next) {
                if (!visited.count({nr, nc, nh})) {
                    visited.insert({nr, nc, nh});
                    q.push({nr, nc, nh, d+1});
                }
            }
        }
        return -1;
    }
};
