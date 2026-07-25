// Link: https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n), n = specialRoads.size()
// SC: O(n)
// Approach: Dijkstra over a graph whose only "nodes of interest" are the
// entry points of each special road (walking directly, at Manhattan
// distance, is always an option and never needs its own node). dis[i] =
// cheapest cost to reach the START of special road i (walk there, or walk
// from some other road's exit). Relax by trying, from each road i popped
// off the heap, walking from its exit to every other road j's entry (or
// straight to target, updating ans) and to the target directly.
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target,
                    vector<vector<int>>& specialRoads) {

        auto dist = [](int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        };

        int n = specialRoads.size();

        vector<int> dis(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < n; i++) {
            dis[i] = dist(start[0], start[1], specialRoads[i][0],
                          specialRoads[i][1]) +
                     specialRoads[i][4];

            pq.push({dis[i], i});
        }

        int ans = dist(start[0], start[1], target[0], target[1]);

        while (!pq.empty()) {

            auto [cost, i] = pq.top();
            pq.pop();

            if (cost > dis[i])
                continue;

            ans = min(ans, cost + dist(specialRoads[i][2], specialRoads[i][3],
                                       target[0], target[1]));

            for (int j = 0; j < n; j++) {

                int newCost = cost +
                              dist(specialRoads[i][2], specialRoads[i][3],
                                   specialRoads[j][0], specialRoads[j][1]) +
                              specialRoads[j][4];

                if (newCost < dis[j]) {
                    dis[j] = newCost;
                    pq.push({newCost, j});
                }
            }
        }

        return ans;
    }
};
