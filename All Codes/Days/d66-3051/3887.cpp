// Link: https://leetcode.com/problems/incremental-even-weighted-cycle-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))  SC: O(n)
//  Approach: We can use a Disjoint Set Union (DSU) data structure to efficiently manage the connected components of the graph. We initialize a DSU with n nodes and iterate through the edges. For each edge, we check if the two nodes are already in the same connected component using the find operation. If they are in the same component, we check if the parity of the two nodes is equal to the weight of the edge. If they are equal, we increment the count of edges added. If they are not in the same component, we perform a union operation to merge the two components and update the parity of the nodes accordingly. Finally, we return the count of edges added.
class DSU
{
public:
    vector<int> parent, parity, size;
    int n;
    DSU(int n)
    {
        this->n = n;
        parent.resize(n);
        parity.resize(n, 0);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        int orig_parent = parent[u];
        parent[u] = find(parent[u]);
        parity[u] ^= parity[orig_parent];
        return parent[u];
    }

    void Union(int u, int v, int w)
    {
        int ru = find(u);
        int rv = find(v);
        if (size[ru] < size[rv])
        {
            swap(ru, rv);
            swap(u, v);
        }
        parent[rv] = ru;
        parity[rv] = parity[u] ^ parity[v] ^ w;
        size[ru] += size[rv];
    }
};
class Solution
{
public:
    int numberOfEdgesAdded(int n, vector<vector<int>> &edges)
    {
        DSU d(n);
        int count = 0;
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            int ru = d.find(u);
            int rv = d.find(v);
            if (ru == rv)
            {
                if ((d.parity[u] ^ d.parity[v]) == w)
                {
                    count++;
                }
            }
            else
            {
                d.Union(u, v, w);
                count++;
            }
        }
        return count;
    }
};
