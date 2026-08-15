// Link: https://leetcode.com/problems/clone-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    // TC: O(V + E) where V is the number of vertices and E is the number of edges in the graph. We visit each node and edge once during the DFS traversal.
    // SC: O(V) for the cloneMap and the recursion stack. The cloneMap stores a mapping from original nodes to their clones, and the recursion stack can go as deep as the number of vertices in the worst case.
    // Approach:
    //  1. We use a depth-first search (DFS) approach to traverse the graph and create a clone of each node.
    //  2. We maintain a hash map (cloneMap) to keep track of the mapping between original nodes and their corresponding cloned nodes.
    //  3. We define a recursive DFS function that takes a node as input and returns its clone.
    //  4. If the node has already been cloned (i.e., it exists in the cloneMap), we return the cloned node.
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        unordered_map<Node *, Node *> cloneMap;
        function<Node *(Node *)> dfs = [&](Node *cur) -> Node *
        {
            auto it = cloneMap.find(cur);
            if (it != cloneMap.end())
                return it->second;
            Node *clone = new Node(cur->val);
            cloneMap[cur] = clone;
            for (auto nb : cur->neighbors)
                clone->neighbors.push_back(dfs(nb));
            return clone;
        };
        return dfs(node);
    }
};
