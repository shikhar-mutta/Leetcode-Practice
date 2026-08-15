// Link: https://leetcode.com/problems/maximum-path-quality-of-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int>* valuesPtr;
    vector<int> visitCount;
    int best = 0;

    void dfs(int node, int remaining, int curSum) {
        if (node == 0) best = max(best, curSum);
        for (auto& [next, w] : adj[node]) {
            if (w > remaining) continue;
            bool firstVisit = (visitCount[next] == 0);
            visitCount[next]++;
            dfs(next, remaining - w, curSum + (firstVisit ? (*valuesPtr)[next] : 0));
            visitCount[next]--;
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        valuesPtr = &values;
        visitCount.assign(n, 0);
        visitCount[0] = 1;
        dfs(0, maxTime, values[0]);
        return best;
    }
};
