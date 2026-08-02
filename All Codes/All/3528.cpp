// Link: https://leetcode.com/problems/unit-conversion-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const long long MOD = 1e9 + 7;
        int n = conversions.size() + 1;
        vector<vector<pair<int,long long>>> adj(n);
        for (auto& c : conversions) adj[c[0]].push_back({c[1], c[2]});

        vector<long long> ans(n, -1);
        ans[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& [v, f] : adj[u]) {
                ans[v] = (ans[u] * f) % MOD;
                q.push(v);
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = (int)ans[i];
        return res;
    }
};
