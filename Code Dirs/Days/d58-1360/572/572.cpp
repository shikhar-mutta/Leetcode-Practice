// Link: https://leetcode.com/problems/subtree-of-another-tree/description/

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
    // TC: O(n * m), where n is the number of nodes in the main tree and m is the number of nodes in the subtree. In the worst case, we may need to compare each node of the main tree with each node of the subtree.
    // SC: O(h), where h is the height of the main tree.
    // Approach:
    //  1. We define a recursive function isSubtree that takes the root of the main tree and the root of the subtree as input.
    //  2. If the main tree is empty, we return true if the subtree is also empty, otherwise false.
    //  3. We check if the current node of the main tree is the same as the root of the subtree using the isSameTree function. If they are the same, we return true.
    //  4. If they are not the same, we recursively check the left and right subtrees of the main tree to see if the subtree exists in either of them.
    //  5. The isSameTree function checks if two trees are identical by comparing their values and recursively checking their left and right children.
    //  6. Finally, we return true if the subtree is found in the main tree, otherwise false.
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return !subRoot;
        if (isSameTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
            return true;
        if (!a || !b || a->val != b->val)
            return false;
        return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
};
