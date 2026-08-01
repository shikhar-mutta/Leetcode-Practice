// Link: https://leetcode.com/problems/count-connected-subgraphs-with-even-node-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: root the tree; every connected subgraph has a unique node
// closest to the root (its "top"), so count subgraphs by that top node to
// avoid double-counting. dp[v][p] = number of connected subgraphs rooted at
// v (must include v, entirely within v's subtree) with sum parity p.
// Combine children one at a time: for each child c, either skip its
// subtree (factor 1 on the identity parity) or attach one of its dp[c][pc]
// extensions (flips parity by pc) — a convolution of the running dp with
// [1+dp[c][0], dp[c][1]]. Sum dp[v][0] over all v for the answer.
class Solution {
    static const long long MOD = 1000000007;
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (!visited[v]) { visited[v] = true; parent[v] = u; st.push(v); }
            }
        }

        vector<array<long long,2>> dp(n);
        for (int idx = order.size() - 1; idx >= 0; idx--) {
            int v = order[idx];
            long long e = (nums[v] % 2 == 0) ? 1 : 0;
            long long o = (nums[v] % 2 == 0) ? 0 : 1;
            for (int c : adj[v]) {
                if (c == parent[v]) continue;
                long long ce = dp[c][0], co = dp[c][1];
                long long ne = (e * ((1 + ce) % MOD) % MOD + o * co % MOD) % MOD;
                long long no = (o * ((1 + ce) % MOD) % MOD + e * co % MOD) % MOD;
                e = ne; o = no;
            }
            dp[v] = {e, o};
        }

        long long ans = 0;
        for (int v = 0; v < n; v++) ans = (ans + dp[v][0]) % MOD;
        return (int)ans;
    }
};
