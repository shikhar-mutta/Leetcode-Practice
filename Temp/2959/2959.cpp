// Link: https://leetcode.com/problems/number-of-possible-sets-of-closing-branches/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        const int INF = 1e9;
        int cnt = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<vector<int>> dist(n, vector<int>(n, INF));
            for (int i = 0; i < n; i++) if (mask & (1 << i)) dist[i][i] = 0;
            for (auto& r : roads) {
                int u = r[0], v = r[1], w = r[2];
                if ((mask & (1 << u)) && (mask & (1 << v))) {
                    dist[u][v] = min(dist[u][v], w);
                    dist[v][u] = min(dist[v][u], w);
                }
            }
            for (int k = 0; k < n; k++) {
                if (!(mask & (1 << k))) continue;
                for (int i = 0; i < n; i++) {
                    if (!(mask & (1 << i)) || dist[i][k] >= INF) continue;
                    for (int j = 0; j < n; j++) {
                        if (!(mask & (1 << j))) continue;
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
            bool ok = true;
            for (int i = 0; i < n && ok; i++) {
                if (!(mask & (1 << i))) continue;
                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j))) continue;
                    if (dist[i][j] > maxDistance) { ok = false; break; }
                }
            }
            if (ok) cnt++;
        }
        return cnt;
    }
};
