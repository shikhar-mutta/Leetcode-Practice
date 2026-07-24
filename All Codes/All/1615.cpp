// Link: https://leetcode.com/problems/maximal-network-rank/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(n^2)
    // Approach:
    //  1. We will create a degree array to store the degree of each city.
    //  2. We will create an adjacency matrix to store the roads between the cities.
    //  3. We will iterate through all the pairs of cities and calculate the network rank
    //  4. The network rank of a pair of cities is the sum of their degrees
    //     minus 1 if they are directly connected by a road.
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> deg(n, 0);
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        for (auto &r : roads)
        {
            ++deg[r[0]];
            ++deg[r[1]];
            adj[r[0]][r[1]] = adj[r[1]][r[0]] = true;
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                res = max(res, deg[i] + deg[j] - (adj[i][j] ? 1 : 0));
        return res;
    }
};