// Link: https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*2500 + 2^m * m^2), SC: O(m*2500 + 2^m * m)
// Approach: BFS knight-move distances from each relevant point (start + every pawn) to every
// board cell, giving exact pairwise distances between all m+1 nodes. Then minimax with
// memoization over (bitmask of remaining pawns, current knight node): Alice (maximizer, even
// number of pawns captured so far) and Bob (minimizer) alternate choosing which remaining pawn
// to capture next, paying its knight-distance in moves.
class Solution {
public:
    int m;
    vector<vector<int>> dist; // dist[node][pawnIndex] using node = 0(start) or 1..m
    vector<vector<int>> memo;

    int dp(int mask, int pos, int startPopcount) {
        if (mask == 0) return 0;
        if (memo[mask][pos] != -1) return memo[mask][pos];

        bool maximizer = ((startPopcount - __builtin_popcount(mask)) % 2 == 0);
        int best = maximizer ? INT_MIN : INT_MAX;
        for (int p = 0; p < m; p++) {
            if (!(mask & (1 << p))) continue;
            int cost = dist[pos][p] + dp(mask ^ (1 << p), p + 1, startPopcount);
            if (maximizer) best = max(best, cost);
            else best = min(best, cost);
        }
        memo[mask][pos] = best;
        return best;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        m = positions.size();
        vector<pair<int,int>> nodes;
        nodes.push_back({kx, ky});
        for (auto& p : positions) nodes.push_back({p[0], p[1]});

        int BOARD = 50;
        int dr[] = {-2,-2,-1,-1,1,1,2,2}, dc[] = {-1,1,-2,2,-2,2,-1,1};
        dist.assign(m+1, vector<int>(m, 0));
        for (int s = 0; s <= m; s++) {
            vector<vector<int>> d(BOARD, vector<int>(BOARD, -1));
            int sx = nodes[s].first, sy = nodes[s].second;
            d[sx][sy] = 0;
            queue<pair<int,int>> q; q.push({sx, sy});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 8; k++) {
                    int nx = x+dr[k], ny = y+dc[k];
                    if (nx<0||nx>=BOARD||ny<0||ny>=BOARD||d[nx][ny]!=-1) continue;
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            for (int p = 0; p < m; p++) dist[s][p] = d[nodes[p+1].first][nodes[p+1].second];
        }

        memo.assign(1 << m, vector<int>(m+1, -1));
        int fullMask = (1 << m) - 1;
        return dp(fullMask, 0, m);
    }
};
