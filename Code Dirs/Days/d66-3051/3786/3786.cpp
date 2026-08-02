// Link: https://leetcode.com/problems/total-sum-of-interaction-cost-in-tree-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: We can use depth-first search (DFS) to traverse the tree and calculate the interaction costs. We can maintain a count of the number of nodes in each group and use this information to calculate the interaction costs. For each node, we can calculate the interaction cost with its parent and its children. We can also maintain a count of the number of nodes in each group and use this information to calculate the interaction costs. We can return the total interaction cost after traversing the entire tree.
int idx[100001], nbs[200000], cnts[20], tcnts[20];
vector<int> groups;

long long dfs(int n, int p)
{
    long long res = 0;
    int f = 0, cnt[20];
    memcpy(cnt, cnts, sizeof cnt);
    for (int i = idx[n], j = idx[n + 1]; i != j; ++i)
        if (int nb = nbs[i]; nb != p)
        {
            res += dfs(nb, n);
        }
    ++cnts[groups[n] - 1];
    for (int k = 0; k < 20; ++k)
        if (int c = cnts[k] - cnt[k])
        {
            res += (long long)c * (tcnts[k] - c);
        }
    return res;
}

class Solution
{
public:
    long long interactionCosts(int n, vector<vector<int>> &edges,
                               vector<int> &group)
    {
        fill(idx, idx + n, 0);
        for (const auto &e : edges)
            ++idx[e[0]], ++idx[e[1]];
        for (int i = 1; i < n; ++i)
            idx[i] += idx[i - 1];
        idx[n] = idx[n - 1];
        for (const auto &e : edges)
        {
            nbs[--idx[e[0]]] = e[1];
            nbs[--idx[e[1]]] = e[0];
        }

        fill(tcnts, tcnts + 20, 0);
        for (int g : group)
            ++tcnts[g - 1];

        groups = std::move(group);
        return dfs(0, -1);
    }
};
