// Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sort) + (n + m)\alpha(n): Sort(nums) + CountSort(queries) + dsu
// SC: O(n + m): nums + queries + dsu
//  Approach: Sort the nums and build a tree of connected components. Then, for each query, check if the two nodes are in the same component and if the path between them is valid.
//  The tree is built by connecting each node to the next node that is within the maxDiff. The depth of each node is calculated to determine the number of edges between two nodes in the same component. The queries are processed in a way that allows for efficient union-find operations to determine the path existence.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fornr(i, n) for (int i = n - 1; i >= 0; --i)
#define for1n(i, n) for (int i = 1; i < n; ++i)

#define N 100000
#define M 100000
alignas(16) array<int, 2> vals[N];
alignas(16) int iperm[N], parent[N], depth[N], dsu[N], label[N], cnt[N], id[N];
alignas(16) int qs[M][3], qperm[M]; // queries

void sort_values(int *v, int n)
{
    forn(i, n) vals[i][0] = v[i], vals[i][1] = i;
    sort(vals, vals + n, [](auto &i, auto &j)
         { return i[0] < j[0]; });
    forn(i, n) iperm[vals[i][1]] = i;
}

void calc_qperm(int n, int m)
{
    fill_n(cnt, m, 0);
    forn(i, n)++ cnt[qs[i][2]];
    for (int i = 0, p = 0; i < m; ++i)
        swap(p, cnt[i]), p += cnt[i];
    forn(i, n) qperm[cnt[qs[i][2]]++] = i;
}

void init_dsu(int n) { fill_n(dsu, n, -1), iota(label, label + n, 0); }
int find(int v) { return dsu[v] < 0 ? v : dsu[v] = find(dsu[v]); }
void join(int v, int u, int lbl)
{
    if ((v = find(v)) == (u = find(u)))
        return;
    if (dsu[v] < dsu[u])
        swap(u, v);
    label[u] = lbl, dsu[u] += dsu[v], dsu[v] = u;
}

// O(sort) + (n + m)\alpha(n): Sort(nums) + CountSort(queries) + dsu
class Solution
{
public:
    vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        int m = queries.size();
        sort_values(nums.data(), n);

        for (int i = 0, j = 0, cid = 0; i < n; ++i)
        {
            while (j < n && vals[j][0] - vals[i][0] <= maxDiff)
                ++j;
            parent[i] = j - 1;                  // tree connection
            id[i] = cid, cid += parent[i] == i; // tree id
        }
        fornr(i, n) depth[i] = parent[i] == i ? 0 : depth[parent[i]] + 1; // tree depth

        vector<int> result(m);
        int k = 0; // rest queries
        forn(i, m)
        {
            int a = queries[i][0], b = queries[i][1];
            if (a == b)
            {
                result[i] = 0;
                continue;
            } // trivial case
            a = iperm[a], b = iperm[b];
            if (id[a] != id[b])
            {
                result[i] = -1;
                continue;
            } // different trees
            if (a > b)
                swap(a, b);
            if (parent[a] >= b)
            {
                result[i] = 1;
                continue;
            } // simple case #1
            qs[k][0] = i, qs[k][1] = a, qs[k++][2] = b;
        }
        calc_qperm(k, n);

        init_dsu(n);
        for (int i = 0, j = 0; j < k; ++i)
        {
            for (; j < k && qs[qperm[j]][2] == i; ++j)
            {
                int z = qperm[j], a = qs[z][1], q = qs[z][0];
                result[q] = depth[a] - depth[label[find(a)]];
            }
            join(i, parent[i], parent[i]);
        }

        return result;
    }
};
