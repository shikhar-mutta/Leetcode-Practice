// Link: https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V+E)  SC: O(V+E)
// Approach: Kahn's algorithm (topological sort via BFS) — a valid ordering exists iff all nodes get processed
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.push(i);
        int processed = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            processed++;
            for (int v : adj[u]) if (--indeg[v] == 0) q.push(v);
        }
        return processed == numCourses;
    }
};
