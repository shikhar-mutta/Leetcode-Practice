// Link: https://leetcode.com/problems/inorder-successor-in-bst/description/

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

// TC: O(h)  SC: O(1)
// Approach: BST walk - go right if p->val >= node->val, else record node as
// candidate successor and go left
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = nullptr;
        TreeNode* node = root;
        while (node) {
            if (p->val < node->val) {
                succ = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return succ;
    }
};
