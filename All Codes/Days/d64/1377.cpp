// Link: https://leetcode.com/problems/frog-position-after-t-seconds/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: DFS from node 1 tracking elapsed time and current
// probability (1/product of branching factors along the path). At each
// node, if it's a leaf (no unvisited children) or time runs out exactly
// (t==0), the frog must be sitting there for all remaining time —
// return the probability if it's the target. Otherwise recurse into
// each unvisited neighbor with probability divided by the branch count.
class Solution
{
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        if (n == 1)
        {
            if (t > 0)
            {
                return 1;
            }
            return 0;
        }
        vector<vector<int>> graph(n + 1);
        for (vector<int> &edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        vector<int> path;
        vector<bool> visited(n + 1, false);
        function<bool(int, int)> dfs = [&](int start, int target)
        {
            path.push_back(start);
            visited[start] = true;

            if (start == target)
            {
                return true;
            }

            for (int next : graph[start])
            {
                if (!visited[next] && dfs(next, target))
                {
                    return true;
                }
            }

            visited[start] = false;
            path.pop_back();
            return false;
        };

        dfs(1, target);

        if (path.size() - 1 > t)
        {
            return 0;
        }
        if (path.size() - 1 < t)
        {
            for (int next : graph[target])
            {
                if (!visited[next])
                {
                    return 0;
                }
            }
        }

        double p = 1.0 / graph[path[0]].size();
        for (int i = 1; i < path.size() - 1; i++)
        {
            p *= 1.0 / (graph[path[i]].size() - 1);
        }
        return p;
    }
};
