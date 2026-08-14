// Link: https://leetcode.com/problems/parallel-courses-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1, 0);
        for (auto& r : relations) {
            adj[r[0]].push_back(r[1]);
            indeg[r[1]]++;
        }
        vector<int> finish(n + 1, 0);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                finish[i] = time[i - 1];
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                finish[v] = max(finish[v], finish[u] + time[v - 1]);
                if (--indeg[v] == 0) q.push(v);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, finish[i]);
        return ans;
    }
};
