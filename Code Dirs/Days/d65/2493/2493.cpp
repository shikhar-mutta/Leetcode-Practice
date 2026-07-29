// Link: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*(N+E)), SC: O(N+E)
// Approach: each connected component must be bipartite (BFS 2-coloring), else impossible.
// For each valid component, the max number of groups equals the max BFS depth (levels) achieved
// starting from any single node in that component; sum over components.
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }

        vector<int> comp(n+1, -1);
        int numComp = 0;
        for (int i = 1; i <= n; i++) {
            if (comp[i] != -1) continue;
            queue<int> q; q.push(i); comp[i] = numComp;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) if (comp[v] == -1) { comp[v] = numComp; q.push(v); }
            }
            numComp++;
        }

        auto bfsDepth = [&](int src) -> int {
            vector<int> dist(n+1, -1);
            dist[src] = 0;
            queue<int> q; q.push(src);
            int maxD = 0;
            vector<int> color(n+1, -1);
            color[src] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                maxD = max(maxD, dist[u]);
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return -1; // odd cycle
                    }
                }
            }
            return maxD + 1;
        };

        vector<int> best(numComp, 0);
        for (int i = 1; i <= n; i++) {
            int d = bfsDepth(i);
            if (d == -1) return -1;
            best[comp[i]] = max(best[comp[i]], d);
        }

        int ans = 0;
        for (int b : best) ans += b;
        return ans;
    }
};
