// Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: find each node's parent via a DFS from the root (node 0),
// then walk Bob's fixed path from his start node up to the root recording
// the time he reaches each node on it. Then DFS from the root as Alice,
// tracking elapsed time and running income: a node's amount is collected
// in full if Alice arrives strictly before Bob, halved if they arrive
// simultaneously, and skipped if Bob arrives first. Since Alice must stop
// at a leaf, only leaf incomes are candidates for the answer.
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        bobTime.assign(n, INT_MAX);
        vector<int> parent(n, -1);
        findParents(0, -1, adj, parent);

        int t = 0;
        for (int cur = bob; cur != -1; cur = parent[cur]) {
            bobTime[cur] = t++;
        }

        best = INT_MIN;
        dfs(0, -1, 0, 0, adj, amount);
        return best;
    }

private:
    vector<int> bobTime;
    int best;

    void findParents(int u, int par, vector<vector<int>>& adj,
                     vector<int>& parent) {
        parent[u] = par;
        for (int v : adj[u])
            if (v != par)
                findParents(v, u, adj, parent);
    }

    void dfs(int u, int par, int time, int income, vector<vector<int>>& adj,
             vector<int>& amount) {
        if (time < bobTime[u])
            income += amount[u]; // Alice first
        else if (time == bobTime[u])
            income += amount[u] / 2; // simultaneous: split

        bool isLeaf = true;
        for (int v : adj[u]) {
            if (v == par)
                continue;
            isLeaf = false;
            dfs(v, u, time + 1, income, adj, amount);
        }
        if (isLeaf)
            best = max(best, income);
    }
};
