// Link: https://leetcode.com/problems/delete-node-in-a-bst/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else
            {
                TreeNode *temp = root->right;
                while (temp && temp->left)
                    temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};
