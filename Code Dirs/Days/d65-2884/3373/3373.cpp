// Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), SC: O(n + m)
//  Approach: We can use BFS to color the nodes of both trees. For each node in tree1, we can count the number of nodes in tree1 that have the same color as the node and add it to the maximum number of nodes in tree2 that have the same color as the node. We can return the maximum number of nodes for each node in tree1.
class Solution
{
public:
    vector<int> color;
    vector<vector<int>> adj;

    void bfs(int start, int n)
    {
        color.assign(n, -1);
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                               vector<vector<int>> &edges2)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build and color tree1
        adj.assign(n, {});
        for (auto &e : edges1)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        bfs(0, n);
        vector<int> color1 = color;

        int cnt1_0 = 0, cnt1_1 = 0;
        for (int c : color1)
        {
            if (c == 0)
                cnt1_0++;
            else
                cnt1_1++;
        }

        // Build and color tree2
        adj.assign(m, {});
        for (auto &e : edges2)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        bfs(0, m);
        vector<int> color2 = color;

        int cnt2_0 = 0, cnt2_1 = 0;
        for (int c : color2)
        {
            if (c == 0)
                cnt2_0++;
            else
                cnt2_1++;
        }

        int bestTree2 = max(cnt2_0, cnt2_1);

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int sameColorCount = (color1[i] == 0) ? cnt1_0 : cnt1_1;
            ans[i] = sameColorCount + bestTree2;
        }

        return ans;
    }
};
