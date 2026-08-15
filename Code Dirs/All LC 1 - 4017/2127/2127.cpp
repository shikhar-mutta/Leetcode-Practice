// Link: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) indeg[favorite[i]]++;
        vector<int> dist(n, 0);
        vector<bool> removed(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            removed[u] = true;
            int v = favorite[u];
            dist[v] = max(dist[v], dist[u] + 1);
            if (--indeg[v] == 0) q.push(v);
        }

        int longestCycle = 0;
        long long armsSum = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (removed[i] || visited[i]) continue;
            vector<int> cycle;
            int u = i;
            while (!visited[u]) {
                visited[u] = true;
                cycle.push_back(u);
                u = favorite[u];
            }
            int len = cycle.size();
            if (len == 2) {
                int a = cycle[0], b = cycle[1];
                armsSum += (long long)dist[a] + dist[b] + 2;
            } else {
                longestCycle = max(longestCycle, len);
            }
        }
        return (int)max((long long)longestCycle, armsSum);
    }
};
