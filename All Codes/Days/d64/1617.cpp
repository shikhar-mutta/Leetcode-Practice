// Link: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) SC: O(n^3)
// Approach: We can use a depth-first search (DFS) approach to traverse the tree and count the number of subtrees with a maximum distance between cities. We maintain a 3D DP array where dp[nod][depth][len] represents the number of subtrees rooted at 'nod' with a maximum depth of 'depth' and a maximum length of 'len'. We merge the results from child nodes to compute the results for the parent node. Finally, we accumulate the counts for each possible length to get the final result.
const int nmax = 100;
vector<int> G[nmax + 5];
int dp[nmax + 5][nmax + 5][nmax + 5];
int aux[nmax + 5][nmax + 5];

int w[nmax + 5];

vector<int> rez;

class Solution
{
public:
    void Merge(int nod, int son)
    {
        for (int depth = 0; depth < w[nod]; depth++)
        {
            for (int len = 0; len < w[nod]; len++)
            {
                aux[depth][len] = dp[nod][depth][len];
            }
        }
        for (int depth_nod = 0; depth_nod < w[nod]; depth_nod++)
        {
            for (int depth_son = 0; depth_son < w[son]; depth_son++)
            {
                for (int len_nod = 0; len_nod < w[nod]; len_nod++)
                {
                    for (int len_son = 0; len_son < w[son]; len_son++)
                    {
                        int cur_depth = max(depth_nod, depth_son + 1);
                        int cur_len = max(max(len_nod, len_son),
                                          depth_nod + depth_son + 1);
                        aux[cur_depth][cur_len] += dp[nod][depth_nod][len_nod] *
                                                   dp[son][depth_son][len_son];
                    }
                }
            }
        }
        w[nod] += w[son];
        for (int depth = 0; depth < w[nod]; depth++)
        {
            for (int len = 0; len < w[nod]; len++)
            {
                dp[nod][depth][len] = aux[depth][len];
                aux[depth][len] = 0;
            }
        }
    }
    void dfs(int nod, int dad = 0)
    {
        w[nod] = 1;
        for (auto it : G[nod])
        {
            if (it == dad)
            {
                continue;
            }
            dfs(it, nod);
        }
        dp[nod][0][0] = 1;
        for (auto it : G[nod])
        {
            if (it == dad)
            {
                continue;
            }
            Merge(nod, it);
        }
        for (int depth = 0; depth < w[nod]; depth++)
        {
            for (int len = 1; len < w[nod]; len++)
            {
                rez[len - 1] += dp[nod][depth][len];
            }
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n,
                                              vector<vector<int>> &edges)
    {
        rez.clear();
        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
            w[i] = 0;
            for (int depth = 0; depth <= n; depth++)
            {
                for (int len = 0; len <= n; len++)
                {
                    dp[i][depth][len] = 0;
                    aux[depth][len] = 0;
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            G[x].push_back(y);
            G[y].push_back(x);
        }
        rez.resize(n - 1);
        dfs(1);
        return rez;
    }
};