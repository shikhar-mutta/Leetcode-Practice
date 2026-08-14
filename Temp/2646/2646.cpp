// Link: https://leetcode.com/problems/minimize-the-total-price-of-the-trips/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<int> count_;

    bool findPath(int u, int parent, int target, vector<int>& path) {
        path.push_back(u);
        if (u == target) return true;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (findPath(v, u, target, path)) return true;
        }
        path.pop_back();
        return false;
    }

    pair<long long,long long> dfs(int u, int parent, vector<int>& price) {
        long long base = (long long)count_[u] * price[u];
        long long notHalved = base, halved = base / 2;
        for (int v : adj[u]) {
            if (v == parent) continue;
            auto [cn, ch] = dfs(v, u, price);
            notHalved += min(cn, ch);
            halved += cn;
        }
        return {notHalved, halved};
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        count_.assign(n, 0);
        for (auto &t : trips) {
            vector<int> path;
            findPath(t[0], -1, t[1], path);
            for (int node : path) count_[node]++;
        }

        auto [notHalved, halved] = dfs(0, -1, price);
        return (int)min(notHalved, halved);
    }
};
