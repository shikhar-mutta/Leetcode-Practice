// Link: https://leetcode.com/problems/longest-special-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//   Approach: Use a DFS traversal to explore all paths in the tree. Maintain a distance array to keep track of the cumulative distance from the root to each node. Use a last-seen array to track the last occurrence of each number in the path. When visiting a node, check if the number has been seen before and update the left boundary of the path accordingly. Calculate the length and number of nodes in the current path and update the best length and node count if necessary. Backtrack by restoring the last-seen array and left boundary after exploring each child node.

using ll = long long;
template <typename T>
using V = vector<T>;
constexpr int N = 5e4;
int last[N + 1];
class Solution
{
public:
    V<int> longestSpecialPath(V<V<int>> &edges, V<int> &nums)
    {
        int n = nums.size(), left = 0;
        V<V<pair<int, int>>> g(n);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];

            g[u].emplace_back(v, w), g[v].emplace_back(u, w);
        }

        memset(last, -1, sizeof(last));
        V<ll> dist;
        int bestd = 0, bestn = 1e9;

        auto dfs = [&](auto &&self, int u, int p = -1) -> void
        {
            int id = dist.size() - 1, q = last[nums[u]], old = left;

            if (q != -1)
                left = max(left, q + 1);

            last[nums[u]] = id;

            ll len = dist[id] - dist[left];
            int nodes = id - left + 1;

            if (len > bestd)
                bestd = len, bestn = nodes;

            else if (len == bestd)
                bestn = min(bestn, nodes);

            for (auto &[v, w] : g[u])
                if (v != p)
                    dist.push_back(dist.back() + w), self(self, v, u),
                        dist.pop_back();

            last[nums[u]] = q, left = old;
        };

        dist.push_back(0), dfs(dfs, 0);

        return {bestd, bestn};
    }
};