// Link: https://leetcode.com/problems/minimize-maximum-component-cost/description/

#include <bits/stdc++.h>
using namespace std;

template <class T>
using V = vector<T>;
#define vi V<int>

// TC: O(E log E) + O(E α(V)) = O(E log E) where E is the number of edges and V is the number of vertices
// SC: O(V) where V is the number of vertices
// Approach:
// 1. Sort the edges in non-decreasing order of their weights.
// 2. Initialize a DSU (Disjoint Set Union) data structure to keep track of the connected components.
// 3. Iterate through the sorted edges and for each edge, check if the two vertices are in the same connected component using the DSU. If they are not, unite them and decrement the count of connected components.
// 4. If the count of connected components is less than or equal to k, return the weight of the current edge as the minimum cost to achieve k connected components.
// 5. If the loop ends and the count of connected components is still greater than k, return 0 as it is not possible to achieve k connected components with the given edges.
// 6. The DSU data structure is implemented using path compression and union by size to optimize the time complexity of the union and find operations.

struct DSU
{
    int n;
    vi e;
    void init(int _n)
    {
        n = _n;
        e = vi(n, -1);
    }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return false;
        if (e[x] > e[y])
            swap(x, y);
        n--;
        e[x] += e[y], e[y] = x;
        return true;
    }
};

class Solution
{
public:
    int minCost(int n, vector<vector<int>> &edges, int k)
    {
        if (k == n)
            return 0;
        vector<pair<int, pair<int, int>>> ed;
        for (const auto &e : edges)
        {
            ed.push_back({e[2], {e[0], e[1]}});
        }
        sort(ed.begin(), ed.end());
        DSU dsu;
        dsu.init(n);
        int cnt = n;
        for (auto &e : ed)
        {
            int u = e.second.first;
            int v = e.second.second;
            if (dsu.unite(u, v))
            {
                --cnt;
                if (cnt <= k)
                {
                    return e.first;
                }
            }
        }
        return 0;
    }
};