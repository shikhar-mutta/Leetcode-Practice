// Link: https://leetcode.com/problems/all-paths-from-source-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n), where n is the number of nodes in the graph.
    // SC: O(n), for storing the current path in the recursion stack.
    // Approach:
    // 1. We perform a depth-first search (DFS) starting from the source node (node 0).
    // 2. We maintain a path vector to keep track of the current path from the source to the current node.
    // 3. If we reach the target node (node n-1), we add the current path to the answer vector.
    // 4. We backtrack by removing the last node from the path vector and continue exploring other paths
    // 5. Finally, we return the answer vector containing all paths from source to target.
    void dfs(int node, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans)
    {
        path.push_back(node);
        if (node == graph.size() - 1)
        {
            ans.push_back(path);
        }
        else
        {
            for (auto it : graph[node])
            {
                dfs(it, graph, path, ans);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph, path, ans);

        return ans;
    }
};