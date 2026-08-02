// Link: https://leetcode.com/problems/time-taken-to-mark-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: marking node v (from any neighbor) costs w(v) = 1 if v is odd, else 2 — depends only on the node being entered, not direction.
//  So time to mark j starting from i = sum of w(x) over the path from i to j, excluding i. Root the tree at 0, compute down[u] (best downward weighted distance from u) via post-order DFS tracking top-2 child values for correct rerooting, then a second DFS computes up[u] (best distance going through u's parent). Answer[u] = max(down[u], up[u]).
const int N = 1e5 + 5;
vector<int> kraw[N];
pair<int, int> info[N][2];
class Solution
{
public:
    int cost(int v) { return (v & 1) ? 1 : 2; }
    void calc(int x, int par)
    {
        info[x][0] = info[x][1] = {0, -1};
        for (auto &v : kraw[x])
        {
            if (v == par)
                continue;
            calc(v, x);
            if (info[v][0].first + cost(v) > info[x][0].first)
            {
                info[x][0] = {info[v][0].first + cost(v), v};
            }
        }
        for (auto &v : kraw[x])
        {
            if (v == par)
                continue;
            if (info[v][0].first + cost(v) > info[x][1].first &&
                v != info[x][0].second)
            {
                info[x][1] = {info[v][0].first + cost(v), v};
            }
        }
    }
    void dfs(int x, int par, int prev, vector<int> &ans)
    {
        ans[x] = max(prev, info[x][0].first);
        for (auto &v : kraw[x])
        {
            if (v == par)
                continue;
            int next_prev = prev;
            if (v == info[x][0].second)
            {
                next_prev = max(prev, info[x][1].first);
            }
            else
            {
                next_prev = max(prev, info[x][0].first);
            }
            next_prev += cost(x);
            dfs(v, x, next_prev, ans);
        }
    }
    vector<int> timeTaken(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        for (int i = 0; i < n; ++i)
        {
            kraw[i].clear();
        }
        for (auto &v : edges)
        {
            kraw[v[0]].push_back(v[1]);
            kraw[v[1]].push_back(v[0]);
        }
        calc(0, -1);
        vector<int> ans(n, 0);
        dfs(0, -1, 0, ans);
        return ans;
    }
};
