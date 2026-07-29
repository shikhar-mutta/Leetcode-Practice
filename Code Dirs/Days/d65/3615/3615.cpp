// Link: https://leetcode.com/problems/longest-palindromic-path-in-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        for (auto& e : edges) { adj[e[0]][e[1]] = true; adj[e[1]][e[0]] = true; }

        int full = 1 << n;
        // dp[mask][u][v] : -1 unknown, 0 false, 1 true
        vector<vector<vector<int8_t>>> dp(full, vector<vector<int8_t>>(n, vector<int8_t>(n, -1)));

        vector<vector<int>> masksByPC(n + 1);
        for (int m = 0; m < full; m++) masksByPC[__builtin_popcount(m)].push_back(m);

        int ans = 1;

        for (int m : masksByPC[1]) {
            int u = __builtin_ctz(m);
            dp[m][u][u] = 1;
        }

        for (int pc = 2; pc <= n; pc++) {
            for (int mask : masksByPC[pc]) {
                for (int u = 0; u < n; u++) {
                    if (!(mask & (1 << u))) continue;
                    for (int v = 0; v < n; v++) {
                        if (u == v || !(mask & (1 << v))) continue;
                        if (label[u] != label[v]) { dp[mask][u][v] = 0; continue; }
                        bool ok = false;
                        if (pc == 2) {
                            ok = adj[u][v];
                        } else {
                            int inner = mask ^ (1 << u) ^ (1 << v);
                            int cand = inner;
                            while (cand && !ok) {
                                int up = __builtin_ctz(cand);
                                cand &= cand - 1;
                                if (!adj[u][up]) continue;
                                int cand2 = inner;
                                while (cand2) {
                                    int vp = __builtin_ctz(cand2);
                                    cand2 &= cand2 - 1;
                                    if (!adj[v][vp]) continue;
                                    if (dp[inner][up][vp] == 1) { ok = true; break; }
                                }
                            }
                        }
                        dp[mask][u][v] = ok ? 1 : 0;
                        if (ok) ans = max(ans, pc);
                    }
                }
            }
        }

        return ans;
    }
};
