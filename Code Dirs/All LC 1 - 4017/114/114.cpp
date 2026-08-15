// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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

// TC: O(n)  SC: O(1) extra
// Approach: for each node, if it has a left subtree, find its rightmost node, attach the current right
// subtree there, then move left subtree to become the right subtree and clear left
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* rightmost = cur->left;
                while (rightmost->right) rightmost = rightmost->right;
                rightmost->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};
