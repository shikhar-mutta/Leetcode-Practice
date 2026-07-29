// Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: repeatedly peel leaves. If a leaf's accumulated value mod k is 0, it can be cut off
// as its own valid component (count it); otherwise its value must merge into its parent since it
// can't stand alone. Either way the leaf is removed and its parent's degree drops. The final
// remaining node is always a valid component too (total sum is divisible by k).
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n == 1) return 1;
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]);
            degree[e[0]]++; degree[e[1]]++;
        }
        vector<long long> val(n);
        for (int i = 0; i < n; i++) val[i] = values[i] % k;

        vector<bool> removed(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++) if (degree[i] == 1) q.push(i);

        int ans = 0, processed = 0;
        while (!q.empty() && processed < n - 1) {
            int u = q.front(); q.pop();
            if (removed[u]) continue;
            removed[u] = true; processed++;
            int parent = -1;
            for (int v : adj[u]) if (!removed[v]) { parent = v; break; }
            if (val[u] == 0) ans++;
            else val[parent] = (val[parent] + val[u]) % k;
            degree[parent]--;
            if (degree[parent] == 1) q.push(parent);
        }
        return ans + 1;
    }
};
