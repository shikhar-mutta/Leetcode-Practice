// Link: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &r : roads) {
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }

        long long fuel = 0;
        function<int(int,int)> dfs = [&](int u, int parent) -> int {
            int count = 1;
            for (int v : adj[u]) {
                if (v == parent) continue;
                count += dfs(v, u);
            }
            if (u != 0) fuel += (count + seats - 1) / seats;
            return count;
        };
        dfs(0, -1);
        return fuel;
    }
};
