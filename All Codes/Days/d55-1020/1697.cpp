// Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(ElogE + QlogE) where E is the number of edges and Q is the number of queries
// SC: O(N) where N is the number of nodes in the graph
// Approach:
// 1. Sort the edges based on their weights in ascending order.
// 2. Create a custom DSU class that supports union by rank and path compression.
// 3. For each edge in the sorted list, perform union operation on the two nodes of the edge and store the weight of the edge in the DSU.
// 4. For each query, check if the two nodes in the query are connected in the DSU and if the weight of the edge connecting them is less than the limit specified in the query. If both conditions are satisfied, return true, otherwise return false.
class Solution
{
public:
    class custom_DSU
    {
    private:
        vector<int> parent;
        vector<int> rank;
        vector<int> weight;

    public:
        custom_DSU(int n)
        {
            parent.resize(n + 1, 0);
            rank.resize(n + 1, 0);
            weight.resize(n + 1, 0);

            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int find(int x, int lim)
        {
            if (parent[x] == x)
                return x;

            while (x != parent[x])
            {
                if (weight[x] >= lim)
                {
                    break;
                }
                x = parent[x];
            } // moving up till the root of this tree till some weight doesn't violate us
            return x;
        }

        void unionbyrank(int u, int v, int lim)
        {
            int root_u = find(u, INT_MAX);
            int root_v = find(v, INT_MAX);

            if (root_u == root_v)
                return;

            if (rank[root_u] < rank[root_v])
            {
                parent[root_u] = root_v;
                weight[root_u] = lim;
            }
            else if (rank[root_u] > rank[root_v])
            {
                parent[root_v] = root_u;
                weight[root_v] = lim;
            }
            else
            {
                rank[root_u]++;
                parent[root_v] = root_u;
                weight[root_v] = lim;
            }

            return;
        }
    };
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgelist, vector<vector<int>> &quer)
    {
        sort(edgelist.begin(), edgelist.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        custom_DSU ds(n);
        for (int i = 0; i < edgelist.size(); i++)
        {
            ds.unionbyrank(edgelist[i][0], edgelist[i][1], edgelist[i][2]);
        }

        vector<bool> ans(quer.size(), false);

        for (int i = 0; i < quer.size(); i++)
        {
            if (ds.find(quer[i][0], quer[i][2]) == ds.find(quer[i][1], quer[i][2]))
                ans[i] = true;
        }

        return ans;
    }
};