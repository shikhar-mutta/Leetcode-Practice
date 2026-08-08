// Link: https://leetcode.com/problems/all-paths-from-source-lead-to-destination/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back(e[1]);

        vector<int> state(n, 0); // 0=unvisited,1=visiting,2=done
        return dfs(source, destination, adj, state);
    }

private:
    bool dfs(int u, int destination, vector<vector<int>>& adj, vector<int>& state) {
        if (state[u] == 1) return false;
        if (state[u] == 2) return true;
        if (adj[u].empty()) return u == destination;
        if (u == destination) return false;

        state[u] = 1;
        for (int v : adj[u]) {
            if (!dfs(v, destination, adj, state)) return false;
        }
        state[u] = 2;
        return true;
    }
};
