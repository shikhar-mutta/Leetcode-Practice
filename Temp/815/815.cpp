// Link: https://leetcode.com/problems/bus-routes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * m) SC: O(n^2)
// Approach: build a stop->routes map; BFS over routes (not stops) — from the current route, jump to any route sharing a stop with it, tracking bus-count. Start by enqueueing all routes containing source; done when a route containing target is reached.
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < n; i++) for (int stop : routes[i]) stopToRoutes[stop].push_back(i);

        vector<bool> visitedRoute(n, false);
        queue<int> q;
        for (int r : stopToRoutes[source]) { q.push(r); visitedRoute[r] = true; }
        int buses = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int r = q.front(); q.pop();
                for (int stop : routes[r]) {
                    if (stop == target) return buses;
                    for (int nr : stopToRoutes[stop]) {
                        if (!visitedRoute[nr]) { visitedRoute[nr] = true; q.push(nr); }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};
