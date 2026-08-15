// Link: https://leetcode.com/problems/find-all-the-lonely-nodes/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void dfs(TreeNode* node, vector<int>& res) {
        if (!node) return;
        if (node->left && !node->right) res.push_back(node->left->val);
        if (node->right && !node->left) res.push_back(node->right->val);
        dfs(node->left, res);
        dfs(node->right, res);
    }

    vector<int> findLonelyNodes(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
