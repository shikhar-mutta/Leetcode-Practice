// Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countWithinK(vector<vector<int>>& adj, int k) {
        int n = adj.size();
        vector<int> res(n, 0);
        for (int s = 0; s < n; s++) {
            vector<int> dist(n, -1);
            queue<int> q;
            dist[s] = 0;
            q.push(s);
            int cnt = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1 && dist[u] + 1 <= k) {
                        dist[v] = dist[u] + 1;
                        cnt++;
                        q.push(v);
                    }
                }
            }
            res[s] = cnt;
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) { adj1[e[0]].push_back(e[1]); adj1[e[1]].push_back(e[0]); }
        for (auto& e : edges2) { adj2[e[0]].push_back(e[1]); adj2[e[1]].push_back(e[0]); }

        vector<int> cnt1 = countWithinK(adj1, k);
        int maxTree2 = 0;
        if (k - 1 >= 0) {
            vector<int> cnt2 = countWithinK(adj2, k - 1);
            for (int x : cnt2) maxTree2 = max(maxTree2, x);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = cnt1[i] + maxTree2;
        return res;
    }
};
