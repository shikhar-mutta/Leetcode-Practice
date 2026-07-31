// Link: https://leetcode.com/problems/minimize-the-total-price-of-the-trips/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m + n) = O(n + m), SC: O(n + m) for graph, O(n) for cnt, O(n) for price
// Approach: We can use DFS to find the path from source to destination for each trip and increment the count of each node in the path. Then we can use DP to find the minimum total price by considering two cases for each node: not halving the price or halving the price. We can return the minimum of these two cases for the root node.
class Solution
{
public:
    vector<vector<int>> g;
    vector<int> cnt, price;

    bool dfsPath(int u, int p, int target)
    {
        if (u == target)
        {
            cnt[u]++;
            return true;
        }
        for (int v : g[u])
        {
            if (v == p)
                continue;
            if (dfsPath(v, u, target))
            {
                cnt[u]++;
                return true;
            }
        }
        return false;
    }

    pair<int, int> dfsDP(int u, int p)
    {
        int notHalf = cnt[u] * price[u];
        int half = cnt[u] * (price[u] / 2);

        for (int v : g[u])
        {
            if (v == p)
                continue;
            auto [a, b] = dfsDP(v, u);
            notHalf += min(a, b);
            half += a;
        }

        return {notHalf, half};
    }

    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price,
                          vector<vector<int>> &trips)
    {
        this->price = price;
        g.assign(n, {});
        cnt.assign(n, 0);

        for (auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        for (auto &t : trips)
            dfsPath(t[0], -1, t[1]);

        auto [a, b] = dfsDP(0, -1);
        return min(a, b);
    }
};