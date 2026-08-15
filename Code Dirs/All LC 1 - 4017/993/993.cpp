// Link: https://leetcode.com/problems/cousins-in-binary-tree/description/

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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,TreeNode*> px = find(root, x, 0, nullptr);
        pair<int,TreeNode*> py = find(root, y, 0, nullptr);
        return px.second && py.second && px.first == py.first && px.second != py.second;
    }

private:
    pair<int,TreeNode*> find(TreeNode* node, int target, int depth, TreeNode* parent) {
        if (!node) return {-1, nullptr};
        if (node->val == target) return {depth, parent};
        auto l = find(node->left, target, depth+1, node);
        if (l.second) return l;
        return find(node->right, target, depth+1, node);
    }
};
