// Link: https://leetcode.com/problems/construct-string-from-binary-tree/description/

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

// TC: O(n) SC: O(n)
// Approach: recursive preorder; wrap left in parens always if there's any right or left subtree, wrap right in parens only if it exists.
class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string s = to_string(root->val);
        if (root->left || root->right) {
            s += "(" + tree2str(root->left) + ")";
        }
        if (root->right) {
            s += "(" + tree2str(root->right) + ")";
        }
        return s;
    }
};
