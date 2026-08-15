// Link: https://leetcode.com/problems/recover-binary-search-tree/description/

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

// TC: O(n)  SC: O(n) (recursion, no extra structure)
// Approach: inorder traversal tracking previous node; find the two positions where order breaks, swap their values
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            if (prev && prev->val > node->val) {
                if (!first) first = prev;
                second = node;
            }
            prev = node;
            dfs(node->right);
        };
        dfs(root);
        swap(first->val, second->val);
    }
};
