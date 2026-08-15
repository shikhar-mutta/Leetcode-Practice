// Link: https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
        queue<pair<int,int>> q;
        dist1[1] = 0;
        q.push({1, 0});
        while (!q.empty()) {
            auto [u, steps] = q.front(); q.pop();
            for (int v : adj[u]) {
                int ns = steps + 1;
                if (dist1[v] == -1) {
                    dist1[v] = ns;
                    q.push({v, ns});
                } else if (dist1[v] != ns && dist2[v] == -1) {
                    dist2[v] = ns;
                    q.push({v, ns});
                }
            }
        }
        int steps = dist2[n];
        long long t = 0;
        for (int i = 0; i < steps; i++) {
            if ((t / change) % 2 == 1) {
                t = (t / change + 1) * change;
            }
            t += time;
        }
        return (int)t;
    }
};
