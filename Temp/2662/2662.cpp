// Link: https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        vector<pair<int,int>> nodes;
        nodes.push_back({start[0], start[1]});
        nodes.push_back({target[0], target[1]});
        for (auto &r : specialRoads) {
            nodes.push_back({r[0], r[1]});
            nodes.push_back({r[2], r[3]});
        }

        int n = nodes.size();
        auto manhattan = [](pair<int,int> a, pair<int,int> b) {
            return abs(a.first - b.first) + abs(a.second - b.second);
        };

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (int v = 0; v < n; v++) {
                if (v == u) continue;
                long long w = manhattan(nodes[u], nodes[v]);
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }

            for (auto &r : specialRoads) {
                if (nodes[u].first == r[0] && nodes[u].second == r[1]) {
                    for (int v = 0; v < n; v++) {
                        if (nodes[v].first == r[2] && nodes[v].second == r[3]) {
                            long long w = r[4];
                            if (dist[u] + w < dist[v]) {
                                dist[v] = dist[u] + w;
                                pq.push({dist[v], v});
                            }
                        }
                    }
                }
            }
        }

        return (int)dist[1];
    }
};
