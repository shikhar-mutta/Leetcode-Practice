// Link: https://leetcode.com/problems/complete-binary-tree-inserter/description/

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

class CBTInserter {
    TreeNode* root_;
    deque<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) {
        root_ = root;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            TreeNode* node = bfs.front(); bfs.pop();
            if (node->left) bfs.push(node->left);
            if (node->right) bfs.push(node->right);
            if (!node->left || !node->right) q.push_back(node);
        }
    }

    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode* parent = q.front();
        if (!parent->left) parent->left = node;
        else {
            parent->right = node;
            q.pop_front();
        }
        q.push_back(node);
        return parent->val;
    }

    TreeNode* get_root() {
        return root_;
    }
};
