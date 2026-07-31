// Link: https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + E), SC: O(N + E)
// Approach: The problem is to determine if it is possible to add edges to a graph such that all nodes have even degrees. The solution involves checking the degrees of the nodes and identifying the odd-degree nodes. If there are more than 4 odd-degree nodes, it is impossible to make all degrees even. If there are 0 or 2 odd-degree nodes, it is possible. If there are 4 odd-degree nodes, we need to check if we can connect them in pairs without creating a direct edge between any two odd-degree nodes. The solution uses a helper function to check the possibility of connecting two odd-degree nodes and returns true or false accordingly.
class Solution
{
private:
    bool isPoss2(int x, int y, vector<vector<int>> &edges, int n)
    {
        vector<bool> isNei(n, true);
        isNei[x] = false;
        isNei[y] = false;
        bool isDirect = true;
        for (const auto &edge : edges)
        {
            const auto &u = edge[0] - 1, v = edge[1] - 1;
            if (u == x || u == y)
                isNei[v] = false;
            if (v == x || v == y)
                isNei[u] = false;
            if ((u == x && v == y) || (u == y && v == x))
                isDirect = false;
        }
        if (isDirect)
            return true;
        for (int i = 0; i < n; ++i)
        {
            if (isNei[i])
                return true;
        }
        return false;
    }

public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        vector<bool> count(n, false);
        // vector<vector<bool>> adj(n,vector<bool> (n,false));
        for (const auto &edge : edges)
        {
            const auto &u = edge[0] - 1, v = edge[1] - 1;
            count[u] = !count[u], count[v] = !count[v];
            // adj[u][v] = true, adj[v][u] = true;
        }
        vector<int> odds;
        odds.reserve(4);
        for (int i = 0; i < n; ++i)
        {
            if (count[i])
            {
                if (odds.size() >= 4)
                    return false;
                odds.push_back(i);
            }
        }
        if ((odds.size() & 1) > 0)
            return false;
        if (odds.size() == 0)
            return true;

        if (odds.size() == 2)
            return isPoss2(odds[0], odds[1], edges, n);

        vector<vector<bool>> newAdj(4, vector<bool>(4, false));
        auto getIdx = [](int num, const vector<int> &odds)
        {
            for (int i = 0; i < 4; ++i)
            {
                if (num == odds[i])
                    return i;
            }
            return -1;
        };
        for (const auto &edge : edges)
        {
            const auto &u = edge[0] - 1, v = edge[1] - 1;
            int x = getIdx(u, odds), y = getIdx(v, odds);
            if (x == -1 || y == -1)
                continue;
            newAdj[x][y] = true, newAdj[y][x] = true;
        }

        if (!newAdj[0][1] && !newAdj[2][3])
            return true;
        if (!newAdj[0][2] && !newAdj[1][3])
            return true;
        if (!newAdj[0][3] && !newAdj[1][2])
            return true;
        return false;
    }
};