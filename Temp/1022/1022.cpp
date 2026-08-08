// Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/

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

class Solution {
    int dfs(TreeNode* node, int cur) {
        if (!node) return 0;
        cur = cur * 2 + node->val;
        if (!node->left && !node->right) return cur;
        return dfs(node->left, cur) + dfs(node->right, cur);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
