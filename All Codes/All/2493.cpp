// Link: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N^2)
//  Approach: The problem can be solved using graph theory. We can represent the nodes and edges as a graph and check if the graph is bipartite. If the graph is not bipartite, we cannot divide the nodes into groups. If the graph is bipartite, we can use BFS to find the maximum distance from each node in the graph. The maximum distance will give us the number of groups we can divide the nodes into. We can sum up the maximum distances from each component to get the final answer. If any component is not bipartite, we return -1.
class Solution
{

    vector<vector<int>> g;
    vector<int> vis;
    vector<vector<int>> comp;

    int is_bipartite = true;

    void dfs(int node, int color, int idx)
    {
        vis[node] = color;
        comp[idx].push_back(node);
        for (auto v : g[node])
        {
            if (!vis[v])
            {
                dfs(v, 3 - color, idx);
            }
            else if (vis[node] == vis[v])
                is_bipartite = false;
        }
    }

    int bfs(int node)
    {
        queue<int> q;
        q.push(node);
        vector<int> dis(501, INT_MAX);
        dis[node] = 1;
        int mx = 1;
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            for (auto v : g[val])
            {
                if (dis[v] == INT_MAX)
                {
                    dis[v] = dis[val] + 1;
                    q.push(v);
                    mx = max(mx, dis[v]);
                }
            }
        }
        return mx;
    }

public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        g.resize(n + 1);
        comp.resize(n + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        vis.assign(n + 1, 0);
        int idxx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i, 1, idxx);
                idxx++;
            }
        }
        if (!is_bipartite)
            return -1;
        int ans = 0;
        for (auto &it : comp)
        {
            int temp = INT_MIN;
            for (auto node : it)
            {
                temp = max(temp, bfs(node));
            }
            if (temp != INT_MIN)
                ans += temp;
        }
        return ans;
    }
};