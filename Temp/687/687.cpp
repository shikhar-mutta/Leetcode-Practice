// Link: https://leetcode.com/problems/longest-univalue-path/description/

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

// TC: O(n) SC: O(h)
// Approach: post-order DFS returning the longest downward univalue arm from each node; update global best using left arm + right arm (if both match node's value) at each node.
class Solution {
    int best = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int leftArm = (node->left && node->left->val == node->val) ? left+1 : 0;
        int rightArm = (node->right && node->right->val == node->val) ? right+1 : 0;
        best = max(best, leftArm + rightArm);
        return max(leftArm, rightArm);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return best;
    }
};
