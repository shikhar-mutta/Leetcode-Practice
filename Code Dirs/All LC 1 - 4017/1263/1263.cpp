// Link: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int br=-1, bc=-1, pr=-1, pc=-1, tr=-1, tc=-1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') { br = i; bc = j; }
                else if (grid[i][j] == 'S') { pr = i; pc = j; }
                else if (grid[i][j] == 'T') { tr = i; tc = j; }
            }
        }
        auto isWall = [&](int r, int c) {
            return r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '#';
        };

        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        auto reachable = [&](int fromR, int fromC, int toR, int toC, int boxR, int boxC) -> bool {
            if (fromR == toR && fromC == toC) return true;
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            queue<pair<int,int>> q;
            q.push({fromR, fromC});
            vis[fromR][fromC] = true;
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (isWall(nr, nc) || vis[nr][nc]) continue;
                    if (nr == boxR && nc == boxC) continue;
                    if (nr == toR && nc == toC) return true;
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            return false;
        };

        set<tuple<int,int,int,int>> visited;
        queue<tuple<int,int,int,int,int>> q; // br, bc, pr, pc, dist
        q.push({br, bc, pr, pc, 0});
        visited.insert({br, bc, pr, pc});

        while (!q.empty()) {
            auto [cbr, cbc, cpr, cpc, dist] = q.front(); q.pop();
            if (cbr == tr && cbc == tc) return dist;
            for (int d = 0; d < 4; d++) {
                int nbr = cbr + dr[d], nbc = cbc + dc[d];
                if (isWall(nbr, nbc)) continue;
                int needR = cbr - dr[d], needC = cbc - dc[d];
                if (isWall(needR, needC)) continue;
                if (!reachable(cpr, cpc, needR, needC, cbr, cbc)) continue;
                auto key = make_tuple(nbr, nbc, cbr, cbc);
                if (visited.count(key)) continue;
                visited.insert(key);
                q.push({nbr, nbc, cbr, cbc, dist + 1});
            }
        }
        return -1;
    }
};
