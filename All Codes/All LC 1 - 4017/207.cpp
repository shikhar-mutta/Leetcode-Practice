// Link: https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V + E), SC: O(V + E)
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto &p : prerequisites)
        { // p[1] -> p[0]
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indeg[i] == 0)
                q.push(i);

        int done = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            done++;
            for (int v : adj[u])
                if (--indeg[v] == 0)
                    q.push(v);
        }
        // If every course was emitted, the graph is acyclic.
        return done == numCourses;
    }
};

// class Solution {
// public:

//     bool bfs(int courseNum, vector<int>& status, vector<vector<int>>& adj) {
//         if (status[courseNum] == 1) {
//             return false;
//         }
//         if (status[courseNum] == 2) {
//             return true;
//         }
//         status[courseNum] = 1;

//         for (auto v : adj[courseNum]) {
//             if (!bfs(v, status, adj)) {
//                 return false;
//             }
//         }
//         status[courseNum] = 2;
//         return true;
//     }

//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         for (auto& p : prerequisites) adj[p[1]].push_back(p[0]);

//         vector<int> status(numCourses, 0);

//         for (int i = 0; i < numCourses; i++) {
//             if (status[i] == 0) {
//                 if (!bfs(i, status, adj)) {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };