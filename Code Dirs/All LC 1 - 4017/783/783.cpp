// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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

// TC: O(n) SC: O(h)
// Approach: in-order traversal gives sorted values; track previous value and min gap to the current.
class Solution {
    int prev = INT_MIN;
    bool hasPrev = false;
    int best = INT_MAX;
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (hasPrev) best = min(best, node->val - prev);
        prev = node->val;
        hasPrev = true;
        inorder(node->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return best;
    }
};
