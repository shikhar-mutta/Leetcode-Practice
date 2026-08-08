// Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/

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

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a][2] < queries[b][2];
        });

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        vector<bool> ans(m, false);
        int edgeIdx = 0;
        for (int qi : idx) {
            int p = queries[qi][0], q = queries[qi][1], limit = queries[qi][2];
            while (edgeIdx < (int)edgeList.size() && edgeList[edgeIdx][2] < limit) {
                unite(edgeList[edgeIdx][0], edgeList[edgeIdx][1]);
                edgeIdx++;
            }
            ans[qi] = (find(p) == find(q));
        }
        return ans;
    }
};
