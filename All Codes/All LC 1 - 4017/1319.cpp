// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m * α(n)) ~ O(n + m)
// SC: O(n) + O(n) ~ O(n)
// Approach: Union-Find to count connected components.
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // Need at least n-1 cables total to connect n computers.
        if ((int)connections.size() < n - 1)
            return -1;

        // Union-Find to count connected components.
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x)
        {
            while (parent[x] != x)
                x = parent[x] = parent[parent[x]];
            return x;
        };

        int components = n;
        for (auto &c : connections)
        {
            int a = find(c[0]), b = find(c[1]);
            if (a != b)
            {
                parent[a] = b;
                components--;
            }
        }

        // components-1 moves reconnect all groups (we have enough spare cables).
        return components - 1;
    }
};
