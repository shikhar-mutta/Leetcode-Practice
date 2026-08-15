// Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

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
    int moves = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        moves += abs(l) + abs(r);
        return node->val - 1 + l + r;
    }
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};
