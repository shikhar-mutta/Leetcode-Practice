// Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n*k + E*k) log(n*k)) SC: O(n*k)
// Approach: Dijkstra over an expanded state space (node, runLength),
// where runLength is how many consecutive nodes ending at the current
// node share its label. Moving along an edge to v: if labels[v] matches
// the current run's label (which is always labels[node]), the run
// extends by 1 (rejected if it would exceed k); otherwise it resets to
// 1. Answer is the minimum distance to the last node across all valid
// run lengths.
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));
        dist[0][1] = 0;
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> pq;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top(); pq.pop();
            if (d > dist[u][run]) continue;
            for (auto& [v, w] : adj[u]) {
                int newRun = (labels[v] == labels[u]) ? run + 1 : 1;
                if (newRun > k) continue;
                long long nd = d + w;
                if (nd < dist[v][newRun]) {
                    dist[v][newRun] = nd;
                    pq.push({nd, v, newRun});
                }
            }
        }

        long long best = INF;
        for (int run = 1; run <= k; run++) best = min(best, dist[n-1][run]);
        return best == INF ? -1 : (int)best;
    }
};
