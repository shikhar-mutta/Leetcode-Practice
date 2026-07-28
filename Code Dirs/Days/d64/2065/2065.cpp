// Link: https://leetcode.com/problems/maximum-path-quality-of-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: exponential in edges but bounded (maxTime constraint keeps branching
// small in practice)  SC: O(n) recursion depth
// Approach: DFS from node 0, allowed to revisit nodes, tracking remaining
// time budget and a visited-count array so a value is only added once. Every
// time we return to node 0, update the best quality found.
class Solution {
    vector<vector<pair<int,int>>> adj;
    vector<int> values;
    vector<int> visitCount;
    int best = 0;

    void dfs(int u, int remTime, int curQuality) {
        if (u == 0) best = max(best, curQuality);
        for (auto& [v, w] : adj[u]) {
            if (w > remTime) continue;
            bool firstVisit = (visitCount[v] == 0);
            visitCount[v]++;
            dfs(v, remTime - w, curQuality + (firstVisit ? values[v] : 0));
            visitCount[v]--;
        }
    }
public:
    int maximalPathQuality(vector<int>& values_, vector<vector<int>>& edges, int maxTime) {
        values = values_;
        int n = values.size();
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        visitCount.assign(n, 0);
        visitCount[0] = 1;
        dfs(0, maxTime, values[0]);
        return best;
    }
};
