// Link: https://leetcode.com/problems/minimum-cost-to-buy-apples-ii/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n * (m log m + n log n))  SC: O(n^2)
//Approach: We can use Dijkstra's algorithm to find the minimum cost to buy apples from each city. We can use a priority queue to keep track of the minimum cost to reach each city. We can use two arrays to keep track of the minimum cost to reach each city using roads and using prices. We can update the minimum cost to reach each city using the prices and the roads. We can return the minimum cost to reach each city.  
class Solution
{
    using ll = long long;
    static constexpr ll INF = 1e18;

public:
    vector<int> minCost(int n, vector<int> &prices,
                        vector<vector<int>> &roads)
    {
        vector<vector<pair<int, pair<int, int>>>> adj(n);
        for (auto &r : roads)
        {
            adj[r[0]].push_back({r[1], {r[2], r[3]}});
            adj[r[1]].push_back({r[0], {r[2], r[3]}});
        }
        vector<int> ans = prices;
        for (int src = 0; src < n; src++)
        {
            vector<ll> c1(n, INF);
            vector<ll> c2(n, INF);
            priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                           greater<pair<ll, int>>>
                pq;
            c1[src] = 0;
            pq.push({0, src});
            while (!pq.empty())
            {
                auto [dist, x] = pq.top();
                pq.pop();
                if (dist > c1[x])
                    continue;
                for (const auto &[y, cstt] : adj[x])
                {
                    ll nd = dist + cstt.first;
                    if (nd < c1[y])
                    {
                        c1[y] = nd;
                        if (nd < ans[src])
                            pq.push({nd, y});
                    }
                }
            }
            c2[src] = 0;
            pq.push({0, src});
            while (!pq.empty())
            {
                auto [dist, x] = pq.top();
                pq.pop();
                if (dist > c2[x])
                    continue;
                ans[src] = min((ll)ans[src], c1[x] + (ll)prices[x] + c2[x]);
                for (const auto &[y, cstt] : adj[x])
                {
                    ll nd = dist + 1LL * cstt.first * cstt.second;
                    if (nd < c2[y])
                    {
                        c2[y] = nd;
                        if (nd < ans[src])
                            pq.push({nd, y});
                    }
                }
            }
        }
        return ans;
    }
};