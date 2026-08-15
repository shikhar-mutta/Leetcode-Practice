// Link: https://leetcode.com/problems/minimum-increments-to-equalize-leaf-paths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: post-order DFS. Each subtree returns the target root-to-leaf
//  path sum all its leaves must share. For an internal node, gather each
//  child's returned target; increasing that ONE child's own cost is
//  enough to fix every leaf path under it (the delta propagates to all
//  its leaves), so we only need to change nodes for children whose target
//  differs from the most common one — pick the mode as this node's shared
//  target to minimize changes, and return mode + cost[node] upward.
class Solution
{
public:
    int ans = 0;
    long long dfs(vector<vector<int>> &graph, int u, vector<int> &cost)
    {
        long long maxi = INT_MIN, cnt = 0;
        if (graph[u].size() == 0)
            return cost[u];
        for (auto it = graph[u].begin(); it != graph[u].end(); ++it)
        {
            long long val = dfs(graph, *it, cost);
            if (val >= maxi)
            {
                if (maxi == val)
                    cnt++;
                else
                    cnt = 1;
                maxi = val;
            }
            // cout<<val<<" "<<maxi<<" "<<cnt<<endl;
        }
        // cout<<maxi<<" "<<cnt<<endl;
        ans += graph[u].size() - cnt;
        return maxi + cost[u];
    }
    int minIncrease(int n, vector<vector<int>> &edges, vector<int> &cost)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i][1] == 0)
                sort(edges[i].begin(), edges[i].end());
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        long long val = dfs(graph, 0, cost);
        return ans;
    }
};