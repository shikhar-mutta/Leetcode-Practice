// Link: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E * log(V)) SC: O(V + E)
// Approach: We can use Dijkstra's algorithm to find the minimum cost to reach the destination within the given time. We maintain a priority queue to explore the nodes with the least cost first, and we keep track of the minimum time and cost to reach each node. If we reach the destination node, we return the cost; if we exhaust all possibilities without reaching the destination within the time limit, we return -1.
class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges,
                vector<int> &passingFees)
    {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> graph(n);
        for (const auto &e : edges)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<int> minCostAt(n, INT_MAX);
        vector<int> minTimeAt(n, INT_MAX);
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        pq.push({passingFees[0], {0, 0}});
        minTimeAt[0] = 0, minCostAt[0] = passingFees[0];
        while (!pq.empty())
        {
            auto [nCost, nD] = pq.top();
            pq.pop();
            auto [nTime, node] = nD;
            if (node == (n - 1))
                return nCost;
            if (minTimeAt[node] < nTime && minCostAt[node] < nCost)
                continue;
            for (const auto &[next, eTime] : graph[node])
            {
                if (nTime + eTime <= maxTime)
                {
                    if (minTimeAt[next] > nTime + eTime)
                    {
                        minTimeAt[next] = nTime + eTime;
                        pq.push(
                            {nCost + passingFees[next], {nTime + eTime, next}});
                    }
                    else if (minCostAt[next] > nCost + passingFees[next])
                    {
                        minCostAt[next] = nCost + passingFees[next];
                        pq.push(
                            {nCost + passingFees[next], {nTime + eTime, next}});
                    }
                }
            }
        }
        return -1;
    }
};