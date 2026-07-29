// Link: https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*(N+E)), SC: O(N+E)
// Approach: BFS from each node as root, tracking parent edge used to reach each node. Any
// non-parent edge (u,v) found where both are already visited gives a cycle of length
// dist[u]+dist[v]+1; take the minimum across all BFS runs.
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n); // (neighbor, edgeId)
        for (int i = 0; i < (int)edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], i});
            adj[edges[i][1]].push_back({edges[i][0], i});
        }

        int ans = INT_MAX;
        for (int src = 0; src < n; src++) {
            vector<int> dist(n, -1), parentEdge(n, -1);
            dist[src] = 0;
            queue<int> q; q.push(src);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto& [v, eid] : adj[u]) {
                    if (eid == parentEdge[u]) continue;
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parentEdge[v] = eid;
                        q.push(v);
                    } else {
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
