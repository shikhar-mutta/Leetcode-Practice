// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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

// TC: O(h) SC: O(1)
// Approach: standard BST search — go left/right based on comparison until found or nullptr.
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};
