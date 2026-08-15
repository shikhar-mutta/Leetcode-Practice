// Link: https://leetcode.com/problems/count-connected-components-in-lcm-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) parent[a] = b;
    }

    int countComponents(vector<int>& nums, int threshold) {
        parent.resize(threshold + 1);
        iota(parent.begin(), parent.end(), 0);

        for (int v : nums) {
            if (v > threshold) continue;
            for (long long m = 2LL * v; m <= threshold; m += v) {
                unite(v, (int)m);
            }
        }

        unordered_set<int> roots;
        int isolatedCount = 0;
        for (int v : nums) {
            if (v > threshold) isolatedCount++;
            else roots.insert(find(v));
        }

        return (int)roots.size() + isolatedCount;
    }
};
