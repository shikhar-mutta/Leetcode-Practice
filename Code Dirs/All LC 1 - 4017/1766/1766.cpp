// Link: https://leetcode.com/problems/tree-of-coprimes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> nums, ans, depth;
    int last[51];

    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

    void dfs(int u, int p, int d) {
        depth[u] = d;
        int bestDepth = -1;
        for (int v = 1; v <= 50; v++) {
            if (last[v] != -1 && gcd(nums[u], v) == 1 && depth[last[v]] > bestDepth) {
                bestDepth = depth[last[v]];
                ans[u] = last[v];
            }
        }
        int old = last[nums[u]];
        last[nums[u]] = u;
        for (int v : adj[u]) {
            if (v != p) dfs(v, u, d + 1);
        }
        last[nums[u]] = old;
    }

    vector<int> getCoprimes(vector<int>& nums_, vector<vector<int>>& edges) {
        nums = nums_;
        int n = nums.size();
        adj.assign(n, vector<int>());
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        ans.assign(n, -1);
        depth.assign(n, 0);
        memset(last, -1, sizeof(last));
        dfs(0, -1, 0);
        return ans;
    }
};
