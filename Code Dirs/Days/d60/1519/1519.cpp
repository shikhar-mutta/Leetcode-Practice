// Link: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string label_;

public:
    // TC: O(n), SC: O(n)
    //  Approach:
    //  1. Build a graph representation of the tree using adjacency lists.
    //  2. Perform a depth-first search (DFS) traversal of the tree starting from the root node (node 0).
    //  3. For each node, maintain a count of occurrences of each label in its subtree using a vector of size 26 (for lowercase English letters).
    //  4. When visiting a node, record the current count of its label before exploring its children.
    //  5. After visiting all children, update the count of the current node's label and calculate the number of nodes in its subtree with the same label by subtracting the previous count from the updated count.
    //  6. Store the result for each node in a result vector and return it after the DFS traversal is complete.
    vector<int> countSubTrees(int n, vector<vector<int>> &edges,
                              string labels)
    {
        vector<vector<int>> graph(n, vector<int>{});
        label_ = labels;
        std::vector<bool> vis(n, false);
        vis[0] = true;
        for (auto &edge : edges)
        {
            if (vis[edge[0]])
                graph[edge[0]].push_back(edge[1]);
            else
                graph[edge[1]].push_back(edge[0]);
            vis[edge[0]] = true;
            vis[edge[1]] = true;
        }
        vector<int> res(n, 0);
        vector<int> add(26, 0);
        dfs(graph, res, add, 0);
        return res;
    }

    void dfs(const auto &graph, vector<int> &res, vector<int> &add, int root)
    {
        if (graph[root].size() == 0)
        {
            add[label_[root] - 'a'] += 1;
            res[root] = 1;
            return;
        }
        int prev = add[label_[root] - 'a'];
        for (auto &ch : graph[root])
        {
            dfs(graph, res, add, ch);
        }
        add[label_[root] - 'a']++;
        res[root] = add[label_[root] - 'a'] - prev;
    }
};