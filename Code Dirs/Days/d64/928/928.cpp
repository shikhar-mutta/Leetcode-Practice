// Link: https://leetcode.com/problems/minimize-malware-spread-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * alpha(n))  SC: O(n)
// Approach: union-find using only edges between non-initial ("clean")
// nodes, giving components that would exist if all initial nodes were
// removed. For each initial node, look at which clean components its
// (non-initial) neighbors belong to; a component only ever gets
// infected if exactly one initial node touches it — removing that node
// saves the whole component. Sum a node's exclusive-component sizes as
// its "save" value, and pick the node with the largest save (ties
// broken by smallest index); if no node has any exclusive save, the
// answer is just the smallest initial index.
class Solution {
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) parent[a] = b;
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        unordered_set<int> infected(initial.begin(), initial.end());
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++) {
            if (infected.count(i)) continue;
            for (int j = i + 1; j < n; j++) {
                if (infected.count(j)) continue;
                if (graph[i][j]) unite(i, j);
            }
        }

        vector<int> compSize(n, 0);
        for (int i = 0; i < n; i++) if (!infected.count(i)) compSize[find(i)]++;

        unordered_map<int, unordered_set<int>> compTouchers; // root -> set of infected nodes touching it
        for (int x : initial) {
            for (int j = 0; j < n; j++) {
                if (graph[x][j] && !infected.count(j)) {
                    compTouchers[find(j)].insert(x);
                }
            }
        }

        unordered_map<int,long long> save;
        for (auto& [root, touchers] : compTouchers) {
            if (touchers.size() == 1) {
                int x = *touchers.begin();
                save[x] += compSize[root];
            }
        }

        sort(initial.begin(), initial.end());
        int best = initial[0];
        long long bestSave = -1;
        for (int x : initial) {
            long long s = save.count(x) ? save[x] : 0;
            if (s > bestSave) { bestSave = s; best = x; }
        }
        return best;
    }
};
