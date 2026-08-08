// Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int best = 0;

    // returns {isBST, minVal, maxVal, sum}
    struct Info { bool isBST; long long minVal, maxVal, sum; };

    Info dfs(TreeNode* node) {
        if (!node) return {true, LLONG_MAX, LLONG_MIN, 0};
        Info left = dfs(node->left);
        Info right = dfs(node->right);
        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal) {
            long long sum = left.sum + right.sum + node->val;
            best = max(best, (int)sum);
            long long mn = (node->left ? left.minVal : (long long)node->val);
            long long mx = (node->right ? right.maxVal : (long long)node->val);
            return {true, mn, mx, sum};
        }
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return best;
    }
};
