// Link: https://leetcode.com/problems/handling-sum-queries-after-update/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> ones;
    vector<bool> lazy;
    int n;

    void build(vector<int>& nums1, int node, int lo, int hi) {
        if (lo == hi) { ones[node] = nums1[lo]; return; }
        int mid = (lo + hi) / 2;
        build(nums1, 2*node, lo, mid);
        build(nums1, 2*node+1, mid+1, hi);
        ones[node] = ones[2*node] + ones[2*node+1];
    }

    void applyFlip(int node, int lo, int hi) {
        ones[node] = (hi - lo + 1) - ones[node];
        lazy[node] = !lazy[node];
    }

    void push(int node, int lo, int hi) {
        if (!lazy[node]) return;
        int mid = (lo + hi) / 2;
        applyFlip(2*node, lo, mid);
        applyFlip(2*node+1, mid+1, hi);
        lazy[node] = false;
    }

    void update(int node, int lo, int hi, int l, int r) {
        if (r < lo || hi < l) return;
        if (l <= lo && hi <= r) { applyFlip(node, lo, hi); return; }
        push(node, lo, hi);
        int mid = (lo + hi) / 2;
        update(2*node, lo, mid, l, r);
        update(2*node+1, mid+1, hi, l, r);
        ones[node] = ones[2*node] + ones[2*node+1];
    }

public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        n = nums1.size();
        ones.assign(4 * n, 0);
        lazy.assign(4 * n, false);
        build(nums1, 1, 0, n - 1);

        long long sum2 = 0;
        for (int x : nums2) sum2 += x;

        vector<long long> ans;
        for (auto &q : queries) {
            if (q[0] == 1) {
                update(1, 0, n - 1, q[1], q[2]);
            } else if (q[0] == 2) {
                sum2 += (long long)q[1] * ones[1];
            } else {
                ans.push_back(sum2);
            }
        }
        return ans;
    }
};
