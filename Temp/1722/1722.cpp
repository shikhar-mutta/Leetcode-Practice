// Link: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/

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
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        for (auto& s : allowedSwaps) unite(s[0], s[1]);

        unordered_map<int, multiset<int>> groups;
        for (int i = 0; i < n; i++) groups[find(i)].insert(source[i]);

        int mismatches = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            auto it = groups[root].find(target[i]);
            if (it != groups[root].end()) {
                groups[root].erase(it);
            } else {
                mismatches++;
            }
        }
        return mismatches;
    }
};
