// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^3) + O(n^2) ~ O(n^3)
    // SC: O(n^2) + O(n) ~ O(n^2)
    // Approach: Floyd-Warshall: all-pairs shortest paths.
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for (auto &e : edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        // Floyd-Warshall: all-pairs shortest paths.
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        // Pick the city with fewest reachable neighbors within threshold;
        // ties broken by greatest index.
        int best = -1, minCount = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
                if (i != j && dist[i][j] <= distanceThreshold)
                    count++;
            if (count <= minCount)
            {
                minCount = count;
                best = i;
            }
        }
        return best;
    }
};
