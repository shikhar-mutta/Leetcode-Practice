// Link: https://leetcode.com/problems/minimize-malware-spread/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 * alpha(n))  SC: O(n)
// Approach: union-find the graph into connected components, tracking
// each component's size. For each initially infected node, count how
// many initial nodes share its component; if it's the sole infected
// node in its component, removing it saves that whole component's
// size. Pick the candidate with the largest such savings (ties broken
// by smallest node index); if no candidate is alone in its component,
// removing any one saves nothing, so return the smallest index.
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
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (graph[i][j]) unite(i, j);

        vector<int> compSize(n, 0);
        for (int i = 0; i < n; i++) compSize[find(i)]++;

        unordered_map<int,int> infectedCount;
        for (int x : initial) infectedCount[find(x)]++;

        sort(initial.begin(), initial.end());
        int best = initial[0], bestSave = -1;
        for (int x : initial) {
            int root = find(x);
            if (infectedCount[root] == 1) {
                int save = compSize[root];
                if (save > bestSave) { bestSave = save; best = x; }
            }
        }
        return best;
    }
};
