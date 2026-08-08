// Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int full = (1 << n) - 1;
        vector<vector<int>> dist(n, vector<int>(1 << n, -1));
        queue<tuple<int,int,int>> q;
        for (int i = 0; i < n; i++) {
            dist[i][1 << i] = 0;
            q.push({i, 1 << i, 0});
        }
        while (!q.empty()) {
            auto [node, mask, d] = q.front(); q.pop();
            if (mask == full) return d;
            for (int next : graph[node]) {
                int nmask = mask | (1 << next);
                if (dist[next][nmask] == -1) {
                    dist[next][nmask] = d + 1;
                    q.push({next, nmask, d + 1});
                }
            }
        }
        return -1;
    }
};
