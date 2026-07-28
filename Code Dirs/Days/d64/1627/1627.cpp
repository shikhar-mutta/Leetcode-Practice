// Link: https://leetcode.com/problems/graph-connectivity-with-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> par;
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) par[a] = b;
    }
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        for (int d = threshold + 1; d <= n; d++) {
            for (int m = 2 * d; m <= n; m += d) unite(d, m);
        }
        vector<bool> res;
        for (auto& q : queries) res.push_back(find(q[0]) == find(q[1]));
        return res;
    }
};
