// Link: https://leetcode.com/problems/recover-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

// TC: O(n), SC: O(h) where h is the height of the tree. In worst case, h = n.
class Solution
{
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    // In-order walk: the two swapped nodes are the spots where order breaks.
    void inorder(TreeNode *node)
    {
        if (!node)
            return;
        inorder(node->left);
        if (prev && prev->val > node->val)
        {
            if (!first)
                first = prev; // first dip: take the larger (prev)
            second = node;    // last dip: take the smaller (node)
        }
        prev = node;
        inorder(node->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        if (first && second)
            swap(first->val, second->val);
    }
};
