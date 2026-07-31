// Link: https://leetcode.com/problems/maximum-path-quality-of-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: exponential in edges but bounded (maxTime constraint keeps branching
//  small in practice)  SC: O(n) recursion depth
//  Approach: DFS from node 0, allowed to revisit nodes, tracking remaining
//  time budget and a visited-count array so a value is only added once. Every
//  time we return to node 0, update the best quality found.
class Solution
{
public:
    int n;
    int answer = 0;

    vector<vector<pair<int, int>>> adj;
    vector<int> dist;
    vector<int> visited;

    void dijkstra()
    {
        dist.assign(n, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [cost, cur] = pq.top();
            pq.pop();

            if (cost > dist[cur])
                continue;

            for (auto [next, weight] : adj[cur])
            {
                int nextCost = cost + weight;

                if (nextCost >= dist[next])
                    continue;

                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    void dfs(int cur, int remainTime, int quality, vector<int> &values)
    {
        // 처음 방문한 경우에만 value 추가
        if (visited[cur] == 0)
        {
            quality += values[cur];
        }

        visited[cur]++;

        // 0으로 돌아왔다면 유효한 경로
        if (cur == 0)
        {
            answer = max(answer, quality);
        }

        for (auto [next, cost] : adj[cur])
        {

            // next로 이동한 후에도
            // 0으로 돌아올 시간이 있어야 함
            if (cost + dist[next] > remainTime)
                continue;

            dfs(next, remainTime - cost, quality, values);
        }

        // 백트래킹
        visited[cur]--;
    }

    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                           int maxTime)
    {
        n = values.size();

        adj.assign(n, {});
        visited.assign(n, 0);

        for (auto &edge : edges)
        {
            int a = edge[0];
            int b = edge[1];
            int time = edge[2];

            adj[a].push_back({b, time});
            adj[b].push_back({a, time});
        }

        dijkstra();

        dfs(0, maxTime, 0, values);

        return answer;
    }
};