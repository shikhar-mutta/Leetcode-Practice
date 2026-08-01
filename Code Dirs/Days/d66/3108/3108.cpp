// Link: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m + q)  SC: O(n)
// Approach: Use union-find to group nodes into connected components. For each component, compute the bitwise AND of all edge weights in that component. For each query, check if the two nodes are in the same component and return the precomputed AND value or -1 if they are not connected.
static const auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int par[100001];
int cost[100001];

class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges,
                            vector<vector<int>> &query)
    {
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
            cost[i] = -1;
        }
        for (const auto &v : edges)
        {
            uni(v[0], v[1], v[2]);
        }
        const int q = query.size();
        std::vector<int> res;
        res.reserve(q);
        for (const auto &v : query)
        {
            int px = find_par(v[0]), py = find_par(v[1]);
            res.push_back(px == py ? cost[px] : -1);
        }
        return res;
    }

    void uni(int x, int y, int w)
    {
        int px = find_par(x);
        int py = find_par(y);
        cost[px] = cost[px] & cost[py] & w;
        par[py] = px;
    }

    int find_par(int x)
    {
        if (x != par[x])
        {
            return par[x] = find_par(par[x]);
        }
        return x;
    }
};
