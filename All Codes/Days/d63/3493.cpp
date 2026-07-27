// Link: https://leetcode.com/problems/properties-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * maxSetSize) SC: O(n)
// Approach: union-find. For each pair (i,j), connect them if the size of
// the intersection of their property sets is >= k. Answer is the number
// of resulting components.
class Solution {
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) { parent[find(a)] = find(b); }
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        vector<unordered_set<int>> sets(n);
        for (int i = 0; i < n; i++) sets[i] = unordered_set<int>(properties[i].begin(), properties[i].end());

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int common = 0;
                auto& small = sets[i].size() < sets[j].size() ? sets[i] : sets[j];
                auto& big = sets[i].size() < sets[j].size() ? sets[j] : sets[i];
                for (int v : small) if (big.count(v)) common++;
                if (common >= k) unite(i, j);
            }
        }

        unordered_set<int> roots;
        for (int i = 0; i < n; i++) roots.insert(find(i));
        return roots.size();
    }
};
