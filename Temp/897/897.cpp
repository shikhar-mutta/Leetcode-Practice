// Link: https://leetcode.com/problems/increasing-order-search-tree/description/

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

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy;
        TreeNode* cur = &dummy;
        inorder(root, cur);
        return dummy.right;
    }

private:
    void inorder(TreeNode* node, TreeNode*& cur) {
        if (!node) return;
        inorder(node->left, cur);
        node->left = nullptr;
        cur->right = node;
        cur = node;
        inorder(node->right, cur);
    }
};
