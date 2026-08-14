// Link: https://leetcode.com/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        long long dp[2][2] = {{0,0},{0,0}};
    };

    int n;
    vector<Node> seg;

    Node merge(const Node& L, const Node& R) {
        Node res;
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                long long best = LLONG_MIN;
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        if (x == 0 && y == 0) continue; // both boundary elements included & adjacent
                        best = max(best, L.dp[a][x] + R.dp[y][b]);
                    }
                }
                res.dp[a][b] = best;
            }
        }
        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            long long v = nums[l];
            seg[node].dp[0][0] = max(v, 0LL);
            seg[node].dp[0][1] = 0;
            seg[node].dp[1][0] = 0;
            seg[node].dp[1][1] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid, nums);
        build(2*node+1, mid+1, r, nums);
        seg[node] = merge(seg[2*node], seg[2*node+1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            seg[node].dp[0][0] = max((long long)val, 0LL);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*node, l, mid, pos, val);
        else update(2*node+1, mid+1, r, pos, val);
        seg[node] = merge(seg[2*node], seg[2*node+1]);
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        seg.assign(4 * n, Node());
        build(1, 0, n - 1, nums);

        const long long MOD = 1e9 + 7;
        long long total = 0;
        for (auto& q : queries) {
            int pos = q[0], x = q[1];
            update(1, 0, n - 1, pos, x);
            total = (total + seg[1].dp[0][0]) % MOD;
        }
        return (int)total;
    }
};
