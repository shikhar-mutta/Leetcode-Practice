// Link: https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: root tree, compute subtree XOR + Euler in/out times via DFS. Removing two edges
// (to nodes u,v, u!=root,v!=root) splits into 3 pieces; use ancestor check via tin/tout to
// derive the 3 XOR values, try all O(N^2) pairs, minimize max-min.
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> subXor, tin, tout;
    int timer = 0;

    void dfs(int u, int p, vector<int>& nums) {
        tin[u] = timer++;
        subXor[u] = nums[u];
        for (int v : adj[u]) if (v != p) { dfs(v, u, nums); subXor[u] ^= subXor[v]; }
        tout[u] = timer++;
    }

    bool isAncestor(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        adj.assign(n, {});
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        subXor.assign(n, 0); tin.assign(n, 0); tout.assign(n, 0);
        dfs(0, -1, nums);
        int total = subXor[0];

        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int x1, x2, x3;
                if (isAncestor(i, j)) { x1 = subXor[j]; x2 = subXor[i]^subXor[j]; x3 = total^subXor[i]; }
                else if (isAncestor(j, i)) { x1 = subXor[i]; x2 = subXor[i]^subXor[j]; x3 = total^subXor[j]; }
                else { x1 = subXor[i]; x2 = subXor[j]; x3 = total^subXor[i]^subXor[j]; }
                int mx = max({x1,x2,x3}), mn = min({x1,x2,x3});
                ans = min(ans, mx - mn);
            }
        }
        return ans;
    }
};
