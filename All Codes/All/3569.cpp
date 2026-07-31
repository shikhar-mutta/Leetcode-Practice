// Link: https://leetcode.com/problems/maximize-count-of-distinct-primes-after-split/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + qlogn)
// SC: O(n)
// Approach: Lazy Segment Tree
//  1. We can use a lazy segment tree to keep track of the number of distinct primes in the array.
//  2. We can use a set to keep track of the indices of each prime number.
//  3. For each query, we can remove the old value and insert the new value in the set and update the segment tree accordingly.
//  4. The answer for each query is the maximum value in the segment tree.
template <
    class T, class Z = T, T default_value = T(), Z default_lazy_value = Z(),
    auto merge_node = plus<>(), auto combine_lazy = plus<>(),
    auto apply_lazy = [](T node, Z lazy, int len)
    { return node + len * lazy; }>
struct LazySegmentTree
{
    int n, h;
    vector<T> tree;
    vector<Z> lazy;

    LazySegmentTree(int size)
    {
        n = (size == 1) ? 1
                        : (1 << (8 * sizeof(int) - __builtin_clz(size - 1)));
        h = sizeof(int) * 8 - 1 - __builtin_clz(n);
        tree.resize(2 * n, default_value);
        lazy.resize(n, default_lazy_value);
    }

    int segment(int p) { return n >> (sizeof(int) * 8 - 1 - __builtin_clz(p)); }

    void apply(int p, Z value)
    {
        tree[p] = apply_lazy(tree[p], value, segment(p));
        if (p < n)
            lazy[p] = combine_lazy(lazy[p], value);
    }

    void build(int p)
    {
        while (p > 1)
        {
            p >>= 1;
            tree[p] = apply_lazy(merge_node(tree[p << 1], tree[p << 1 | 1]),
                                 lazy[p], segment(p));
        }
    }

    void push(int p)
    {
        for (int s = h; s > 0; s--)
        {
            int i = p >> s;
            if (lazy[i] != default_lazy_value)
            {
                apply(i << 1, lazy[i]);
                apply(i << 1 | 1, lazy[i]);
                lazy[i] = default_lazy_value;
            }
        }
    }

    void update(int l, int r, Z value)
    {
        l += n, r += n + 1;
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                apply(l++, value);
            if (r & 1)
                apply(--r, value);
        }
        build(l0);
        build(r0 - 1);
    }

    T query(int l, int r)
    {
        l += n, r += n + 1;
        push(l);
        push(r - 1);
        T resLeft = default_value, resRight = default_value;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resLeft = merge_node(resLeft, tree[l++]);
            if (r & 1)
                resRight = merge_node(tree[--r], resRight);
        }
        return merge_node(resLeft, resRight);
    }
};

constexpr int MAXN = 1e5 + 1;
bool prime[MAXN + 1]{};
auto init = []()
{
    fill(prime + 2, prime + size(prime), true);
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i] || i > 316)
            continue;
        for (int j = i * i; j <= MAXN; j += i)
        {
            prime[j] = false;
        }
    }

    return 0;
}();

int merge_node(int a, int b) { return max(a, b); }
int combine_lazy(int a, int b) { return a + b; }
int apply_lazy(int node, int lazy, int len) { return node + lazy; }

class Solution
{
public:
    vector<int> maximumCount(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        unordered_map<int, set<int>> occ;
        LazySegmentTree<int, int, 0, 0, merge_node, combine_lazy, apply_lazy>
            segtree(n);

        auto remove = [&](int val, int idx)
        {
            if (!prime[val])
                return;
            set<int> &indices = occ[val];
            int sz = indices.size();
            if (sz == 1)
            {
                segtree.update(1, n - 1, -1);
            }
            else if (idx == *indices.begin())
            { // very front
                segtree.update(idx + 1, *next(indices.begin()), -1);
            }
            else if (idx == *indices.rbegin())
            { // very back
                segtree.update(*next(indices.rbegin()) + 1, idx, -1);
            }
            indices.erase(idx);
        };

        auto insert = [&](int val, int idx)
        {
            if (!prime[val])
                return;
            set<int> &indices = occ[val];
            int sz = indices.size();
            if (sz == 0)
            {
                segtree.update(1, n - 1, +1);
            }
            else if (idx < *indices.begin())
            { // very front
                segtree.update(idx + 1, *indices.begin(), +1);
            }
            else if (idx > *indices.rbegin())
            { // very back
                segtree.update(*indices.rbegin() + 1, idx, +1);
            }
            indices.insert(idx);
        };

        for (int i = 0; i < n; i++)
            insert(nums[i], i);
        vector<int> res(queries.size());
        for (int i = 0, sz = queries.size(); i < sz; i++)
        {
            auto &q = queries[i];
            int idx = q[0], newVal = q[1];
            if (nums[idx] != newVal)
            {
                remove(nums[idx], idx);
                nums[idx] = newVal;
                insert(nums[idx], idx);
            }

            res[i] = segtree.query(1, n - 1);
        }
        return res;
    }
};