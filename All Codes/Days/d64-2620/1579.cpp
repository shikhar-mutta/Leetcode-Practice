// Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m) SC: O(n)
// Approach: We can use Disjoint Set Union (DSU) to solve this problem. We can create two DSU instances, one for Alice and one for Bob. We can iterate through all the edges and for each edge, we can check if it is a type 3 edge (i.e., an edge that can be used by both Alice and Bob). If it is a type 3 edge, we can unite the two nodes in both DSU instances. If it is a type 1 edge (i.e., an edge that can only be used by Alice), we can unite the two nodes in the Alice DSU instance. If it is a type 2 edge (i.e., an edge that can only be used by Bob), we can unite the two nodes in the Bob DSU instance. Finally, we can check if both DSU instances have only one component (i.e., if both Alice and Bob can traverse the entire graph). If they do, we return the number of edges that were not used. Otherwise, we return -1.
class DSU
{
public:
    vector<int> par, rnk;
    int comps;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), comps(n)
    {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rnk[a] < rnk[b])
            swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
        comps--;
        return true;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DSU alice(n), bob(n);
        int used = 0;
        for (auto &e : edges)
        {
            if (e[0] == 3)
            {
                bool a = alice.unite(e[1], e[2]);
                bool b = bob.unite(e[1], e[2]);
                if (a || b)
                    used++;
            }
        }
        for (auto &e : edges)
        {
            if (e[0] == 1)
            {
                if (alice.unite(e[1], e[2]))
                    used++;
            }
        }
        for (auto &e : edges)
        {
            if (e[0] == 2)
            {
                if (bob.unite(e[1], e[2]))
                    used++;
            }
        }
        if (alice.comps != 1 || bob.comps != 1)
            return -1;
        return (int)edges.size() - used;
    }
};
