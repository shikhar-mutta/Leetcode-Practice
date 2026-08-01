// Link: https://leetcode.com/problems/minimum-time-to-reach-target-with-limited-power/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V)  SC: O(V + E)
// Approach: We can use Dijkstra's algorithm to find the minimum time to reach the target node. We can use a priority queue to store the nodes and their corresponding time and power. We can use a vector to store the settled nodes and their corresponding power. We can use a vector to store the adjacency list of the graph. We can use a vector to store the cost of each node. We can use a vector to store the edges of the graph. We can use a vector to store the source and target nodes. We can use a vector to store the minimum time and maximum power to reach the target node.
// save the current time and power in a single long long variable by shifting the time and power to the left and adding the node index. We can use a priority queue to store the nodes and their corresponding time and power. We can use a vector to store the settled nodes and their corresponding power. We can use a vector to store the adjacency list of the graph. We can use a vector to store the cost of each node. We can use a vector to store the edges of the graph. We can use a vector to store the source and target nodes. We can use a vector to store the minimum time and maximum power to reach the target node.
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

typedef pair<int, int> pr;
vector<pr> adj[1000];
long tmp, tc;
int settled[1000], pc, u;

class Solution
{
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>> &edges,
                                      int power, vector<int> &cost, int source,
                                      int target)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        long cu;

        priority_queue<long, vector<long>, greater<long>> pq;

        for (int i = 0; i != n; ++i)
            adj[i].clear();

        for (auto &v : edges)
        {
            adj[v[0]].push_back({v[1], v[2]});
        }

        fill(settled, settled + n, -1);

        pq.push(source);

        while (!pq.empty())
        {
            tmp = pq.top();
            pq.pop();

            tc = tmp >> 20;
            pc = (tmp >> 10) & 0x3FF;
            u = tmp & 0x3FF;

            int cur = power - pc;
            if (cur <= settled[u])
                continue;
            settled[u] = cur;

            if (u == target)
                return {tc, cur};

            cu = cost[u];
            if (cur < cu)
                continue;

            int rem = cur - cu;

            for (auto &[v, w] : adj[u])
            {
                if (rem > settled[v])
                    pq.push(((tc + w) << 20) + ((power - rem) << 10) + v);
            }
        }

        return {-1, -1};
    }
};
