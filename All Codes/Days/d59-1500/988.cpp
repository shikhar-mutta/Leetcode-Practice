// Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n) where n is the number of nodes in the tree.
// SC: O(h) where h is the height of the tree.
// Approach:
// 1. We will perform a depth-first search (DFS) traversal of the binary tree starting from the root node.
// 2. At each node, we will append the character corresponding to the node's value to a string representing the current path from the root to that node.
// 3. When we reach a leaf node (a node with no left or right children), we will reverse the current path string to get the string from the leaf to the root.
// 4. We will compare this reversed string with the current best string found so far. If the reversed string is lexicographically smaller, we will update the best string.
// 5. We will continue this process for all nodes in the tree, and at the end, we will return the best string found, which represents the smallest string starting from a leaf node to the root node.

class Solution
{
public:
    void dfs(TreeNode *node, string path, string &best)
    {
        if (!node)
            return;
        path += ('a' + node->val);
        if (!node->left && !node->right)
        {
            string rev(path.rbegin(), path.rend());
            if (best.empty() || rev < best)
                best = rev;
            return;
        }
        dfs(node->left, path, best);
        dfs(node->right, path, best);
    }

    string smallestFromLeaf(TreeNode *root)
    {
        string best;
        dfs(root, "", best);
        return best;
    }
};
