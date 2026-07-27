// Link: https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log(maxWeight)) SC: O(V + E)
// Approach: any valid subgraph can always be reduced to a tree where each
// node keeps exactly one outgoing edge toward node 0 — that alone has
// out-degree 1 per node, so threshold only matters as a 0-vs-positive
// gate (impossible if threshold==0 and n>1). Binary search the minimum
// weight cap W; feasibility of W is "every node can reach 0 using only
// edges with weight <= W", checked via BFS on the reversed graph.
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        if (n == 1) return 0;
        if (threshold == 0) return -1;

        vector<vector<pair<int,int>>> radj(n); // v -> (u, w) for edge u->v
        int maxW = 0;
        for (auto& e : edges) {
            radj[e[1]].push_back({e[0], e[2]});
            maxW = max(maxW, e[2]);
        }

        auto feasible = [&](int W) {
            vector<bool> vis(n, false);
            vis[0] = true;
            queue<int> q;
            q.push(0);
            int cnt = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto& [v, w] : radj[u]) {
                    if (w <= W && !vis[v]) {
                        vis[v] = true; cnt++;
                        q.push(v);
                    }
                }
            }
            return cnt == n;
        };

        if (!feasible(maxW)) return -1;
        int lo = 1, hi = maxW;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
