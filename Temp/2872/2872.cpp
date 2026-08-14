// Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n == 1) return 1;
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++; deg[e[1]]++;
        }
        vector<long long> sum(values.begin(), values.end());
        queue<int> q;
        vector<bool> removed(n, false);
        for (int i = 0; i < n; i++) if (deg[i] == 1) q.push(i);
        int components = 0;
        int processed = 0;
        vector<int> curDeg = deg;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            removed[u] = true;
            processed++;
            if (sum[u] % k == 0) components++;
            for (int v : adj[u]) {
                if (!removed[v]) {
                    if (sum[u] % k == 0) {
                        // contributes 0
                    } else {
                        sum[v] += sum[u];
                    }
                    curDeg[v]--;
                    if (curDeg[v] == 1 && processed < n) q.push(v);
                }
            }
            if (processed == n) break;
        }
        return components;
    }
};
