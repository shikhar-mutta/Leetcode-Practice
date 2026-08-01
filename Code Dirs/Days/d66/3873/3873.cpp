// Link: https://leetcode.com/problems/maximum-points-activated-with-one-addition/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: activation spreads transitively between points sharing an x or
// y coordinate, so points partition into connected components via
// union-find (union each point with the first-seen point sharing its x,
// and with the first-seen point sharing its y). A single new point can
// bridge at most two existing components (one via its x, one via its y),
// so the best choice picks the two largest components: answer = largest +
// second-largest + 1 (or just largest + 1 if only one component exists).
class Solution {
    vector<int> parent, sz;
    int find(int i) { return parent[i] == i ? i : parent[i] = find(parent[i]); }
    void unite(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri != rj) { parent[ri] = rj; sz[rj] += sz[ri]; }
    }
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);

        unordered_map<int,int> xFirst, yFirst;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            auto itx = xFirst.find(x);
            if (itx != xFirst.end()) unite(i, itx->second);
            else xFirst[x] = i;
            auto ity = yFirst.find(y);
            if (ity != yFirst.end()) unite(i, ity->second);
            else yFirst[y] = i;
        }

        vector<int> compSizes;
        for (int i = 0; i < n; i++) if (find(i) == i) compSizes.push_back(sz[i]);
        sort(compSizes.rbegin(), compSizes.rend());

        if (compSizes.size() >= 2) return compSizes[0] + compSizes[1] + 1;
        return compSizes[0] + 1;
    }
};
