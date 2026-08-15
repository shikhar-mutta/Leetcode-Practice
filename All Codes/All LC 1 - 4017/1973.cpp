// Link: https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/description/

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
public:
    int count = 0;

    long long dfs(TreeNode* node) {
        if (!node) return 0;
        long long leftSum = dfs(node->left);
        long long rightSum = dfs(node->right);
        if (leftSum + rightSum == node->val) count++;
        return leftSum + rightSum + node->val;
    }

    int equalToDescendants(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};
