// Link: https://leetcode.com/problems/maximum-area-rectangle-with-point-constraints-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> tree;
    int treeN;

    void buildTree(vector<int>& ys) {
        treeN = ys.size();
        tree.assign(4 * max(treeN, 1), {});
        function<void(int,int,int)> build = [&](int node, int l, int r) {
            if (l == r) { tree[node] = {ys[l]}; return; }
            int mid = (l + r) / 2;
            build(node*2, l, mid);
            build(node*2+1, mid+1, r);
            merge(tree[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(), back_inserter(tree[node]));
        };
        if (treeN > 0) build(1, 0, treeN - 1);
    }

    int queryCount(int node, int l, int r, int ql, int qr, int y1, int y2) {
        if (qr < l || r < ql || ql > qr) return 0;
        if (ql <= l && r <= qr) {
            auto lo = lower_bound(tree[node].begin(), tree[node].end(), y1);
            auto hi = upper_bound(tree[node].begin(), tree[node].end(), y2);
            return (int)(hi - lo);
        }
        int mid = (l + r) / 2;
        return queryCount(node*2, l, mid, ql, qr, y1, y2) + queryCount(node*2+1, mid+1, r, ql, qr, y1, y2);
    }

    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        int n = xCoord.size();
        vector<pair<int,int>> pts(n);
        for (int i = 0; i < n; i++) pts[i] = {xCoord[i], yCoord[i]};
        sort(pts.begin(), pts.end());

        vector<int> xsSorted(n), ysArr(n);
        for (int i = 0; i < n; i++) { xsSorted[i] = pts[i].first; ysArr[i] = pts[i].second; }
        buildTree(ysArr);

        map<int, vector<int>> byX;
        for (int i = 0; i < n; i++) byX[pts[i].first].push_back(pts[i].second);
        for (auto& [x, ys] : byX) sort(ys.begin(), ys.end());

        map<pair<int,int>, int> lastX;
        long long best = -1;

        for (auto& [x, ys] : byX) {
            for (int i = 0; i + 1 < (int)ys.size(); i++) {
                pair<int,int> key = {ys[i], ys[i+1]};
                auto it = lastX.find(key);
                if (it != lastX.end()) {
                    int xPrev = it->second;
                    int lo = upper_bound(xsSorted.begin(), xsSorted.end(), xPrev) - xsSorted.begin();
                    int hi = lower_bound(xsSorted.begin(), xsSorted.end(), x) - xsSorted.begin() - 1;
                    bool empty = true;
                    if (lo <= hi && treeN > 0) {
                        int cnt = queryCount(1, 0, treeN - 1, lo, hi, ys[i], ys[i+1]);
                        empty = (cnt == 0);
                    }
                    if (empty) {
                        long long area = (long long)(x - xPrev) * (ys[i+1] - ys[i]);
                        best = max(best, area);
                    }
                }
                lastX[key] = x;
            }
        }

        return best;
    }
};
