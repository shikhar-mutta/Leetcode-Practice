// Link: https://leetcode.com/problems/escape-the-spreading-fire/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};

    bool canReachSafely(vector<vector<int>>& grid, vector<vector<long long>>& fireTime, long long t) {
        if (t >= fireTime[0][0]) return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        queue<pair<int,int>> q;
        q.push({0, 0});
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            for (int s = 0; s < sz; s++) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (visited[nr][nc] || grid[nr][nc] == 2) continue;
                    long long arrival = t + dist;
                    bool isDest = (nr == m-1 && nc == n-1);
                    long long ft = fireTime[nr][nc];
                    if (isDest) {
                        if (arrival > ft) continue;
                    } else {
                        if (arrival >= ft) continue;
                    }
                    visited[nr][nc] = true;
                    if (isDest) return true;
                    q.push({nr, nc});
                }
            }
        }
        return visited[m-1][n-1];
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> fireTime(m, vector<long long>(n, INF));
        queue<pair<int,int>> fq;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) { fireTime[i][j] = 0; fq.push({i, j}); }
        }
        int dist = 0;
        while (!fq.empty()) {
            int sz = fq.size();
            dist++;
            for (int s = 0; s < sz; s++) {
                auto [r, c] = fq.front(); fq.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] == 2 || fireTime[nr][nc] != INF) continue;
                    fireTime[nr][nc] = dist;
                    fq.push({nr, nc});
                }
            }
        }

        if (fireTime[m-1][n-1] == INF) {
            // fire never reaches destination; just check person can reach at all
            vector<vector<long long>> noFire(m, vector<long long>(n, INF));
            return canReachSafely(grid, noFire, 0) ? 1000000000 : -1;
        }

        long long lo = 0, hi = fireTime[m-1][n-1];
        long long best = -1;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canReachSafely(grid, fireTime, mid)) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return (int)best;
    }
};
