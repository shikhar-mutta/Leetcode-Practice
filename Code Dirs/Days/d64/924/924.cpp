// Link: https://leetcode.com/problems/minimize-malware-spread/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: DSU. Build connected components, count infected nodes in each component. If a component has only one infected node, removing it will save the entire component. Return the node that saves the most nodes (tie-breaker: smallest index).
class DSU
{
private:
    vector<int> parent;
    vector<int> sz;

public:
    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return;

        if (sz[rootA] < sz[rootB])
            swap(rootA, rootB);

        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];
    }

    int getSize(int x) { return sz[find(x)]; }
};

class Solution
{
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {

        int n = graph.size();

        DSU dsu(n);

        // Build connected components
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (graph[i][j])
                    dsu.Union(i, j);
            }
        }

        unordered_map<int, int> infectedCount;

        // Count infected nodes in every component
        for (int node : initial)
        {
            infectedCount[dsu.find(node)]++;
        }

        sort(initial.begin(), initial.end());

        int ans = initial[0];
        int bestSaved = -1;

        for (int node : initial)
        {

            int root = dsu.find(node);

            // Another malware still exists in this component
            if (infectedCount[root] != 1)
                continue;

            int saved = dsu.getSize(root);

            if (saved > bestSaved)
            {
                bestSaved = saved;
                ans = node;
            }
        }

        return ans;
    }
};