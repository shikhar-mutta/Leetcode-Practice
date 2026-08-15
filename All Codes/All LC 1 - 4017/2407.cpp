// Link: https://leetcode.com/problems/longest-increasing-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<int> tree;

    void update(int node, int lo, int hi, int pos, int val) {
        if (lo == hi) { tree[node] = max(tree[node], val); return; }
        int mid = (lo + hi) / 2;
        if (pos <= mid) update(2*node, lo, mid, pos, val);
        else update(2*node+1, mid+1, hi, pos, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int lo, int hi, int l, int r) {
        if (r < lo || hi < l || l > r) return 0;
        if (l <= lo && hi <= r) return tree[node];
        int mid = (lo + hi) / 2;
        return max(query(2*node, lo, mid, l, r), query(2*node+1, mid+1, hi, l, r));
    }

public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        n = maxVal;
        tree.assign(4 * (n + 1), 0);

        int best = 0;
        for (int x : nums) {
            int lo = max(1, x - k), hi = x - 1;
            int prevBest = (hi >= lo) ? query(1, 1, n, lo, hi) : 0;
            int cur = prevBest + 1;
            update(1, 1, n, x, cur);
            best = max(best, cur);
        }
        return best;
    }
};
