// Link: https://leetcode.com/problems/unit-conversion-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: We can represent the conversions as a directed graph, where each unit is a node and each conversion is a directed edge with a weight equal to the conversion factor. We can then perform a depth-first search (DFS) starting from each unit to calculate the total conversion factor for that unit. The result for each unit will be the product of the conversion factors along the path from that unit to the base unit (unit 0). We can store the results in an array and return it at the end.
class Solution
{
public:
    void dfs(int u, auto &p, auto &ans)
    {
        int mod = 1e9 + 7;
        if (ans[u] != 0)
            return;
        ans[u] = 1;
        auto &[v, cf] = p[u];
        dfs(v, p, ans);
        ans[u] = 1LL * ans[u] * ans[v] % mod * cf % mod;
    }
    vector<int> baseUnitConversions(vector<vector<int>> &conversions)
    {
        int n = size(conversions) + 1;
        vector<int> ans(n);
        vector<pair<int, int>> p(n);
        p[0] = {0, 1};
        for (auto &e : conversions)
            p[e[1]] = {e[0], e[2]};
        for (int i = 0; i < n; ++i)
            dfs(i, p, ans);
        return ans;
    }
};