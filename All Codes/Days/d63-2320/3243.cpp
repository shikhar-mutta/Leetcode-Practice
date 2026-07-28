// Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) amortized, SC: O(n)
// Approach: Maintain dist[i] = current shortest distance from 0 to i (init
// i for the base chain). Adding an edge (u,v) only matters if it improves
// dist[v]; when it does, re-run a BFS relaxation from v (since all other
// distances are already optimal, only nodes reachable from v need
// updating), stopping early once node n-1 is reached/settled.
class Solution {
    void bfs(vector<int>& dist, vector<vector<int>>& adj, int n, int src) {
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == n - 1)
                return;
            for (int v : adj[u]) {
                if (dist[v] > (1 + dist[u])) {
                    dist[v] = 1 + dist[u];
                    q.push(v);
                }
            }
        }
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> dist(n, 1e9);
        dist[n - 1] = n - 1;
        for (int i = 0; i < n - 1; i++) {
            dist[i] = i;
            adj[i].push_back(i + 1);
        }

        vector<int> ans;
        for (auto& q : queries) {
            adj[q[0]].push_back(q[1]);
            if ((dist[q[0]] + 1) < dist[q[1]]) {
                // Update the q[1] with new shortest distance from 0
                dist[q[1]] = dist[q[0]] + 1;
                // start from q[1] since
                // Before this node we already have Shortest Distance of each
                // node from 0
                bfs(dist, adj, n, q[1]);
            }
            ans.push_back(dist[n - 1]);
        }
        return ans;
    }
};
