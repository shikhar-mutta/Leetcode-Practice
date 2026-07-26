// Link: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: root the tree at city 0 and DFS. Each subtree returns the
// number of representatives (people) that must travel up through its
// root edge; that count needs ceil(count / seats) cars for the edge
// connecting it to its parent, which is added to the running answer.
// Every node contributes its own representative plus all of its
// children's passenger counts.
class Solution {
public:
    long long ans = 0;

    int dfs(int node, int parent, vector<vector<int>>& adj, int seats) {

        int passengers = 0;

        for (int child : adj[node]) {

            if (child == parent)
                continue;

            int p = dfs(child, node, adj, seats);

            passengers += p;

            ans += (p + seats - 1) / seats; // ceil(p / seats)
        }

        return passengers + 1; // include current city's representative
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        int n = roads.size() + 1;

        vector<vector<int>> adj(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, adj, seats);

        return ans;
    }
};
