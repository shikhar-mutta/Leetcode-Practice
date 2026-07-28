// Link: https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n + e)  SC: O(n)
// Approach: BFS tracking two distances per node (shortest, second-shortest
// strictly greater). A neighbor relaxation with dist+1 updates dist1 if
// smaller, or dist2 if strictly between dist1 and current dist2. Then convert
// the second-shortest edge count to actual time, accounting for signal wait.
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
        queue<pair<int,int>> q; // (node, dist)
        dist1[1] = 0;
        q.push({1, 0});
        while (!q.empty()) {
            auto [u, d] = q.front(); q.pop();
            for (int v : adj[u]) {
                int nd = d + 1;
                if (dist1[v] == -1) {
                    dist1[v] = nd;
                    q.push({v, nd});
                } else if (nd > dist1[v] && dist2[v] == -1) {
                    dist2[v] = nd;
                    q.push({v, nd});
                }
            }
        }

        int steps = dist2[n];
        long long cur = 0;
        for (int i = 0; i < steps; i++) {
            long long waitBlocks = cur / change;
            if (waitBlocks % 2 == 1) {
                cur = (waitBlocks + 1) * change;
            }
            cur += time;
        }
        return (int)cur;
    }
};
