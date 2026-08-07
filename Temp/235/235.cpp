// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

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
// Approach: BST property — walk down from root; if both p,q are smaller go left, both larger go right,
// otherwise the current node is the split point (the LCA)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while (node) {
            if (p->val < node->val && q->val < node->val) node = node->left;
            else if (p->val > node->val && q->val > node->val) node = node->right;
            else return node;
        }
        return nullptr;
    }
};
