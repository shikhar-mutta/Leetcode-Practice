// Link: https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1);
        vector<long long> down(n, 0);
        vector<long long> up(n, 0);
        vector<int> order;

        // BFS to get processing order and parents
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        // down[v]: max path sum from v downward (into its subtree), including price[v]
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int v = order[i];
            long long best = 0;
            for (int c : adj[v]) {
                if (c == parent[v]) continue;
                best = max(best, down[c]);
            }
            down[v] = price[v] + best;
        }

        // up[v]: max path sum going from v toward its parent direction, including price[v]
        up[0] = 0;
        for (int v : order) {
            vector<pair<long long,int>> childVals; // (down[c], c)
            for (int c : adj[v]) {
                if (c == parent[v]) continue;
                childVals.push_back({down[c], c});
            }
            sort(childVals.rbegin(), childVals.rend());

            for (int c : adj[v]) {
                if (c == parent[v]) continue;
                long long bestSibling = 0;
                for (auto &[val, node] : childVals) {
                    if (node != c) { bestSibling = val; break; }
                }
                long long upBranch = max(up[v], bestSibling);
                up[c] = price[v] + upBranch;
            }
        }

        long long answer = 0;
        for (int v = 0; v < n; v++) {
            long long best = up[v];
            for (int c : adj[v]) {
                if (c == parent[v]) continue;
                best = max(best, down[c]);
            }
            answer = max(answer, best);
        }
        return answer;
    }
};
