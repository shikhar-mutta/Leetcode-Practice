// Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

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
    string best;
    void dfs(TreeNode* node, string path) {
        if (!node) return;
        path = string(1, 'a' + node->val) + path;
        if (!node->left && !node->right) {
            if (best.empty() || path < best) best = path;
            return;
        }
        dfs(node->left, path);
        dfs(node->right, path);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return best;
    }
};
