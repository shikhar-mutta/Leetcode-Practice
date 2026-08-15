// Link: https://leetcode.com/problems/length-of-the-longest-increasing-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct FenwickMax {
        vector<int> tree;
        int n;
        FenwickMax(int n) : tree(n + 1, 0), n(n) {}
        void update(int i, int val) { // 1-indexed
            for (; i <= n; i += i & (-i)) tree[i] = max(tree[i], val);
        }
        int query(int i) { // max over [1..i], 1-indexed
            int res = 0;
            for (; i > 0; i -= i & (-i)) res = max(res, tree[i]);
            return res;
        }
    };

    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        vector<int> xs(n), ys(n);
        for (int i = 0; i < n; i++) { xs[i] = coordinates[i][0]; ys[i] = coordinates[i][1]; }

        vector<int> sortedY = ys;
        sort(sortedY.begin(), sortedY.end());
        sortedY.erase(unique(sortedY.begin(), sortedY.end()), sortedY.end());
        int m = sortedY.size();
        vector<int> rank(n);
        for (int i = 0; i < n; i++) rank[i] = lower_bound(sortedY.begin(), sortedY.end(), ys[i]) - sortedY.begin();

        vector<int> lenEnd(n, 0), lenStart(n, 0);

        // LEN_END: sort by x asc, y desc for ties
        {
            vector<int> order(n);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int a, int b) {
                if (xs[a] != xs[b]) return xs[a] < xs[b];
                return ys[a] > ys[b];
            });
            FenwickMax fw(m);
            for (int idx : order) {
                int r = rank[idx] + 1; // 1-indexed
                int best = fw.query(r - 1);
                lenEnd[idx] = best + 1;
                fw.update(r, lenEnd[idx]);
            }
        }

        // LEN_START: sort by x desc, y asc for ties; transform rank to reuse prefix-max
        {
            vector<int> order(n);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int a, int b) {
                if (xs[a] != xs[b]) return xs[a] > xs[b];
                return ys[a] < ys[b];
            });
            FenwickMax fw(m);
            for (int idx : order) {
                int rt = (m - 1 - rank[idx]) + 1; // transformed, 1-indexed
                int best = fw.query(rt - 1);
                lenStart[idx] = best + 1;
                fw.update(rt, lenStart[idx]);
            }
        }

        return lenEnd[k] + lenStart[k] - 1;
    }
};
