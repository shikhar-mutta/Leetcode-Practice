// Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& e : edges) {
            int ra = find(e[0]), rb = find(e[1]);
            if (ra != rb) parent[ra] = rb;
        }
        return find(source) == find(destination);
    }
};
