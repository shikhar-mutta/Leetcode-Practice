// Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/

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

class Solution
{
public:
    // TC: O(n) where n is the number of nodes in the tree. We visit each node once.
    // SC: O(h) where h is the height of the tree. This space is used by the recursion stack.
    // Approach:
    //  1. We perform a post-order traversal of the tree using the helper function.
    //  2. For each node, we calculate the depth of its left and right subtrees.
    //  3. If the depths are equal, it means the current node is the lowest common ancestor of the deepest nodes, so we return the current node and its depth.
    //  4. If the left depth is greater, we return the left child and its depth. If the right depth is greater, we return the right child and its depth.
    //  5. The main function subtreeWithAllDeepest calls the helper function and returns the node that is the smallest subtree containing all the deepest nodes.
    pair<TreeNode *, int> helper(TreeNode *root)
    {
        if (!root)
            return {nullptr, 0};
        auto [leftNode, leftDepth] = helper(root->left);
        auto [rightNode, rightDepth] = helper(root->right);
        if (leftDepth == rightDepth)
            return {root, leftDepth + 1};
        if (leftDepth > rightDepth)
            return {leftNode, leftDepth + 1};
        return {rightNode, rightDepth + 1};
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return helper(root).first;
    }
};
