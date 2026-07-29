// Link: https://leetcode.com/problems/number-of-possible-sets-of-closing-branches/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^N * N^3), SC: O(N^2)
// Approach: n <= 10, so brute-force every subset of kept branches. For each subset, run
// Floyd-Warshall restricted to those nodes/edges and check every pair's shortest distance is
// within maxDistance.
class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        const int INF = 1e9;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<vector<int>> dist(n, vector<int>(n, INF));
            for (int i = 0; i < n; i++) if (mask & (1 << i)) dist[i][i] = 0;
            for (auto& r : roads) {
                if ((mask & (1 << r[0])) && (mask & (1 << r[1])))
                    dist[r[0]][r[1]] = dist[r[1]][r[0]] = min(dist[r[0]][r[1]], r[2]);
            }
            for (int k = 0; k < n; k++)
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (dist[i][k] < INF && dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

            bool ok = true;
            for (int i = 0; i < n && ok; i++) {
                if (!(mask & (1 << i))) continue;
                for (int j = 0; j < n && ok; j++) {
                    if (!(mask & (1 << j))) continue;
                    if (dist[i][j] > maxDistance) ok = false;
                }
            }
            if (ok) ans++;
        }
        return ans;
    }
};
