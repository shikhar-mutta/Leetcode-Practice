// Link: https://leetcode.com/problems/minimize-malware-spread-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        sort(initial.begin(), initial.end());
        unordered_set<int> initSet(initial.begin(), initial.end());

        int best = initial[0], bestInfected = INT_MAX;
        for (int removed : initial) {
            vector<bool> visited(n, false);
            visited[removed] = true;
            int infected = 0;
            for (int start : initial) {
                if (start == removed || visited[start]) continue;
                queue<int> q;
                q.push(start);
                visited[start] = true;
                infected++;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v = 0; v < n; v++) {
                        if (graph[u][v] == 1 && !visited[v]) {
                            visited[v] = true;
                            infected++;
                            q.push(v);
                        }
                    }
                }
            }
            if (infected < bestInfected) {
                bestInfected = infected;
                best = removed;
            }
        }
        return best;
    }
};
