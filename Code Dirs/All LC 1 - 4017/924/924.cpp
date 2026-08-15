// Link: https://leetcode.com/problems/minimize-malware-spread/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][j] == 1) {
                    int ri = find(i), rj = find(j);
                    if (ri != rj) parent[ri] = rj;
                }

        vector<int> size(n, 0);
        for (int i = 0; i < n; i++) size[find(i)]++;

        vector<int> count(n, 0);
        for (int x : initial) count[find(x)]++;

        sort(initial.begin(), initial.end());
        int best = initial[0], bestSave = -1;
        for (int x : initial) {
            int root = find(x);
            if (count[root] == 1) {
                if (size[root] > bestSave) {
                    bestSave = size[root];
                    best = x;
                }
            }
        }
        return best;
    }
};
