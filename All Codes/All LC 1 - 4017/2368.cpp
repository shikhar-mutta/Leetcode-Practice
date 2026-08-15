// Link: https://leetcode.com/problems/reachable-nodes-with-restrictions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), where n is the number of nodes in the graph and m is the number of edges in the graph.
// SC: O(n), where n is the number of nodes in the graph.
//  Approach:
//   1. We initialize three arrays: parentList, size, and rest. The parentList array is used to keep track of the parent of each node in the graph. The size array is used to keep track of the size of each connected component in the graph. The rest array is used to keep track of the restricted nodes in the graph.
//   2. We iterate through the restricted array and mark the restricted nodes in the rest array.
//   3. We iterate through the edges array and combine the nodes that are not restricted using the combine function. The combine function uses the union-find algorithm to combine the connected components of the graph.
//   4. Finally, we return the size of the connected component that contains node 0, which represents the number of reachable nodes from node 0 without visiting any restricted nodes.
class Solution
{
public:
    bool *rest;
    int *parentList;
    int *size;
    int parent0sz;

    int parent(int v)
    {
        if (parentList[v] == v)
        {
            return v;
        }

        return parent(parentList[v]);
    }

    int combine(int v1, int v2)
    {
        int pv1 = parent(v1);
        int pv2 = parent(v2);
        if (pv1 == pv2)
        {
            return 0;
        }
        if (pv2 == 0 || pv1 != 0)
        {
            parentList[pv1] = pv2;
            size[pv2] += size[pv1];
        }
        else if (pv1 == 0)
        {
            parentList[pv2] = pv1;
            size[pv1] += size[pv2];
        }
        return 1;
    }

    int reachableNodes(int n, vector<vector<int>> &edges,
                       vector<int> &restricted)
    {
        parentList = new int[n]();
        size = new int[n]();
        rest = new bool[n]();
        for (int i = 0; i < n; i++)
        {
            parentList[i] = i;
            size[i] = 1;
        }

        for (int i = 0; i < restricted.size(); i++)
        {
            rest[restricted[i]] = true;
        }

        for (int i = 0; i < edges.size(); i++)
        {
            if (rest[edges[i][0]] || rest[edges[i][1]])
            {
                continue;
            }

            combine(edges[i][0], edges[i][1]);
        }
        return size[0];
    }
};