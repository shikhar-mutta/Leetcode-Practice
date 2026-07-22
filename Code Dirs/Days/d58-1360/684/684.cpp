// Link: https://leetcode.com/problems/redundant-connection/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * α(n)) where n is the number of edges and α is the inverse Ackermann function, which is very slow-growing and can be considered nearly constant for practical input sizes. We iterate through each edge and perform union-find operations.
// SC: O(n) for the parent and rank arrays used in the union-find data structure
//  Approach:
//  1. We use the union-find (disjoint set union) data structure to detect cycles in the graph formed by the edges.
//  2. We initialize a parent array where each node is its own parent and a rank array to keep track of the depth of the trees.
//  3. For each edge, we attempt to unite the two nodes. If they are already connected (i.e., they have the same root), it means adding this edge would create a cycle, and thus it is the redundant connection we are looking for.
//  4. We return the first edge that causes a cycle, which is the redundant connection.
class Solution
{
public:
    vector<int> parent, rank_;

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b)
    {
        int ra = find(a), rb = find(b);
        if (ra == rb)
            return false;
        if (rank_[ra] < rank_[rb])
            swap(ra, rb);
        parent[rb] = ra;
        if (rank_[ra] == rank_[rb])
            rank_[ra]++;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n + 1);
        rank_.assign(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        for (auto &e : edges)
        {
            if (!unite(e[0], e[1]))
                return e;
        }
        return {};
    }
};
