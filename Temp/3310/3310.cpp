// Link: https://leetcode.com/problems/remove-methods-from-project/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& e : invocations) adj[e[0]].push_back(e[1]);

        vector<bool> suspicious(n, false);
        suspicious[k] = true;
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        for (auto& e : invocations) {
            if (!suspicious[e[0]] && suspicious[e[1]]) {
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) if (!suspicious[i]) res.push_back(i);
        return res;
    }
};
