// Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n+m)log(n)) SC: O(n+m)
// Approach: Dijkstra's algorithm with a priority queue, where each state is (node, consecutive character count). The priority queue is ordered by the current path weight. For each node, we track the minimum consecutive character count seen so far to avoid revisiting states that would exceed the limit k.
class Solution
{
public:
    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k)
    {
        if (n == 1)
            return 0;

        vector<vector<pair<int, int>>> adj(n);
        for (const auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<array<int, 3>, vector<array<int, 3>>,
                       greater<array<int, 3>>>
            minQ;
        vector<int> charFrequency(n, INT_MAX);
        minQ.push({0, 0, 1});

        while (!minQ.empty())
        {
            auto [w, u, charF] = minQ.top();
            minQ.pop();

            if (charF >= charFrequency[u])
                continue;
            charFrequency[u] = charF;

            if (u == n - 1)
                return w;

            for (const auto &e : adj[u])
            {
                int nextCharF = (labels[u] == labels[e.first]) ? charF + 1 : 1;

                if (nextCharF <= k)
                    minQ.push({w + e.second, e.first, nextCharF});
            }
        }

        return -1;
    }
};