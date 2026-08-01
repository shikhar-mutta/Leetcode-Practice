// Link: https://leetcode.com/problems/count-connected-subgraphs-with-even-node-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n * n)  SC: O(2^n)
// Approach: We can use bitmasking to represent the subgraphs. We can iterate through all the possible subgraphs and check if the subgraph is connected and if the sum of the nodes in the subgraph is even. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected. We can use a bitmask to represent the subgraph and use a BFS or DFS to check if the subgraph is connected.
class Solution
{
public:
    int evenSumSubgraphs(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        vector<int> adj(n);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u] |= (1 << v);
            adj[v] |= (1 << u);
        }
        int total = 1 << n;
        vector<int> reach(total, 0);
        vector<int> sum(total, 0);
        for (int mask = 1; mask < total; mask++)
        {
            int bit = __builtin_ctz(mask);
            int prev = mask & (mask - 1);
            sum[mask] = sum[prev] + nums[bit];
        }
        int ans = 0;
        for (int mask = 1; mask < total; mask++)
        {
            int start = __builtin_ctz(mask);
            int seen = 1 << start;
            int frontier = seen;
            while (frontier)
            {
                int next = 0;
                int temp = frontier;
                while (temp)
                {
                    int u = __builtin_ctz(temp);
                    temp &= temp - 1;
                    next |= adj[u];
                }
                next &= mask;
                next &= ~seen;
                seen |= next;
                frontier = next;
            }
            reach[mask] = seen;
            if (seen == mask && sum[mask] % 2 == 0)
                ans++;
        }
        return ans;
    }
};
