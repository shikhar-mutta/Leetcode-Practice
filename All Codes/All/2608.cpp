// Link: https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + E), SC: O(N + E)
//  Approach: We can use DFS to find the shortest cycle in a graph. We can keep track of the depth of each node and the parent of each node. If we encounter a node that has already been visited and is not the parent of the current node, then we have found a cycle. We can update the answer with the length of the cycle. We can repeat this process for all nodes in the graph. Finally, we can return the length of the shortest cycle found.
int ans;
int dep[1000];
vector<vector<int>> conn;
class Solution
{
public:
    void dfs(int cur, int par, int d)
    {
        dep[cur] = d;
        for (auto sub : conn[cur])
        {
            if (sub != par)
            {
                if (dep[sub] > d + 1)
                {
                    // explore another path and it is possible to find a shorter
                    // cycle
                    dfs(sub, cur, d + 1);
                }
                else if (dep[sub] < d)
                {
                    // cycle detected
                    ans = min(ans, d - dep[sub] + 1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ans = INT_MAX;
        conn.clear();
        conn.resize(n);
        for (int i = 0; i < n; dep[i++] = INT_MAX)
        {
        }
        for (int i = 0, m = edges.size(); i < m; ++i)
        {
            conn[edges[i][0]].push_back(edges[i][1]);
            conn[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0, j; i < n; ++i)
        {
            if (dep[i] == INT_MAX) // DFS on each connected sub-graph
                dfs(i, -1, 0);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};