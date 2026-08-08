// Link: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> res(n, 0);
        vector<bool> visited(n, false);

        function<array<int,26>(int)> dfs = [&](int u) -> array<int,26> {
            array<int,26> cnt = {};
            visited[u] = true;
            cnt[labels[u] - 'a']++;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    auto childCnt = dfs(v);
                    for (int i = 0; i < 26; i++) cnt[i] += childCnt[i];
                }
            }
            res[u] = cnt[labels[u] - 'a'];
            return cnt;
        };
        dfs(0);
        return res;
    }
};
