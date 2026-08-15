// Link: https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int cost = 0, edges = 0;
        for (auto& c : connections) {
            int ra = find(c[0]), rb = find(c[1]);
            if (ra != rb) {
                parent[ra] = rb;
                cost += c[2];
                edges++;
            }
        }
        return edges == n - 1 ? cost : -1;
    }
};
