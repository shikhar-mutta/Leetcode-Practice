// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n - 1) return -1;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& c : connections) unite(c[0], c[1]);
        unordered_set<int> roots;
        for (int i = 0; i < n; i++) roots.insert(find(i));
        return roots.size() - 1;
    }
};
