// Link: https://leetcode.com/problems/delete-node-in-a-bst/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(h)  SC: O(h)
// Approach: standard BST delete - find node, if it has 0/1 child replace
// directly, if 2 children replace value with in-order successor and delete
// the successor from the right subtree
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* succ = root->right;
            while (succ->left) succ = succ->left;
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};
