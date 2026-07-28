// Link: https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((V+E) log V), SC: O(V+E)
// Approach: Standard Dijkstra from node 0, except a relaxed distance to a
// node is only accepted if it's also strictly less than that node's
// disappear time — arriving at or after disappearance means the node is
// already gone, so it's treated as unreachable via that path.
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
    {
        std::vector<int> dist (n, INT_MAX);
        dist [0] = 0;
        std::vector<std::vector<std::pair<int, int>>> neighbors (n);

        for (const std::vector<int>& e : edges)
        {
            neighbors [e [0]].emplace_back (e [2], e [1]);
            neighbors [e [1]].emplace_back (e [2], e [0]);
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.emplace (0, 0);

        while (! pq.empty ())
        {
            int parent = pq.top ().second;
            int parent_dist = pq.top ().first;
            pq.pop ();

            if (dist [parent] < parent_dist) continue;

            for (const std::pair<int, int>& neighbor_pair : neighbors [parent])
            {
                int neighbor = neighbor_pair.second;
                int weight = parent_dist + neighbor_pair.first;

                if (dist [neighbor] > weight && disappear [neighbor] > weight)
                {
                    dist [neighbor] = weight;
                    pq.emplace (weight, neighbor);
                }
            }
        }

        for (int& d : dist) if (d == INT_MAX) d = -1;
        return dist;
    }
};
