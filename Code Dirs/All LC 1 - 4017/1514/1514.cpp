// Link: https://leetcode.com/problems/path-with-maximum-probability/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back({b, succProb[i]});
            adj[b].push_back({a, succProb[i]});
        }

        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [p, u] = pq.top(); pq.pop();
            if (p < prob[u]) continue;
            for (auto& [v, w] : adj[u]) {
                double np = p * w;
                if (np > prob[v]) {
                    prob[v] = np;
                    pq.push({np, v});
                }
            }
        }
        return prob[end_node];
    }
};
