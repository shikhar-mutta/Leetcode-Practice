// Link: https://leetcode.com/problems/palindromic-path-queries-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n+q) log n)  SC: O(n)
// Approach: a path's characters can be rearranged into a palindrome iff at
// most one character has an odd count along it. Track a 26-bit parity mask
// per node = XOR of (1<<char) from root to that node; a path u..v (through
// their LCA) has parity mask prefixXOR[u]^prefixXOR[v]^charBit(lca) (LCA's
// own bit is cancelled twice by the two prefixes, so XOR it back in once).
// Root the tree, use binary lifting for LCA (static structure), and an
// Euler-tour + Fenwick range-XOR/point-query structure so a character
// update at a node XORs the old/new char bits over its whole subtree's
// prefixXOR in O(log n); queries then just popcount the combined mask.
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), in(n), out(n), parent(n, -1);
        vector<int> baseXor(n, 0);
        vector<char> curChar(n);
        for (int i = 0; i < n; i++) curChar[i] = s[i];

        int timer = 0;
        {
            vector<int> stck;
            vector<int> childIdx(n, 0);
            vector<bool> visited(n, false);
            stck.push_back(0);
            visited[0] = true;
            in[0] = timer++;
            baseXor[0] = 1 << (s[0]-'a');
            while (!stck.empty()) {
                int u = stck.back();
                if (childIdx[u] < (int)adj[u].size()) {
                    int v = adj[u][childIdx[u]++];
                    if (visited[v]) continue;
                    visited[v] = true;
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    baseXor[v] = baseXor[u] ^ (1 << (s[v]-'a'));
                    in[v] = timer++;
                    stck.push_back(v);
                } else {
                    out[u] = timer - 1;
                    stck.pop_back();
                }
            }
        }
        for (int i = 0; i < n; i++) up[0][i] = (parent[i] == -1) ? i : parent[i];
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k-1][up[k-1][i]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++) if (diff & (1 << k)) u = up[k][u];
            if (u == v) return u;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) { u = up[k][u]; v = up[k][v]; }
            }
            return parent[u];
        };

        vector<int> fenw(n + 2, 0);
        auto fenwUpdate = [&](int i, int val) { for (i++; i <= n; i += i & (-i)) fenw[i] ^= val; };
        auto fenwQuery = [&](int i) { int r = 0; for (i++; i > 0; i -= i & (-i)) r ^= fenw[i]; return r; };
        auto rangeXor = [&](int l, int r, int val) { fenwUpdate(l, val); fenwUpdate(r + 1, val); };

        auto curPrefixXor = [&](int node) { return baseXor[node] ^ fenwQuery(in[node]); };

        vector<bool> result;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int idx; string cs;
                ss >> idx >> cs;
                char nc = cs[0];
                if (nc != curChar[idx]) {
                    int delta = (1 << (curChar[idx]-'a')) ^ (1 << (nc-'a'));
                    rangeXor(in[idx], out[idx], delta);
                    curChar[idx] = nc;
                }
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int mask = curPrefixXor(u) ^ curPrefixXor(v) ^ (1 << (curChar[l]-'a'));
                result.push_back(__builtin_popcount(mask) <= 1);
            }
        }
        return result;
    }
};
