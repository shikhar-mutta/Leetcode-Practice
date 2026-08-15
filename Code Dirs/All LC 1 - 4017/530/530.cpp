// Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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

// TC: O(n)  SC: O(h)
// Approach: inorder traversal gives sorted order; track previous value,
// min diff to current
class Solution {
    int best = INT_MAX;
    bool hasPrev = false;
    int prevVal = 0;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (hasPrev) best = min(best, node->val - prevVal);
        prevVal = node->val;
        hasPrev = true;
        inorder(node->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return best;
    }
};
