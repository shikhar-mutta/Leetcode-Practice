// Link: https://leetcode.com/problems/maximum-points-activated-with-one-addition/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)  SC: O(n)
//  Approach: We can use a disjoint set union (DSU) data structure to group points that share the same x or y coordinate. We first create two vectors of pairs, one for the x-coordinates and one for the y-coordinates, where each pair contains the coordinate value and the index of the point. We then sort these vectors and iterate through them to union points that share the same coordinate. Finally, we find the two largest groups of points and return their combined size plus one (for the additional point that can be added).
class dsu
{
public:
    vector<int> size;
    vector<int> parent;
    dsu(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findparent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findparent(parent[x]);
    }

    void unionby(int u, int v)
    {
        int pu = findparent(u);
        int pv = findparent(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution
{
public:
    int maxActivated(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 1)
            return 2;
        vector<pair<int, int>> xaxis;
        vector<pair<int, int>> yaxis;

        for (int i = 0; i < points.size(); i++)
        {
            xaxis.push_back({points[i][0], i});
            yaxis.push_back({points[i][1], i});
        }
        dsu ds(n);

        sort(xaxis.begin(), xaxis.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (xaxis[i].first == xaxis[i + 1].first)
            {
                ds.unionby(xaxis[i].second, xaxis[i + 1].second);
            }
        }
        sort(yaxis.begin(), yaxis.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (yaxis[i].first == yaxis[i + 1].first)
            {
                ds.unionby(yaxis[i].second, yaxis[i + 1].second);
            }
        }

        int max1 = 0;
        int max2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
            {
                if (ds.size[i] > max1)
                {
                    max2 = max1;
                    max1 = ds.size[i];
                }
                else if (ds.size[i] > max2)
                {
                    max2 = ds.size[i];
                }
            }
        }
        return max1 + max2 + 1;
    }
};
