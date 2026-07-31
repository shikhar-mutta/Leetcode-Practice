// Link: https://leetcode.com/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q * 26), SC: O(n * 26)
// Approach: We can use a depth-first search (DFS) to traverse the tree and keep track of the number of times each character appears in the path from the root to the current node. We can also keep track of the depth of each node and the parent of each node. Then, for each query, we can find the lowest common ancestor (LCA) of the two nodes in the query and calculate the number of times each character appears in the path from the root to both nodes, subtracting the counts from the LCA. The answer for each query will be the total number of characters in both paths minus the maximum count of any character in both paths.
const int MAXN = 20000;
const int LIMIT = 16;
int head[MAXN];
int next_[MAXN * 2];
int to[MAXN * 2];
int val[MAXN * 2];
int cnt = 0;
int st[MAXN][LIMIT];
int deep[MAXN];
int times[MAXN][27];
int power;

int log_(int num)
{
    int ans = 0;
    while ((1 << ans) <= (num >> 1))
    {
        ans++;
    }
    return ans;
}

void build(int a, int b, int c)
{
    next_[cnt] = head[a];
    head[a] = cnt;
    to[cnt] = b;
    val[cnt++] = c;
}

void dfs(int cur, int fa, int v)
{
    deep[cur] = deep[fa] + 1;
    st[cur][0] = fa;
    for (int i = 1; i <= 26; i++)
    {
        times[cur][i] = times[fa][i];
    }
    times[cur][v] += 1;
    for (int p = 1; (1 << p) <= deep[cur]; p++)
    {
        st[cur][p] = st[st[cur][p - 1]][p - 1];
    }

    for (int e = head[cur]; e != -1; e = next_[e])
    {
        if (to[e] != fa)
        {
            dfs(to[e], cur, val[e]);
        }
    }
}

int lca(int a, int b)
{
    if (deep[a] < deep[b])
    {
        int t = a;
        a = b;
        b = t;
    }
    for (int p = power; p >= 0; p--)
    {
        if ((1 << p) <= deep[a] && deep[st[a][p]] >= deep[b])
        {
            a = st[a][p];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int p = power; p >= 0; p--)
    {
        if ((1 << p) <= deep[a] && st[a][p] != st[b][p])
        {
            a = st[a][p];
            b = st[b][p];
        }
    }
    return st[a][0];
}

class Solution
{
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>> &edges,
                                     vector<vector<int>> &queries)
    {
        cnt = 0;
        power = log_(n);
        deep[n] = 0;
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            head[i] = -1;
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= 26; j++)
            {
                times[i][j] = 0;
            }
        }
        for (vector<int> &v : edges)
        {
            build(v[0], v[1], v[2]);
            build(v[1], v[0], v[2]);
        }
        dfs(0, n, 0);
        for (vector<int> &v : queries)
        {
            int point = lca(v[0], v[1]);
            int max_ = 0;
            int all = 0;
            for (int i = 1; i <= 26; i++)
            {
                max_ = max(max_, times[v[0]][i] + times[v[1]][i] -
                                     2 * times[point][i]);
                all += times[v[0]][i] + times[v[1]][i] - 2 * times[point][i];
            }
            ans.push_back(all - max_);
        }
        return ans;
    }
};
