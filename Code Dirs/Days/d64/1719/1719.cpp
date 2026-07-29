// Link: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: Graph + DFS
//  We can represent the pairs as a graph and check if the graph can be reconstructed into a tree. We can use DFS to traverse the graph and check if the tree can be reconstructed. If there is more than one way to reconstruct the tree, we return 2. If there is no way to reconstruct the tree, we return 0. Otherwise, we return 1.
class Solution
{
public:
    int checkWays(vector<vector<int>> &pairs)
    {
        vector<int> adj[501];
        bool connected[501][501] = {false};
        vector<int> nodes;
        for (const auto &p : pairs)
        {
            int x = p[0], y = p[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            connected[x][y] = true;
            connected[y][x] = true;
        }
        for (int i = 1; i <= 500; ++i)
        {
            if (!adj[i].empty())
            {
                nodes.push_back(i);
                connected[i][i] = true;
            }
        }
        sort(nodes.begin(), nodes.end(),
             [&](int a, int b)
             { return adj[a].size() < adj[b].size(); });
        int n = nodes.size();
        int result = 1;
        for (int i = 0; i < n; ++i)
        {
            int u = nodes[i];
            int parent = -1;
            for (int j = i + 1; j < n; ++j)
            {
                int v = nodes[j];
                if (connected[u][v])
                {
                    parent = v;
                    break;
                }
            }
            if (parent == -1)
            {
                if (adj[u].size() != n - 1)
                    return 0;
            }
            else
            {
                for (int neighbor : adj[u])
                {
                    if (!connected[parent][neighbor])
                        return 0;
                }
                if (adj[u].size() == adj[parent].size())
                {
                    result = 2;
                }
            }
        }
        return result;
    }
};
