// Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

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

    void dfs(TreeNode* node, int maxSoFar) {
        if (!node) return;
        if (node->val >= maxSoFar) {
            count++;
            maxSoFar = node->val;
        }
        dfs(node->left, maxSoFar);
        dfs(node->right, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }
};
