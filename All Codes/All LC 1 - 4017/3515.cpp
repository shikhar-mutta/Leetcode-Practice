// Link: https://leetcode.com/problems/shortest-path-in-a-weighted-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q * log(n)), where n is the number of nodes in the tree and q is the number of queries.
// SC: O(n), where n is the number of nodes in the tree.
// Approach: We can use a depth-first search (DFS) to calculate the distance of each node from the root and store it in an array. We will also maintain a segment tree to efficiently update the weights of the edges and query the distance of a node from the root. For each query, if it is an update query, we will update the weight of the edge in the segment tree. If it is a distance query, we will return the distance of the node from the root by querying the segment tree.
vector<pair<int, int>> g[100001];
int p[100001][2], rngs[100001][2], tree[1 << 18], dist[100001];

class Solution
{
public:
    int k = 1, MAX = 1;
    void update(int p, int l, int r, int ql, int qr, int v)
    {
        if (l == ql && r == qr)
        {
            tree[p] += v;
            return;
        }
        int m = (l + r) >> 1, pl = p << 1, pr = pl | 1;
        if (ql <= m)
            update(pl, l, m, ql, min(m, qr), v);
        if (qr > m)
            update(pr, m + 1, r, max(m + 1, ql), qr, v);
    }
    int query(int p)
    {
        int res = 0;
        while (p)
        {
            res += tree[p];
            p >>= 1;
        }
        return res;
    }
    int dfs(int s, int up = -1, int curr_d = 0)
    {
        dist[s] = curr_d;
        int x = -1, y;
        for (int i = 0, j; i < g[s].size(); ++i)
        {
            j = g[s][i].first;
            if (j != up)
            {
                y = dfs(j, s, curr_d + g[s][i].second);
                if (x == -1)
                    x = y;
                p[j][0] = s;
                p[j][1] = g[s][i].second;
            }
        }
        if (x == -1)
            x = k;
        rngs[s][0] = x;
        rngs[s][1] = k;
        ++k;
        return x;
    }
    vector<int> treeQueries(int n, vector<vector<int>> &edges,
                            vector<vector<int>> &queries)
    {
        while (MAX < n)
            MAX <<= 1;
        memset(tree, 0, 4 * 2 * MAX);
        for (int i = 1; i <= n; ++i)
        {
            g[i].clear();
            p[i][0] = p[i][1] = 0;
            rngs[i][0] = rngs[i][1] = 0;
        }
        for (int i = 0; i < edges.size(); ++i)
        {
            g[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            g[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
        }
        dfs(1);
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i)
        {
            if (queries[i][0] == 1)
            {
                int u = queries[i][1], v = queries[i][2];
                if (p[u][0] != v)
                    swap(u, v);
                update(1, 1, MAX, rngs[u][0], rngs[u][1],
                       queries[i][3] - p[u][1]);
                p[u][1] = queries[i][3];
            }
            else
            {
                ans.push_back(dist[queries[i][1]] +
                              query(MAX + rngs[queries[i][1]][1] - 1));
            }
        }
        return ans;
    }
};
