// Link: https://leetcode.com/problems/tree-of-coprimes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 50) SC: O(n * 50)
//  Approach: DFS + Precomputation
//  We can use a DFS to traverse the tree and for each node, we can check if there is a coprime ancestor. We can use a precomputation to find the coprime numbers for each value in the range 1 to 50. We can use a closest array to store the closest ancestor for each value in the range 1 to 50. We can use a result array to store the closest coprime ancestor for each node. We can return the result array after the DFS is complete.
//  We can use a helper function to find the GCD of two numbers. We can use a helper function to find the coprime numbers for each value in the range 1 to 50. We can use a helper function to find the closest ancestor for each value in the range 1 to 50. We can use a helper function to find the closest coprime ancestor for each node. We can return the result array after the DFS is complete.
class Solution
{
    static constexpr int MAX_VALUE = 50;

    static int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

    const vector<int> *nums;
    vector<vector<int>> adj;     // tree adjacency list
    vector<vector<int>> coprime; // coprime[v] = values in 1..50 coprime with v
    array<pair<int, int>, MAX_VALUE + 1>
        closest; // closest[value] = {node, depth} on current path
    vector<int> result;

    void dfs(int node, int depth, int parent)
    {
        int v = (*nums)[node];

        if (parent != -1 && v == (*nums)[parent])
        {
            result[node] = (v == 1) ? parent : result[parent];
        }
        else
        {
            int bestNode = -1, bestDepth = -1;
            for (int c : coprime[v])
            {
                if (closest[c].second > bestDepth)
                {
                    bestDepth = closest[c].second;
                    bestNode = closest[c].first;
                }
            }
            result[node] = bestNode;
        }

        pair<int, int> saved =
            closest[v];             // remember the previous closest with this value
        closest[v] = {node, depth}; // this node is now the closest with value v
        for (int next : adj[node])
            if (next != parent)
                dfs(next, depth + 1, node);
        closest[v] = saved; // restore on the way back up
    }

public:
    vector<int> getCoprimes(const vector<int> &nums,
                            vector<vector<int>> &edges)
    {
        this->nums = &nums;
        int n = nums.size();

        coprime.assign(MAX_VALUE + 1, {});
        for (int a = 1; a <= MAX_VALUE; a++)
            for (int b = 1; b <= MAX_VALUE; b++)
                if (gcd(a, b) == 1)
                    coprime[a].push_back(b);

        adj.assign(n, {});
        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        closest.fill({-1, -1});
        result.assign(n, -1);
        dfs(0, 0, -1);
        return result;
    }
};