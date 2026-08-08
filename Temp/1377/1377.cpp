// Link: https://leetcode.com/problems/frog-position-after-t-seconds/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n + 1, false);
        visited[1] = true;
        queue<tuple<int,int,double>> q;
        q.push({1, 0, 1.0});

        while (!q.empty()) {
            auto [node, time, prob] = q.front(); q.pop();

            vector<int> unvisitedNeighbors;
            for (int nb : adj[node]) if (!visited[nb]) unvisitedNeighbors.push_back(nb);

            if (node == target) {
                if (time == t || (time < t && unvisitedNeighbors.empty())) return prob;
                return 0.0;
            }
            if (time == t) continue;

            for (int nb : unvisitedNeighbors) {
                visited[nb] = true;
                q.push({nb, time + 1, prob / unvisitedNeighbors.size()});
            }
        }
        return 0.0;
    }
};
