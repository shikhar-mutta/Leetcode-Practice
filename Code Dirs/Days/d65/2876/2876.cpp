// Link: https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: functional graph (one outgoing edge per node). Detect cycles via a per-run
// step-index marker; every cycle node's answer is the cycle length. Then multi-source BFS on
// the reverse edges from all cycle nodes outward: each tail node's answer is 1 + its successor's.
class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n, -1);
        vector<int> visited(n, 0), runId(n, -1), stepOf(n, -1);

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int cur = i, step = 0;
            while (cur != -1 && !visited[cur]) {
                visited[cur] = 1;
                runId[cur] = i;
                stepOf[cur] = step++;
                cur = edges[cur];
            }
            if (cur != -1 && runId[cur] == i) {
                int cycleLen = step - stepOf[cur];
                int node = cur;
                do {
                    ans[node] = cycleLen;
                    node = edges[node];
                } while (node != cur);
            }
        }

        vector<vector<int>> rev(n);
        for (int i = 0; i < n; i++) rev[edges[i]].push_back(i);

        queue<int> q;
        for (int i = 0; i < n; i++) if (ans[i] != -1) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int p : rev[u]) {
                if (ans[p] != -1) continue;
                ans[p] = ans[u] + 1;
                q.push(p);
            }
        }
        return ans;
    }
};
