// Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + e * alpha(n))  SC: O(n)
// Approach: union-find, union endpoints of each edge, count distinct roots
class Solution {
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        int count = n;
        for (auto& e : edges) {
            int ra = find(e[0]), rb = find(e[1]);
            if (ra != rb) { parent[ra] = rb; count--; }
        }
        return count;
    }
};
