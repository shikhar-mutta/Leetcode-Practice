// Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n1^2 + n2^2) SC: O(n1 + n2)
// Approach: for node i in tree1, connecting it to some node j in tree2
// gives count1[i] (nodes within k of i in tree1) + count2[j] (nodes within
// k-1 of j in tree2, the extra 1 being the bridge edge). The best choice
// of j doesn't depend on i, so precompute best2 = max over j of count2[j]
// once, then answer[i] = count1[i] + best2.
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<vector<int>> adj1(n1), adj2(n2);
        for (auto& e : edges1) { adj1[e[0]].push_back(e[1]); adj1[e[1]].push_back(e[0]); }
        for (auto& e : edges2) { adj2[e[0]].push_back(e[1]); adj2[e[1]].push_back(e[0]); }

        auto countWithin = [](vector<vector<int>>& adj, int n, int s, int limit) {
            if (limit < 0) return 0;
            vector<int> dist(n, -1);
            queue<int> q;
            dist[s] = 0; q.push(s);
            int cnt = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    if (dist[v] <= limit) { cnt++; q.push(v); }
                }
            }
            return cnt;
        };

        int best2 = 0;
        for (int j = 0; j < n2; j++) best2 = max(best2, countWithin(adj2, n2, j, k - 1));

        vector<int> ans(n1);
        for (int i = 0; i < n1; i++) ans[i] = countWithin(adj1, n1, i, k) + best2;
        return ans;
    }
};
