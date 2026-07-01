// Link: https://leetcode.com/problems/find-eventual-safe-states/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(V + E), SC: O(V) — DFS three-color cycle detection
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0); // 0 = unvisited, 1 = visiting, 2 = safe

        function<bool(int)> dfs = [&](int u) -> bool
        {
            if (color[u] > 0)
                return color[u] == 2; // already resolved
            color[u] = 1;             // on current path
            for (int v : graph[u])
                if (!dfs(v)) // leads into a cycle -> unsafe
                    return false;
            color[u] = 2; // all paths terminate safely
            return true;
        };

        vector<int> res;
        for (int i = 0; i < n; i++)
            if (dfs(i))
                res.push_back(i); // i ascends -> output stays sorted
        return res;
    }
};
