// Link: https://leetcode.com/problems/split-bst/description/

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

// TC: O(h) SC: O(h)
// Approach: recursively split; if root->val <= target, root and its left subtree stay <= target, but root's right subtree must be split further; if root->val > target, symmetric case on the left subtree.
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (!root) return {nullptr, nullptr};
        if (root->val <= target) {
            auto parts = splitBST(root->right, target);
            root->right = parts[0];
            return {root, parts[1]};
        } else {
            auto parts = splitBST(root->left, target);
            root->left = parts[1];
            return {parts[0], root};
        }
    }
};
