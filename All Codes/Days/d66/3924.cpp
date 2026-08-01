// Link: https://leetcode.com/problems/minimum-threshold-path-with-limited-heavy-edges/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(E log E * (V+E))  SC: O(V+E)
// Approach: binary search the minimum threshold T (over sorted distinct
// edge weights) such that source can reach target using at most k "heavy"
// edges (weight > T). Feasibility for a fixed T is checked via 0-1 BFS:
// edges with weight > T cost 1 (heavy), others cost 0, giving the minimum
// number of heavy edges on any path; accept if that's <= k. Feasibility is
// monotonic in T (raising T can only turn heavy edges light), so binary
// search applies.
class Solution {
    int n;
    vector<vector<pair<int,int>>> adj; // {to, weight}

    int minHeavyEdges(int source, int target, int T) {
        vector<int> dist(n, INT_MAX);
        deque<int> dq;
        dist[source] = 0;
        dq.push_back(source);
        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();
            for (auto& [v, w] : adj[u]) {
                int cost = (w > T) ? 1 : 0;
                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    if (cost == 0) dq.push_front(v);
                    else dq.push_back(v);
                }
            }
        }
        return dist[target];
    }
public:
    int minimumThreshold(int n_, vector<vector<int>>& edges, int source, int target, int k) {
        n = n_;
        if (source == target) return 0;
        adj.assign(n, {});
        vector<int> weights;
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
            weights.push_back(e[2]);
        }
        sort(weights.begin(), weights.end());
        weights.erase(unique(weights.begin(), weights.end()), weights.end());

        int lo = 0, hi = (int)weights.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int heavy = minHeavyEdges(source, target, weights[mid]);
            if (heavy != INT_MAX && heavy <= k) {
                ans = weights[mid];
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
