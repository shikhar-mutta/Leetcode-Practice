// Link: https://leetcode.com/problems/count-the-number-of-good-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: DFS the tree computing subtree sizes bottom-up. A node is
// "good" if all of its children's subtrees have equal size; count such
// nodes while returning each subtree's total size to its parent.
class Solution {
public:
    int ans = 0;
    vector<vector<int>> graph;

    int dfs(int node, int parent) {
        int subtreeSize = 1;
        int firstChildSize = -1;
        bool good = true;

        for (int child : graph[node]) {
            if (child == parent)
                continue;

            int childSize = dfs(child, node);

            if (firstChildSize == -1) {
                firstChildSize = childSize;
            } else if (firstChildSize != childSize) {
                good = false;
            }

            subtreeSize += childSize;
        }

        if (good) {
            ans++;
        }

        return subtreeSize;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        graph.resize(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);
        return ans;
    }
};
