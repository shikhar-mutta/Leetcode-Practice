// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// TC: O(n), SC: O(n)
// Approach:
//  1. Create a result vector to store the preorder traversal.
//  2. Create a helper function dfs that takes a node and the result vector as parameters
//  3. In the dfs function, check if the node is null. If it is, return.
//  4. If the node is not null, add its value to the result vector
//  5. Iterate through the children of the node and call dfs on each child.
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        dfs(root, result);
        return result;
    }

private:
    void dfs(Node *node, vector<int> &result)
    {
        if (!node)
            return;
        result.push_back(node->val);
        for (Node *child : node->children)
            dfs(child, result);
    }
};
