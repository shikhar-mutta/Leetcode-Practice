// Link: https://leetcode.com/problems/delete-nodes-and-return-forest/description/

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
    unordered_set<int> toDelete;
    vector<TreeNode*> forest;

    TreeNode* dfs(TreeNode* node, bool isRoot) {
        if (!node) return nullptr;
        bool deleted = toDelete.count(node->val);
        if (isRoot && !deleted) forest.push_back(node);
        node->left = dfs(node->left, deleted);
        node->right = dfs(node->right, deleted);
        return deleted ? nullptr : node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        toDelete.insert(to_delete.begin(), to_delete.end());
        dfs(root, true);
        return forest;
    }
};
