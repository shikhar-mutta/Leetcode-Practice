// Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/

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

// TC: O(n) where n is the number of nodes in the tree
// SC: O(h) where h is the height of the tree
//  Approach:
//   1. We can use a depth-first search (DFS) approach to find the lowest common ancestor (LCA) of the deepest leaves in the binary tree.
//   2. We can define a helper function that returns a pair of values: the depth of the deepest leaf and the LCA of the deepest leaves.
//   3. We can recursively traverse the left and right subtrees of the current node and compare the depths of the deepest leaves in both subtrees.
//   4. If the depths are equal, we return the current node as the LCA.
//   5. If the depth of the left subtree is greater, we return the LCA from the left subtree, and if the depth of the right subtree is greater, we return the LCA from the right subtree.
//   6. Finally, we return the LCA of the deepest leaves from the root node.
class Solution
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        return dfs(root).second;
    }

private:
    pair<int, TreeNode *> dfs(TreeNode *node)
    {
        if (!node)
            return {0, nullptr};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        if (left.first == right.first)
            return {left.first + 1, node};
        return left.first > right.first
                   ? make_pair(left.first + 1, left.second)
                   : make_pair(right.first + 1, right.second);
    }
};
