// Link: https://leetcode.com/problems/graph-connectivity-with-threshold/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(n)
// Approach: We can use Disjoint Set Union (DSU) to efficiently manage the connectivity of the graph. We iterate through all numbers greater than the threshold and unite them with their multiples.
class Solution
{
    struct DSU
    {
        vector<int> par, ranks;
        DSU(int n)
        {
            par.resize(n, 1);
            ranks.resize(n, 0);
            for (int i = 0; i < n; i++)
                par[i] = i;
        }
        int find(int x)
        {
            if (x == par[x])
                return x;
            return par[x] = find(par[x]);
        }
        bool unite(int u, int v)
        {
            u = find(u);
            v = find(v);
            if (u == v)
                return false;

            if (ranks[u] == ranks[v])
                ranks[u]++;
            if (ranks[u] < ranks[v])
                swap(u, v);
            par[v] = u;

            return true;
        }
    };

public:
    vector<bool> areConnected(int n, int th, vector<vector<int>> &qu)
    {
        int m = qu.size();
        if (th < 1)
        {
            vector<bool> ans(m, true);
            return ans;
        }

        DSU dsu(n + 1);
        for (int num = th + 1; num <= n; num++)
        {
            for (int m = 2; m * num <= n; m++)
            {
                int n2 = m * num;
                // cout<< "Uniting (" << num << "," << n2 << endl;
                dsu.unite(num, n2);
            }
        }

        vector<bool> ans(m, false);

        for (int j = 0; j < m; j++)
        {
            int x = qu[j][0];
            int y = qu[j][1];
            int px = dsu.find(x);
            int py = dsu.find(y);
            // cout << "( " << px << ", " << py <<")" << endl ;
            if (px == py)
                ans[j] = true;
        }

        return ans;
    }
};