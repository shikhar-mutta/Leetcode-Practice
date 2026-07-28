// Link: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: functional graph (each node out-degree 1). Peel leaves via
// indegree BFS to compute longest chain length feeding into each node.
// Then find cycles: answer is max(longest cycle of length>2, sum over all
// mutual 2-cycles of (chain[a]+chain[b]+2)).
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) indeg[favorite[i]]++;
        vector<int> chain(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
        vector<bool> removed(n, false);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            removed[u] = true;
            int v = favorite[u];
            chain[v] = max(chain[v], chain[u] + 1);
            if (--indeg[v] == 0) q.push(v);
        }
        int longestCycle = 0;
        long long twoCycleSum = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (removed[i] || visited[i]) continue;
            vector<int> cyc;
            int u = i;
            while (!visited[u]) {
                visited[u] = true;
                cyc.push_back(u);
                u = favorite[u];
            }
            int len = cyc.size();
            if (len == 2) {
                int a = cyc[0], b = cyc[1];
                twoCycleSum += (long long)chain[a] + chain[b] + 2;
            } else {
                longestCycle = max(longestCycle, len);
            }
        }
        return (int)max((long long)longestCycle, twoCycleSum);
    }
};
