// Link: https://leetcode.com/problems/graph-valid-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * alpha(n))  SC: O(n)
// Approach: a valid tree needs exactly n-1 edges and no cycles; union-find each edge, failing if
// both endpoints are already connected (cycle)
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() != n - 1) return false;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) return false;
            parent[a] = b;
        }
        return true;
    }
};
