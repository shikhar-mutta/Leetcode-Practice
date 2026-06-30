// Link: https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Flood-fill every city reachable from i.
    void dfs(int i, vector<vector<int>> &g, vector<bool> &seen)
    {
        seen[i] = true;
        // Visit all cities j connected to city i.
        for (int j = 0; j < (int)g.size(); j++)
            if (g[i][j] && !seen[j])
                dfs(j, g, seen);
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), provinces = 0;
        vector<bool> seen(n, false);
        for (int i = 0; i < n; i++)
            if (!seen[i])
            {
                provinces++;
                dfs(i, isConnected, seen);
            }
        return provinces;
    }
};
