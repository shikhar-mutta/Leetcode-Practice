// Link: https://leetcode.com/problems/trim-a-binary-search-tree/description/

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
    // TC: O(n) where n is the number of nodes in the tree, as we may need to visit all nodes in the worst case.
    // SC: O(h) where h is the height of the tree, which is the space used by the recursion stack. In the worst case, the height of the tree can be n (for a skewed tree), but for a balanced tree, it would be log(n).
    //    Approach:
    //    1. We perform a recursive traversal of the binary search tree (BST).
    //    2. For each node, we check if its value is less than the low boundary or greater than the high boundary.
    //    3. If the node's value is less than low, we discard the left subtree and recursively trim the right subtree.
    //    4. If the node's value is greater than high, we discard the right subtree and recursively trim the left subtree.
    //    5. If the node's value is within the range [low, high], we recursively trim both the left and right subtrees and return the current node as part of the trimmed tree.
    //    6. The function returns the root of the trimmed binary search tree, which contains only the nodes with values within the specified range.
    //    7. The recursion continues until all nodes have been processed, and the final result is the trimmed BST.
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return nullptr;
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
