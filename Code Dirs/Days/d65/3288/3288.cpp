// Link: https://leetcode.com/problems/length-of-the-longest-increasing-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: forward[i] = longest strictly-increasing (both coords) path ending at i; backward[i]
// = longest such path starting at i. Both are LIS-style DPs over y-coordinate (after sorting by
// x), computed with a Fenwick tree doing prefix/suffix max queries over compressed y-ranks.
// Points sharing the same x must never chain to each other, so each x-group is processed as a
// batch: compute all its DP values first, then insert them into the tree together. Answer =
// forward[k] + backward[k] - 1.
class Solution {
public:
    vector<int> tree;
    int sz;

    void update(int i, int val) {
        for (i++; i <= sz; i += i & (-i)) tree[i] = max(tree[i], val);
    }
    int query(int i) { // max over [1..i], 1-indexed after +1 shift
        int r = 0;
        for (; i > 0; i -= i & (-i)) r = max(r, tree[i]);
        return r;
    }

    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        vector<int> ys;
        for (auto& c : coordinates) ys.push_back(c[1]);
        vector<int> sortedY = ys;
        sort(sortedY.begin(), sortedY.end());
        sortedY.erase(unique(sortedY.begin(), sortedY.end()), sortedY.end());
        sz = sortedY.size();
        auto rank = [&](int y) { return lower_bound(sortedY.begin(), sortedY.end(), y) - sortedY.begin(); };

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        // forward pass: sort by x asc, tie y desc; batch by x
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (coordinates[a][0] != coordinates[b][0]) return coordinates[a][0] < coordinates[b][0];
            return coordinates[a][1] > coordinates[b][1];
        });
        vector<int> forward(n, 1);
        tree.assign(sz+1, 0);
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && coordinates[idx[j]][0] == coordinates[idx[i]][0]) j++;
            for (int t = i; t < j; t++) {
                int r = rank(coordinates[idx[t]][1]);
                forward[idx[t]] = query(r) + 1; // strictly smaller y -> ranks [0, r-1] -> query(r) using 1-indexed shift covers [0,r-1]
            }
            for (int t = i; t < j; t++) {
                int r = rank(coordinates[idx[t]][1]);
                update(r, forward[idx[t]]);
            }
            i = j;
        }

        // backward pass: sort by x desc, tie y asc; batch by x
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (coordinates[a][0] != coordinates[b][0]) return coordinates[a][0] > coordinates[b][0];
            return coordinates[a][1] < coordinates[b][1];
        });
        vector<int> backward(n, 1);
        tree.assign(sz+1, 0);
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && coordinates[idx[j]][0] == coordinates[idx[i]][0]) j++;
            for (int t = i; t < j; t++) {
                int r = rank(coordinates[idx[t]][1]);
                int rr = sz - 1 - r; // reverse rank so "suffix max over y>current" becomes prefix query
                backward[idx[t]] = query(rr) + 1;
            }
            for (int t = i; t < j; t++) {
                int r = rank(coordinates[idx[t]][1]);
                int rr = sz - 1 - r;
                update(rr, backward[idx[t]]);
            }
            i = j;
        }

        return forward[k] + backward[k] - 1;
    }
};
