// Link: https://leetcode.com/problems/delete-node-in-a-bst/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // TC: O(h). SC: O(h) for recursion stack.
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            // Found the node to delete.
            if (!root->left)
                return root->right; // 0 or 1 child
            if (!root->right)
                return root->left;
            // Two children: replace value with inorder successor (min of right),
            // then delete that successor from the right subtree.
            TreeNode *succ = root->right;
            while (succ->left)
                succ = succ->left;
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};
