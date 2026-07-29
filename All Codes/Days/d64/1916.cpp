// Link: https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: The problem can be solved using combinatorics and depth-first search (DFS). We can represent the rooms and their connections as a tree structure, where each room is a node and the connections are edges. The number of ways to build the rooms can be calculated by considering the number of ways to arrange the rooms in each subtree, multiplied by the number of ways to arrange the subtrees themselves.
auto x = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp)
    {
        long long res = 1;
        base %= MOD;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n)
    {
        return power(n, MOD - 2);
    }

    int dfs(int node, const vector<vector<int>> &adj, vector<int> &subtree_size)
    {
        int size = 1;
        for (int child : adj[node])
        {
            size += dfs(child, adj, subtree_size);
        }
        return subtree_size[node] = size;
    }

public:
    int waysToBuildRooms(vector<int> &prevRoom)
    {
        int n = prevRoom.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; ++i)
        {
            adj[prevRoom[i]].push_back(i);
        }

        vector<int> subtree_size(n, 0);
        dfs(0, adj, subtree_size);

        long long numerator = 1;
        for (int i = 1; i <= n; ++i)
        {
            numerator = (numerator * i) % MOD;
        }

        long long denominator = 1;
        for (int i = 0; i < n; ++i)
        {
            denominator = (denominator * subtree_size[i]) % MOD;
        }

        long long ans = (numerator * modInverse(denominator)) % MOD;

        return ans;
    }
};