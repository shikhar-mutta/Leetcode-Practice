// Link: https://leetcode.com/problems/collect-coins-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach: We can use a queue to keep track of the leaf nodes that do not have any coins. We can then remove these leaf nodes from the tree and update the degree of their parent nodes. We can repeat this process until there are no more leaf nodes without coins. After that, we can perform two more rounds of removing leaf nodes to account for the fact that we can collect coins from the parent nodes of the leaf nodes. Finally, we can count the number of remaining nodes in the tree, which will be the number of nodes that can be collected.
class Solution
{
public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges)
    {

        int n = coins.size();
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1 && coins[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {

            int node = q.front();
            q.pop();

            if (degree[node] == 0)
                continue;
            degree[node]--;

            for (auto &it : adj[node])
            {

                if (degree[it] == 0)
                    continue;

                degree[it]--;
                if (degree[it] == 1 && coins[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // phase 2;
        for (int i = 0; i < 2; i++)
        {

            for (int j = 0; j < n; j++)
            {
                if (degree[j] == 1)
                {
                    q.push(j);
                }
            }

            int m = q.size();
            for (int sz = 0; sz < m; sz++)
            {

                int node = q.front();
                q.pop();

                if (degree[node] == 0)
                    continue;
                degree[node]--;

                for (auto &it : adj[node])
                {
                    if (degree[it] == 0)
                        continue;

                    degree[it]--;
                    if (degree[it] == 1)
                    {
                        q.push(it);
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += degree[i];
        }

        return cnt;
    }
};
