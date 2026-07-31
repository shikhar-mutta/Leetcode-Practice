// Link: https://leetcode.com/problems/bus-routes/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(sum(routes[i].size()))  SC: same
// Approach: build a map from stop -> list of routes serving it, then
// BFS over routes (not stops): start with all routes containing source,
// each BFS level represents one more bus ride; from a route, jump to
// every unvisited route sharing any stop, until a route containing
// target is reached.
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> stopToRoutes;
        for (int r = 0; r < n; r++)
            for (int stop : routes[r])
                stopToRoutes[stop].push_back(r);

        vector<bool> visitedRoute(n, false);
        queue<int> q;
        for (int r : stopToRoutes[source])
        {
            if (!visitedRoute[r])
            {
                visitedRoute[r] = true;
                q.push(r);
            }
        }

        int buses = 1;
        while (!q.empty())
        {
            int sz = q.size();
            for (int s = 0; s < sz; s++)
            {
                int r = q.front();
                q.pop();
                for (int stop : routes[r])
                {
                    if (stop == target)
                        return buses;
                    for (int nr : stopToRoutes[stop])
                    {
                        if (!visitedRoute[nr])
                        {
                            visitedRoute[nr] = true;
                            q.push(nr);
                        }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};
