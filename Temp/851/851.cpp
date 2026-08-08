// Link: https://leetcode.com/problems/loud-and-rich/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for (auto& r : richer) adj[r[1]].push_back(r[0]);
        vector<int> ans(n, -1);
        function<int(int)> dfs = [&](int u) {
            if (ans[u] != -1) return ans[u];
            int best = u;
            for (int v : adj[u]) {
                int cand = dfs(v);
                if (quiet[cand] < quiet[best]) best = cand;
            }
            return ans[u] = best;
        };
        for (int i = 0; i < n; i++) dfs(i);
        return ans;
    }
};
