// Link: https://leetcode.com/problems/longest-special-path/description/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using V = vector<T>;
constexpr int N = 5e4;
int last3425[N + 1];

class Solution {
public:
    V<int> longestSpecialPath(V<V<int>>& edges, V<int>& nums) {
        int n = nums.size(), left = 0;
        V<V<pair<int, int>>> g(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w), g[v].emplace_back(u, w);
        }

        memset(last3425, -1, sizeof(last3425));
        V<ll> dist;
        int bestd = 0, bestn = 1e9;

        auto dfs = [&](auto&& self, int u, int p = -1) -> void {
            int id = dist.size() - 1, q = last3425[nums[u]], old = left;

            if (q != -1)
                left = max(left, q + 1);

            last3425[nums[u]] = id;

            ll len = dist[id] - dist[left];
            int nodes = id - left + 1;

            if (len > bestd)
                bestd = len, bestn = nodes;
            else if (len == bestd)
                bestn = min(bestn, nodes);

            for (auto& [v, w] : g[u])
                if (v != p)
                    dist.push_back(dist.back() + w), self(self, v, u),
                        dist.pop_back();

            last3425[nums[u]] = q, left = old;
        };

        dist.push_back(0), dfs(dfs, 0);

        return {bestd, bestn};
    }
};
