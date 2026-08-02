// Link: https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> rev(n); // reverse graph: v -> u with weight
        for (auto& e : edges) rev[e[1]].push_back({e[0], e[2]});

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : rev[u]) {
                int nd = max(d, w);
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
