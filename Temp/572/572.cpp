// Link: https://leetcode.com/problems/subtree-of-another-tree/description/

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

// TC: O(m*n)  SC: O(h)
// Approach: for each node in root, check if the subtree rooted there is
// identical to subRoot
class Solution {
    bool sameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;
        return sameTree(a->left, b->left) && sameTree(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return !subRoot;
        if (sameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
