// Link: https://leetcode.com/problems/handling-sum-queries-after-update/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((N+Q) log N), SC: O(N)
// Approach: segment tree over nums1 supporting range-flip (lazy) and range count-of-ones.
// Type1 flips a range; type2 adds p * (current count of ones) to a running nums2 sum; type3
// answers the running sum directly.
class Solution {
public:
    vector<int> tree, lazy;
    int n;

    void build(vector<int>& nums1, int node, int l, int r) {
        if (l == r) { tree[node] = nums1[l]; return; }
        int mid = (l+r)/2;
        build(nums1, 2*node, l, mid);
        build(nums1, 2*node+1, mid+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void apply(int node, int l, int r) {
        tree[node] = (r - l + 1) - tree[node];
        lazy[node] ^= 1;
    }

    void push(int node, int l, int r) {
        if (!lazy[node]) return;
        int mid = (l+r)/2;
        apply(2*node, l, mid);
        apply(2*node+1, mid+1, r);
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { apply(node, l, r); return; }
        push(node, l, r);
        int mid = (l+r)/2;
        update(2*node, l, mid, ql, qr);
        update(2*node+1, mid+1, r, ql, qr);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        push(node, l, r);
        int mid = (l+r)/2;
        return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
    }

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        n = nums1.size();
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(nums1, 1, 0, n-1);

        long long sum = 0;
        for (int x : nums2) sum += x;

        vector<long long> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                update(1, 0, n-1, q[1], q[2]);
            } else if (q[0] == 2) {
                sum += (long long)q[1] * query(1, 0, n-1, 0, n-1);
            } else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
