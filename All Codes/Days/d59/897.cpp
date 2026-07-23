// Link: https://leetcode.com/problems/increasing-order-search-tree/description/

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
    // TC: O(n), where n is the number of nodes in the binary search tree.
    // SC: O(n), where n is the number of nodes in the binary search tree
    //  Approach:
    //      1. We perform an inorder traversal of the binary search tree to obtain the values of the nodes in sorted order. We store these values in a vector.
    //      2. We then create a new binary search tree with the same values, but with all nodes having only right children. We do this by iterating through the vector of values and creating a new TreeNode for each value, linking them together as right children.
    //      3. Finally, we return the root of the new binary search tree, which is the right child of a dummy node that we created to simplify the construction of the new tree.
    void inorder(TreeNode *node, vector<int> &vals)
    {
        if (!node)
            return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> vals;
        inorder(root, vals);
        TreeNode dummy(0);
        TreeNode *cur = &dummy;
        for (int v : vals)
        {
            cur->right = new TreeNode(v);
            cur = cur->right;
        }
        return dummy.right;
    }
};
