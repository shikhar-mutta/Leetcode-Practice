// Link: https://leetcode.com/problems/course-schedule-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(V + E), SC: O(V + E) — DFS topological sort (post-order reversed)
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
            adj[p[1]].push_back(p[0]); // to take p[0], finish p[1] first: edge p[1] -> p[0]

        vector<int> state(numCourses, 0); // 0 = unvisited, 1 = in progress, 2 = done
        vector<int> order;
        bool hasCycle = false;

        function<void(int)> dfs = [&](int u)
        {
            state[u] = 1;
            for (int v : adj[u])
            {
                if (state[v] == 0)
                    dfs(v);
                else if (state[v] == 1) // back edge -> cycle
                {
                    hasCycle = true;
                    return;
                }
            }
            state[u] = 2;
            order.push_back(u);
        };

        for (int i = 0; i < numCourses && !hasCycle; i++)
            if (state[i] == 0)
                dfs(i);

        if (hasCycle)
            return {};

        reverse(order.begin(), order.end());
        return order;
    }
};
