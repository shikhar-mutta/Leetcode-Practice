// Link: https://leetcode.com/problems/escape-the-spreading-fire/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(rc)  SC: O(rc)
// Approach: BFS fire spread times from all initial fire cells, BFS person
// times from (0,0). Person can reach dest safely with wait w iff along
// their shortest path each cell's person-time+w is strictly less than its
// fire-time (except dest, where <= is allowed, since arriving exactly
// when fire arrives is still safe — but simulate directly via feasibility
// check for correctness). Binary search w in [0, 1e9], feasible(w) walks
// a fresh BFS with the wait baked into start time. Special-case: if fire
// never reaches dest, answer is 1e9 (can wait forever, per problem note).
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> fireTime(R, vector<int>(C, INT_MAX));
        queue<pair<int,int>> q;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (grid[i][j] == 1) { fireTime[i][j] = 0; q.push({i, j}); }
        int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (grid[nx][ny] == 2) continue;
                if (fireTime[nx][ny] != INT_MAX) continue;
                fireTime[nx][ny] = fireTime[x][y] + 1;
                q.push({nx, ny});
            }
        }
        auto feasible = [&](long long w) -> bool {
            vector<vector<bool>> vis(R, vector<bool>(C, false));
            queue<tuple<int,int,long long>> qq;
            vis[0][0] = true;
            qq.push({0, 0, w});
            if (fireTime[0][0] != INT_MAX && w >= fireTime[0][0]) return false;
            while (!qq.empty()) {
                auto [x, y, t] = qq.front(); qq.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    if (grid[nx][ny] == 2 || vis[nx][ny]) continue;
                    long long nt = t + 1;
                    bool isDest = (nx == R-1 && ny == C-1);
                    long long ft = fireTime[nx][ny] == INT_MAX ? LLONG_MAX : fireTime[nx][ny];
                    if (isDest) {
                        if (nt > ft) continue;
                    } else {
                        if (nt >= ft) continue;
                    }
                    vis[nx][ny] = true;
                    qq.push({nx, ny, nt});
                }
            }
            return vis[R-1][C-1];
        };
        if (!feasible(0)) return -1;
        long long lo = 0, hi = 1000000000;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid)) lo = mid;
            else hi = mid - 1;
        }
        return (int)lo;
    }
};
