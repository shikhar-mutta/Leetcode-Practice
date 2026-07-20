// Link: https://leetcode.com/problems/minimum-time-for-k-connected-components/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(n)
// Approach:
//   1. Sort the edges in descending order based on their weights.
//   2. Use a union-find data structure to keep track of connected components.
//   3. Iterate through the sorted edges and for each edge, check if it connects two different components.
//   4. If it does, merge the components and update the number of connected components.
//   5. If the number of connected components is greater than or equal to k, update the answer with the current edge weight.
//   6. Continue until all edges are processed
class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges, int k)
    {
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] > b[2]; });
        vector<int> par(n);
        iota(par.begin(), par.end(), 0);
        auto find = [&](int x)
        {
            while (par[x] != x)
                x = par[x] = par[par[x]];
            return x;
        };
        int comp = n, m = edges.size(), ans = 0, i = 0;
        while (i < m)
        {
            int tau = edges[i][2];
            if (comp >= k)
                ans = tau;
            while (i < m && edges[i][2] == tau)
            {
                int a = find(edges[i][0]), b = find(edges[i][1]);
                if (a != b)
                {
                    par[a] = b;
                    comp--;
                }
                i++;
            }
        }
        if (comp >= k)
            ans = 0;
        return ans;
    }
};
