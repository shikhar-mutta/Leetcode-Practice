// Link: https://leetcode.com/problems/even-odd-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                if (level % 2 == 0) {
                    if (node->val % 2 == 0) return false;
                    if (node->val <= prev) return false;
                } else {
                    if (node->val % 2 != 0) return false;
                    if (node->val >= prev) return false;
                }
                prev = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};
