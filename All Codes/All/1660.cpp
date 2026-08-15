// Link: https://leetcode.com/problems/correct-a-binary-tree/description/

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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> level;
            for (int i = 0; i < sz; i++) { level.push_back(q.front()); q.pop(); }
            for (int i = sz - 1; i >= 0; i--) {
                TreeNode* node = level[i];
                if (node->right && visited.count(node->right)) {
                    node->right = nullptr;
                    return root;
                }
                visited.insert(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};
