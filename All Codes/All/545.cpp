// Link: https://leetcode.com/problems/boundary-of-binary-tree/description/

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

// TC: O(n)  SC: O(n)
// Approach: collect left boundary (excluding leaves) top-down, all leaves
// left-to-right, right boundary (excluding leaves) bottom-up, concatenate
class Solution {
    bool isLeaf(TreeNode* n) { return !n->left && !n->right; }

    void leftBoundary(TreeNode* node, vector<int>& res) {
        if (!node || isLeaf(node)) return;
        res.push_back(node->val);
        if (node->left) leftBoundary(node->left, res);
        else leftBoundary(node->right, res);
    }

    void leaves(TreeNode* node, vector<int>& res) {
        if (!node) return;
        if (isLeaf(node)) { res.push_back(node->val); return; }
        leaves(node->left, res);
        leaves(node->right, res);
    }

    void rightBoundary(TreeNode* node, vector<int>& res) {
        if (!node || isLeaf(node)) return;
        if (node->right) rightBoundary(node->right, res);
        else rightBoundary(node->left, res);
        res.push_back(node->val);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);
        if (isLeaf(root)) return res;

        leftBoundary(root->left, res);
        leaves(root->left, res);
        leaves(root->right, res);
        rightBoundary(root->right, res);
        return res;
    }
};
