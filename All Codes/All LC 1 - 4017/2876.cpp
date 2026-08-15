// Link: https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
//  Approach: We can use a DFS to traverse the directed graph. We can keep track of the state of each node (unvisited, visiting, visited) and the number of nodes visited from each node. If we encounter a node that is already being visited, we have found a cycle and we can calculate the length of the cycle and update the number of nodes visited for each node in the cycle. If we encounter a node that has already been visited, we can simply return the number of nodes visited from that node. Otherwise, we mark the node as visiting and recursively visit its neighbor.
class Solution
{
public:
    vector<int> res, state, edges;

    int dfs(int u)
    {
        if (state[u] == 2)
            return res[u];
        if (state[u] == 1)
        {
            int v = edges[u];
            int len = 1;
            while (v != u)
            {
                len++;
                v = edges[v];
            }
            v = u;
            res[v] = len;
            state[v] = 2;
            v = edges[v];
            while (v != u)
            {
                res[v] = len;
                state[v] = 2;
                v = edges[v];
            }
            return res[u];
        }

        state[u] = 1;
        int next = edges[u];
        int val = dfs(next);
        if (res[u] == 0)
            res[u] = val + 1;
        state[u] = 2;
        return res[u];
    }

    vector<int> countVisitedNodes(vector<int> &edgesInput)
    {
        edges = edgesInput;
        int n = edges.size();
        res.assign(n, 0);
        state.assign(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (state[i] == 0)
                dfs(i);
        }
        return res;
    }
};
