// Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a != b) parent[a] = b;
        }
        unordered_map<int, long long> compSize;
        for (int i = 0; i < n; i++) compSize[find(i)]++;

        long long total = (long long)n * (n - 1) / 2;
        long long reachable = 0;
        for (auto& [root, sz] : compSize) reachable += sz * (sz - 1) / 2;
        return total - reachable;
    }
};
