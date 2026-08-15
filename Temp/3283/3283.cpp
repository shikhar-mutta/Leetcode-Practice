// Link: https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        vector<array<int,2>> pts(n + 1);
        pts[0] = {kx, ky};
        for (int i = 0; i < n; i++) pts[i+1] = {positions[i][0], positions[i][1]};

        int dx[8] = {1,1,-1,-1,2,2,-2,-2};
        int dy[8] = {2,-2,2,-2,1,-1,1,-1};

        vector<vector<int>> dist(n+1, vector<int>(n+1, 0));
        for (int s = 0; s <= n; s++) {
            vector<vector<int>> d(50, vector<int>(50, -1));
            d[pts[s][0]][pts[s][1]] = 0;
            queue<pair<int,int>> q;
            q.push({pts[s][0], pts[s][1]});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 8; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && nx < 50 && ny >= 0 && ny < 50 && d[nx][ny] == -1) {
                        d[nx][ny] = d[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            for (int t = 0; t <= n; t++) dist[s][t] = d[pts[t][0]][pts[t][1]];
        }

        vector<vector<int>> memo(1 << n, vector<int>(n + 1, -1));
        function<int(int,int)> solve = [&](int mask, int last) -> int {
            if (mask == 0) return 0;
            if (memo[mask][last] != -1) return memo[mask][last];
            int numCaptured = n - __builtin_popcount(mask);
            bool aliceTurn = (numCaptured % 2 == 0);
            int best = aliceTurn ? INT_MIN : INT_MAX;
            for (int p = 0; p < n; p++) {
                if (!(mask & (1 << p))) continue;
                int val = dist[last][p+1] + solve(mask ^ (1 << p), p+1);
                if (aliceTurn) best = max(best, val);
                else best = min(best, val);
            }
            return memo[mask][last] = best;
        };

        return solve((1 << n) - 1, 0);
    }
};
