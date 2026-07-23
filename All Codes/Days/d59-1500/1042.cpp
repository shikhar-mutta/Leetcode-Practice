// Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the number of gardens and m is the number of paths
    // SC: O(n + m) for the adjacency list and degree array
    //   Approach:
    //    1. We can use a greedy approach to assign colors to the gardens.
    //    2. We can create an adjacency list to represent the paths between the gardens
    //    3. We can iterate through the gardens and for each garden, we can check the colors of its adjacent gardens and assign the smallest color that is not used by its adjacent gardens
    //    4. We can use a bitmask to keep track of the colors used by the adjacent gardens and use the __builtin_ctz function to find the smallest color that is not used by the adjacent gardens
    //    5. Finally, we can return the colors assigned to the gardens
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        int adj[10005][3];
        int deg[10005] = {0};
        for (const auto &p : paths)
        {
            int u = p[0] - 1;
            int v = p[1] - 1;
            adj[u][deg[u]++] = v;
            adj[v][deg[v]++] = u;
        }

        vector<int> c(n, 0);
        for (int i = 0; i < n; i++)
        {
            int u = 0;

            for (int j = 0; j < deg[i]; j++)
            {
                u |= 1 << c[adj[i][j]];
            }

            c[i] = __builtin_ctz(~u & 0b11110);
        }

        return c;
    }
};