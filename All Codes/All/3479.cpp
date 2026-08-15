// Link: https://leetcode.com/problems/fruits-into-baskets-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> seg;

    void build(int node, int l, int r, vector<int>& baskets) {
        if (l == r) { seg[node] = baskets[l]; return; }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, baskets);
        build(2 * node + 1, mid + 1, r, baskets);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    // find leftmost index in [l,r] with value >= x; -1 if none
    int query(int node, int l, int r, int x) {
        if (seg[node] < x) return -1;
        if (l == r) { seg[node] = -1; return l; }
        int mid = (l + r) / 2;
        int res = query(2 * node, l, mid, x);
        if (res == -1) res = query(2 * node + 1, mid + 1, r, x);
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
        return res;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = baskets.size();
        seg.assign(4 * n, 0);
        build(1, 0, n - 1, baskets);

        int unplaced = 0;
        for (int f : fruits) {
            int idx = query(1, 0, n - 1, f);
            if (idx == -1) unplaced++;
        }
        return unplaced;
    }
};
