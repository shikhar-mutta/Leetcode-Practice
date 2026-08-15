// Link: https://leetcode.com/problems/graph-connectivity-with-threshold/description/

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

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        for (int d = threshold + 1; d <= n; d++) {
            for (int m = 2 * d; m <= n; m += d) {
                unite(d, m);
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }
        return ans;
    }
};
