// Link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int count = 0;

    void dfs(TreeNode* node, int mask) {
        if (!node) return;
        mask ^= (1 << node->val);
        if (!node->left && !node->right) {
            if ((mask & (mask - 1)) == 0) count++;
            return;
        }
        dfs(node->left, mask);
        dfs(node->right, mask);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return count;
    }
};
