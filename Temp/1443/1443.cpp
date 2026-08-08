// Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<int(int,int)> dfs = [&](int node, int parent) -> int {
            int cost = 0;
            for (int child : adj[node]) {
                if (child == parent) continue;
                int childCost = dfs(child, node);
                if (childCost > 0 || hasApple[child]) cost += childCost + 2;
            }
            return cost;
        };

        return dfs(0, -1);
    }
};
