// Link: https://leetcode.com/problems/count-connected-components-in-lcm-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(threshold log threshold), SC: O(threshold)
// Approach: any two divisors of the same m<=threshold end up connected (their lcm divides m, so
// lcm<=threshold). Build a DSU over 1..threshold and union every present value v with all its
// multiples up to threshold — this transitively links any two values sharing a common multiple.
// A value > threshold can never satisfy lcm<=threshold (even with itself), so each such
// occurrence is its own isolated component. Count distinct DSU roots among present small values,
// plus one component per element exceeding threshold.
class Solution {
public:
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) { a = find(a); b = find(b); if (a != b) parent[a] = b; }

    int countComponents(vector<int>& nums, int threshold) {
        parent.resize(threshold + 1);
        iota(parent.begin(), parent.end(), 0);

        unordered_set<int> distinctSmall;
        int isolatedCount = 0;
        for (int v : nums) {
            if (v <= threshold) distinctSmall.insert(v);
            else isolatedCount++;
        }

        for (int v : distinctSmall) {
            for (long long m = 2LL * v; m <= threshold; m += v) unite(v, (int)m);
        }

        unordered_set<int> roots;
        for (int v : distinctSmall) roots.insert(find(v));

        return (int)roots.size() + isolatedCount;
    }
};
