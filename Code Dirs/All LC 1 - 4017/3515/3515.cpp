// Link: https://leetcode.com/problems/shortest-path-in-a-weighted-tree/description/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g3515[100001];
int p3515[100001][2], rngs3515[100001][2], tree3515[1 << 18], dist3515[100001];

class Solution {
public:
    int k = 1, MAX = 1;
    void update(int p, int l, int r, int ql, int qr, int v) {
        if (l == ql && r == qr) {
            tree3515[p] += v;
            return;
        }
        int m = (l + r) >> 1, pl = p << 1, pr = pl | 1;
        if (ql <= m)
            update(pl, l, m, ql, min(m, qr), v);
        if (qr > m)
            update(pr, m + 1, r, max(m + 1, ql), qr, v);
    }
    int query(int p) {
        int res = 0;
        while (p) {
            res += tree3515[p];
            p >>= 1;
        }
        return res;
    }
    int dfs(int s, int up = -1, int curr_d = 0) {
        dist3515[s] = curr_d;
        int x = -1, y;
        for (int i = 0, j; i < (int)g3515[s].size(); ++i) {
            j = g3515[s][i].first;
            if (j != up) {
                y = dfs(j, s, curr_d + g3515[s][i].second);
                if (x == -1) x = y;
                p3515[j][0] = s;
                p3515[j][1] = g3515[s][i].second;
            }
        }
        if (x == -1) x = k;
        rngs3515[s][0] = x;
        rngs3515[s][1] = k;
        ++k;
        return x;
    }
    vector<int> treeQueries(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        while (MAX < n) MAX <<= 1;
        memset(tree3515, 0, 4 * 2 * MAX);
        for (int i = 1; i <= n; ++i) {
            g3515[i].clear();
            p3515[i][0] = p3515[i][1] = 0;
            rngs3515[i][0] = rngs3515[i][1] = 0;
        }
        for (int i = 0; i < (int)edges.size(); ++i) {
            g3515[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            g3515[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
        }
        dfs(1);
        vector<int> ans;
        for (int i = 0; i < (int)queries.size(); ++i) {
            if (queries[i][0] == 1) {
                int u = queries[i][1], v = queries[i][2];
                if (p3515[u][0] != v) swap(u, v);
                update(1, 1, MAX, rngs3515[u][0], rngs3515[u][1],
                       queries[i][3] - p3515[u][1]);
                p3515[u][1] = queries[i][3];
            } else {
                ans.push_back(dist3515[queries[i][1]] +
                              query(MAX + rngs3515[queries[i][1]][1] - 1));
            }
        }
        return ans;
    }
};
