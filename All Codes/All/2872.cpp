// Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
//  Approach: We can use a queue to perform a BFS on the tree. We can keep track of the degree of each node and the value of each node modulo k. We can start by adding all the leaf nodes to the queue. Then, we can process each node in the queue by removing it from the tree and updating the value of its parent node. If the value of the current node is divisible by k, we can increment the answer. We can continue this process until we have processed all the nodes in the tree. Finally, we can return the answer plus one to account for the root node.
class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k)
    {
        if (n == 1)
            return 1;
        vector<int> adj(n), idg(n);

        for (auto &e : edges)
        {
            adj[e[0]] ^= e[1];
            adj[e[1]] ^= e[0];
            idg[e[0]]++;
            idg[e[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (idg[i] == 1)
                q.emplace(i);
        }

        int res = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            int nei = adj[cur];
            adj[nei] ^= cur;
            if (--idg[nei] == 1)
                q.emplace(nei);
            values[cur] %= k;
            if (!values[cur])
                res++;
            values[nei] += values[cur];
            values[nei] %= k;
        }

        return res;
    }
};
