// Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E * α(V)) where E is the number of edges, V is the number of vertices, and α is the inverse Ackermann function
// SC: O(V) where V is the number of vertices
// Approach:
//   1. We will use the union-find (disjoint set) data structure to keep track of connected components in the graph.
//   2. We will initialize each vertex as its own parent and then iterate through the edges to union the connected vertices.
//   3. Finally, we will check if the source and destination vertices have the same parent, indicating that there is a valid path between them.
class Solution
{
    vector<int> parent;
    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto &e : edges)
            parent[find(e[0])] = find(e[1]);
        return find(source) == find(destination);
    }
};