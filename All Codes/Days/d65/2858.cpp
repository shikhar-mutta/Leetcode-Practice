// Link: https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: build adjacency with a 0/1 cost per directed step (0 if traversing that direction
// matches the original edge, 1 if it needs a reversal). DFS from node 0 to get ans[0]. Then reroot: moving the root from u to neighbor v flips exactly one edge's relevance --- ans[v] = ans[u] - cost(u->v) + cost(v->u) = ans[u] + (cost(u->v)==0 ? 1 : -1).
class Solution
{
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
    {
        vector<int> offsets(n + 1, 0);
        for (auto &e : edges)
        {
            offsets[e[0]]++;
            offsets[e[1]]++;
        }
        for (int i = n; i > 0; i--)
            offsets[i] = offsets[i - 1];
        offsets[0] = 0;
        for (int i = 1; i < n + 1; i++)
            offsets[i] += offsets[i - 1];
        vector<int> offsetsCopy(offsets);
        vector<pair<int, bool>> edg(edges.size() * 2);
        for (auto &e : edges)
        {
            edg[offsetsCopy[e[0]]] = {e[1], true};
            edg[offsetsCopy[e[1]]] = {e[0], false};
            offsetsCopy[e[0]]++;
            offsetsCopy[e[1]]++;
        }
        // Node, neighbor
        stack<pair<int, int>> s;
        s.push({0, -1});
        int zeroFlips = 0;
        while (!s.empty())
        {
            auto [node, neighbor] = s.top();
            s.pop();
            for (auto i = &edg[offsets[node]]; i != &edg[offsets[node + 1]];
                 i++)
            {
                if (i->first == neighbor)
                    continue;
                if (!i->second)
                    zeroFlips++;
                s.push({i->first, node});
            }
        }
        // Node, neighbor
        s.push({0, -1});
        vector<int> ans(n, 0);
        ans[0] = zeroFlips;
        while (!s.empty())
        {
            auto [node, neighbor] = s.top();
            s.pop();
            for (auto i = &edg[offsets[node]]; i != &edg[offsets[node + 1]];
                 i++)
            {
                if (i->first == neighbor)
                    continue;
                if (!i->second)
                    ans[i->first] = ans[node] - 1;
                else
                    ans[i->first] = ans[node] + 1;
                s.push({i->first, node});
            }
        }
        return ans;
    }
};
