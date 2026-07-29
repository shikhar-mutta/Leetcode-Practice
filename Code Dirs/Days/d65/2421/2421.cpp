// Link: https://leetcode.com/problems/number-of-good-paths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((N+E) log N), SC: O(N)
// Approach: Kruskal-style union by increasing max(vals[u],vals[v]) per edge. Each DSU root tracks
// the max value in its component and how many nodes currently hold that max. When merging via an
// edge whose weight equals both endpoints' component max, add product of counts (good path pairs),
// then combine counts appropriately. Start answer at N for trivial single-node paths.
class Solution {
public:
    vector<int> parent, maxVal, maxCount;

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n); iota(parent.begin(), parent.end(), 0);
        maxVal = vals;
        maxCount.assign(n, 1);

        sort(edges.begin(), edges.end(), [&](auto& a, auto& b) {
            return max(vals[a[0]], vals[a[1]]) < max(vals[b[0]], vals[b[1]]);
        });

        long long ans = n;
        for (auto& e : edges) {
            int ru = find(e[0]), rv = find(e[1]);
            if (ru == rv) continue;
            if (maxVal[ru] == maxVal[rv]) {
                ans += (long long)maxCount[ru] * maxCount[rv];
                parent[ru] = rv;
                maxCount[rv] += maxCount[ru];
            } else if (maxVal[ru] > maxVal[rv]) {
                parent[rv] = ru;
            } else {
                parent[ru] = rv;
            }
        }
        return (int)ans;
    }
};
