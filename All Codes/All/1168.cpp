// Link: https://leetcode.com/problems/optimize-water-distribution-in-a-village/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<array<int,3>> edges;
        for (int i = 0; i < n; i++) edges.push_back({wells[i], 0, i+1});
        for (auto& p : pipes) edges.push_back({p[2], p[0], p[1]});
        sort(edges.begin(), edges.end());

        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };

        int cost = 0;
        for (auto& e : edges) {
            int ra = find(e[1]), rb = find(e[2]);
            if (ra != rb) {
                parent[ra] = rb;
                cost += e[0];
            }
        }
        return cost;
    }
};
