// Link: https://leetcode.com/problems/parallel-courses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1, 0);
        for (auto& r : relations) {
            adj[r[0]].push_back(r[1]);
            indeg[r[1]]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);

        int studied = 0, semesters = 0;
        while (!q.empty()) {
            int sz = q.size();
            semesters++;
            for (int i = 0; i < sz; i++) {
                int u = q.front(); q.pop();
                studied++;
                for (int v : adj[u]) {
                    if (--indeg[v] == 0) q.push(v);
                }
            }
        }
        return studied == n ? semesters : -1;
    }
};
