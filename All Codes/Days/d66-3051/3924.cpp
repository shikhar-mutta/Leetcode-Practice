// Link: https://leetcode.com/problems/minimum-threshold-path-with-limited-heavy-edges/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log E * (V+E))  SC: O(V+E)
// Approach: binary search the minimum threshold T (over sorted distinct edge weights) such that source can reach target using at most k "heavy" edges (weight > T). Feasibility for a fixed T is checked via 0-1 BFS: edges with weight > T cost 1 (heavy), others cost 0, giving the minimum number of heavy edges on any path; accept if that's <= k. Feasibility is monotonic in T (raising T can only turn heavy edges light), so binary search applies.
class Solution
{
public:
    int minimumThreshold(int n, vector<vector<int>> &edges, int source, int target, int k)
    {
        // Build graph adjacency list
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        int maxWeight = 0;
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            maxWeight = std::max(maxWeight, w);
        }

        // Helper function: 0-1 BFS to check if target is reachable with <= k heavy edges for threshold T
        auto isValidThreshold = [&](int T) -> bool
        {
            std::vector<int> dist(n, 1e9);
            std::deque<int> dq;

            dist[source] = 0;
            dq.push_back(source);

            while (!dq.empty())
            {
                int u = dq.front();
                dq.pop_front();

                if (u == target)
                {
                    return dist[target] <= k;
                }

                for (const auto &[v, w] : adj[u])
                {
                    int cost = (w > T) ? 1 : 0;
                    if (dist[u] + cost < dist[v])
                    {
                        dist[v] = dist[u] + cost;
                        if (cost == 0)
                        {
                            dq.push_front(v);
                        }
                        else
                        {
                            dq.push_back(v);
                        }
                    }
                }
            }
            return dist[target] <= k;
        };

        // If target is unreachable even with maximum threshold, return -1
        if (!isValidThreshold(maxWeight))
        {
            return -1;
        }

        // Binary search for the minimum threshold T
        int low = 0, high = maxWeight;
        int ans = maxWeight;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isValidThreshold(mid))
            {
                ans = mid;
                high = mid - 1; // Try finding a smaller valid threshold
            }
            else
            {
                low = mid + 1; // Threshold too small, increase it
            }
        }

        return ans;
    }
};
