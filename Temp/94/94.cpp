// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
// Approach: recursive inorder — left, node, right
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            res.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
        return res;
    }
};
