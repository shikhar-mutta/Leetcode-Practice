// Link: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * (n + e)) worst case (DFS from every node over the adjacency list)
// SC: O(n + e) for the CSR-style adjacency arrays
// Approach: build a CSR adjacency list (from/to arrays via a counting sort +
// exclusive scan) instead of vector<vector<int>> for speed. First pass:
// for each node i, DFS its reachable set once just to size res[i] (count of
// distinct descendants that will list i as an ancestor) so the vectors can
// be reserve()'d up front. Second pass: for each node i, DFS from each
// direct successor j (skipping already-visited within this DFS to avoid
// double-adding i to a node reachable via multiple paths) and push i onto
// every visited descendant's ancestor list.
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        static int from[1001]{}, to[499500]{};
        memset(from, 0, sizeof(int) * n);
        for (const vector<int>& e : edges) {
            const int u{e[0]}, v{e[1]};
            ++from[u];
        }
        exclusive_scan(from, from + n, from, 0);
        for (const vector<int>& e : edges) {
            const int u{e[0]}, v{e[1]};
            to[from[u]++] = v;
        }
        for (int i{n}; i > 0; --i)
            from[i] = from[i - 1];
        from[0] = 0;
        vector<vector<int>> res(n);
        static int cnt[1000]{};
        memset(cnt, -1, sizeof(int) * n);
        bitset<1000> vis{};
        auto add{[&](this auto&& add, int i) -> void {
            vis[i] = true;
            ++cnt[i];
            for (const int j :
                 span<const int>{to + from[i], to + from[i + 1]}) {
                if (!vis[j])
                    add(j);
            }
        }};
        for (const int i : views::iota(0, n)) {
            vis.reset();
            add(i);
        }
        for (const int i : views::iota(0, n))
            res[i].reserve(cnt[i]);
        auto dfs{[&](this auto&& dfs, int i, int k) -> void {
            vis[i] = true;
            res[i].push_back(k);
            for (const int j :
                 span<const int>{to + from[i], to + from[i + 1]}) {
                if (!vis[j])
                    dfs(j, k);
            }
        }};
        for (const int i : views::iota(0, n)) {
            vis.reset();
            for (const int j :
                 span<const int>{to + from[i], to + from[i + 1]}) {
                if (!vis[j])
                    dfs(j, i);
            }
        }
        return move(res);
    }
};
