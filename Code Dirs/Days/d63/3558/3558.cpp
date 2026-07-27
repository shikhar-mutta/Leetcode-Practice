// Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: the sum's parity only depends on how many of the L edges on
// the path from node 1 to node n get weight 1 (weight 2 is always even).
// We need an odd count of 1-weighted edges among L, which has exactly
// 2^(L-1) solutions (half of all 2^L assignments, by symmetry). Find L
// via BFS, then compute 2^(L-1) mod 1e9+7.
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const long long MOD = 1e9 + 7;
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }

        vector<int> dist(n + 1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
        }

        int L = dist[n];
        long long ans = 1;
        long long base = 2;
        int e = L - 1;
        while (e > 0) {
            if (e & 1) ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            e >>= 1;
        }
        return (int)ans;
    }
};
