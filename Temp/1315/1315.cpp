// Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* node, TreeNode* parent, TreeNode* grandparent) {
        if (!node) return;
        if (grandparent && grandparent->val % 2 == 0) sum += node->val;
        dfs(node->left, node, parent);
        dfs(node->right, node, parent);
    }

    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, nullptr, nullptr);
        return sum;
    }
};
