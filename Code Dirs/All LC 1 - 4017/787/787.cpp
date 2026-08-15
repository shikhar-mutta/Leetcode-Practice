// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k*E) SC: O(n)
// Approach: Bellman-Ford limited to k+1 edges; each round relax all edges using the previous round's distances (snapshot), allowing at most k+1 total hops.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> next = dist;
            for (auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != INT_MAX && dist[u] + w < next[v]) next[v] = dist[u] + w;
            }
            dist = next;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
