// Link: https://leetcode.com/problems/good-subsequence-queries/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n+q) log n)  SC: O(n)
// Approach: a good subsequence has length < n and gcd == p; only elements
// divisible by p can appear in it (others act as identity/0 in a gcd
// segment tree, since gcd(x,0)=x). Apply queries as point updates, keeping
// a segment tree of "nums[i] if p|nums[i] else 0" (gcd combine) and a count
// of divisible-by-p positions. After each update, if the root gcd != p, no
// good subsequence; if count < n, using all divisible elements already
// gives length < n; if count == n (every element qualifies, so using all
// of them violates length<n), for n>6 a number-theoretic guarantee makes it
// always still achievable via removing one element, otherwise brute force
// checking each single removal via range gcd queries (n<=6 small).
class SegTree
{
    int n;
    vector<int> tree;
    int g(int a, int b) { return __gcd(a, b); }

public:
    SegTree(int n_) : n(n_), tree(4 * n_, 0) {}
    void update(int node, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * node, l, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, r, pos, val);
        tree[node] = g(tree[2 * node], tree[2 * node + 1]);
    }
    int query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql || ql > qr)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return g(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }
    void update(int pos, int val) { update(1, 0, n - 1, pos, val); }
    int query(int l, int r)
    {
        if (l > r)
            return 0;
        return query(1, 0, n - 1, l, r);
    }
    int root() { return tree[1]; }
};

class Solution
{
public:
    int countGoodSubseq(vector<int> &nums, int p, vector<vector<int>> &queries)
    {
        int n = nums.size();
        SegTree tree(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % p == 0)
            {
                tree.update(i, nums[i]);
                cnt++;
            }
        }
        int ans = 0;
        for (auto &q : queries)
        {
            int idx = q[0], val = q[1];
            if (nums[idx] % p == 0)
            {
                tree.update(idx, 0);
                cnt--;
            }
            if (val % p == 0)
            {
                tree.update(idx, val);
                cnt++;
            }
            nums[idx] = val;
            if (tree.root() != p)
                continue;
            if (cnt < n || n > 6)
            {
                ans++;
                continue;
            }
            bool found = false;
            for (int i = 0; i < n && !found; i++)
            {
                int leftG = tree.query(0, i - 1);
                int rightG = tree.query(i + 1, n - 1);
                if (__gcd(leftG, rightG) == p)
                    found = true;
            }
            if (found)
                ans++;
        }
        return ans;
    }
};
