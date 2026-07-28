// Link: https://leetcode.com/problems/tree-of-coprimes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n, -1);
        vector<vector<pair<int,int>>> stacks(51); // value -> list of (depth, node)
        vector<bool> visited(n, false);

        function<void(int,int)> dfs = [&](int u, int depth) {
            visited[u] = true;
            int bestDepth = -1, bestNode = -1;
            for (int v = 1; v <= 50; v++) {
                if (__gcd(v, nums[u]) == 1 && !stacks[v].empty()) {
                    auto& top = stacks[v].back();
                    if (top.first > bestDepth) { bestDepth = top.first; bestNode = top.second; }
                }
            }
            ans[u] = bestNode;
            stacks[nums[u]].push_back({depth, u});
            for (int v : adj[u]) {
                if (!visited[v]) dfs(v, depth + 1);
            }
            stacks[nums[u]].pop_back();
        };
        dfs(0, 0);
        return ans;
    }
};
