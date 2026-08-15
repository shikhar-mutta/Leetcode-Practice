// Link: https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        for (auto& e : redEdges) red[e[0]].push_back(e[1]);
        for (auto& e : blueEdges) blue[e[0]].push_back(e[1]);

        vector<vector<int>> dist(n, vector<int>(2, -1));
        dist[0][0] = 0; dist[0][1] = 0;
        queue<pair<int,int>> q;
        q.push({0, 0});
        q.push({0, 1});
        while (!q.empty()) {
            auto [node, color] = q.front(); q.pop();
            auto& adj = color == 0 ? red[node] : blue[node];
            int nextColor = 1 - color;
            for (int nb : adj) {
                if (dist[nb][nextColor] == -1) {
                    dist[nb][nextColor] = dist[node][color] + 1;
                    q.push({nb, nextColor});
                }
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1) res[i] = dist[i][1];
            else if (dist[i][1] == -1) res[i] = dist[i][0];
            else res[i] = min(dist[i][0], dist[i][1]);
        }
        return res;
    }
};
